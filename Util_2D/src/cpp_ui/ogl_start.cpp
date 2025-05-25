#include <QtWidgets/QOpenGLWidget>
#include <QtGraphics/QOpenGLFunctions>
#include <QtWidgets/QOpenGLShaderProgram>
#include <QtWidgets/QOpenGLBuffer>
#include <QtWidgets/QOpenGLTexture>
#include <QtWidgets/QImage>
#include <QtWidgets/QMatrix4x4>

class OpenGLWorkspace : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    OpenGLWorkspace(QWidget* parent = nullptr) : QOpenGLWidget(parent) {
        QSurfaceFormat format;
        format.setSamples(16); // Улучшенное сглаживание (опционально)
        this->setFormat(format);
    }

protected:
    void initializeGL() override {
        initializeOpenGLFunctions();

        // Шейдеры
        program = new QOpenGLShaderProgram(this);
        program->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
        program->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
        program->link();

        // VBO
        vertexBuf.create();
        vertexBuf.bind();
        vertexBuf.allocate(vertices, sizeof(vertices));

        // Texture
        texture = new QOpenGLTexture(QImage("path/to/your/image.png").mirrored());
        texture->setMinificationFilter(QOpenGLTexture::Nearest);
        texture->setMagnificationFilter(QOpenGLTexture::Linear);

        // VAO (Vertex Array Object)
        vao.create();
        QOpenGLVertexArrayObject::Binder vaoBinder(&vao);
        vertexBuf.bind();
        program->enableAttributeArray(0);
        program->setAttributeBuffer(0, GL_FLOAT, 0, 3, 0);
    }

    void paintGL() override {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        program->bind();
        texture->bind();

        QMatrix4x4 matrix;
        matrix.perspective(60.0f, 4.0f / 3.0f, 0.1f, 100.0f); // Пример проекции

        program->setUniformValue("matrix", matrix);
        program->setUniformValue("texture", 0); // Текстурный юнит

        vao.bind();
        glDrawArrays(GL_TRIANGLES, 0, 6);

        program->release();
    }

    void resizeGL(int w, int h) override {
        glViewport(0, 0, w, h);
    }

private:

    const char* vertexShaderSource =
        "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "uniform mat4 matrix;\n"
        "out vec2 TexCoord;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = matrix * vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "   TexCoord = vec2(aPos.x/2 + 0.5, aPos.y/2 + 0.5);\n"
        "}\n";
    const char* fragmentShaderSource =
        "#version 330 core\n"
        "out vec4 FragColor;\n"
        "in vec2 TexCoord;\n"
        "uniform sampler2D texture;\n"
        "void main()\n"
        "{\n"
        "   FragColor = texture(texture, TexCoord);\n"
        "}\n";

    QOpenGLShaderProgram* program = nullptr;
    QOpenGLBuffer vertexBuf;
    QOpenGLTexture* texture = nullptr;
    QOpenGLVertexArrayObject vao;

    GLfloat vertices[6 * 3] = {
        // positions
        -1.0f,  1.0f, 0.0f,
        -1.0f, -1.0f, 0.0f,
         1.0f, -1.0f, 0.0f,

        -1.0f,  1.0f, 0.0f,
         1.0f, -1.0f, 0.0f,
         1.0f,  1.0f, 0.0f
    };
};
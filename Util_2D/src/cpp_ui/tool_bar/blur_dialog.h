#pragma once
#include <QtWidgets/qdialog.h>
#include <QtWidgets/qformlayout.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qspinbox.h>
#include <QtWidgets/qcombobox.h>

static bool memorizeValues = false;

enum class BlurMode : int {
    BOX = 0,
    GAUSS = 1
};

class BlurDialog : public QDialog {
public:
    BlurDialog(QWidget* parent) : QDialog(parent) {
        radiusSpinBox = new QSpinBox;
        radiusSpinBox->setRange(1, 100);
        radiusSpinBox->setValue(lastRadius);

        modeComboBox = new QComboBox;
        modeComboBox->addItem("Box");
        modeComboBox->addItem("Gaussian");
        modeComboBox->setCurrentIndex(static_cast<int>(lastMode));

        QPushButton* okButton = new QPushButton("OK");
        QPushButton* cancelButton = new QPushButton("Cancel");

        QFormLayout* formLayout = new QFormLayout;
        formLayout->addRow("Radius:", radiusSpinBox);
        formLayout->addRow("Mode:", modeComboBox);

        QHBoxLayout* buttonLayout = new QHBoxLayout;
        buttonLayout->addWidget(okButton);
        buttonLayout->addWidget(cancelButton);

        QVBoxLayout* mainLayout = new QVBoxLayout;
        mainLayout->addLayout(formLayout);
        mainLayout->addLayout(buttonLayout);

        setLayout(mainLayout);
        setWindowTitle("Blur Parameters");

        connect(okButton, &QPushButton::clicked, this, &BlurDialog::accept);
        connect(cancelButton, &QPushButton::clicked, this, &BlurDialog::reject);
    }

    int radius() const {
        if (memorizeValues)
            lastRadius = radiusSpinBox->value();
        return radiusSpinBox->value();
    }
    BlurMode mode() const {
        BlurMode mode = BlurMode::BOX; // Box mode or eror.
        if (modeComboBox->currentText() == "Gaussian")
            mode = BlurMode::GAUSS;
        //
        if (memorizeValues)
            lastMode = mode;
        return mode;
    }

private:
    QSpinBox* radiusSpinBox;
    QComboBox* modeComboBox;
    //
    static int lastRadius;
    static BlurMode lastMode;
};

int BlurDialog::lastRadius = 1;
BlurMode BlurDialog::lastMode = BlurMode::BOX;

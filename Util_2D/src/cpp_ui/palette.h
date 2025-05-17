#pragma once
#include <QtWidgets/qwidget.h>
#include <QtWidgets/qlayout.h>



class Palette : public QWidget {
public:
	Palette(QWidget* parent) : QWidget(parent) {
		setMaximumSize(80, 80);
		grid = new QGridLayout(this);

		colors.insert(255);
		colors.insert(400);
		colors.insert(420);
		colors.insert(460);
		colors.insert(480);
		colors.insert(500);
		colors.insert(520);

		updateLayout();

	}

	void updateFromImage(const QImage& image) {
		colors.clear();
		for (int y = 0; y < image.height(); ++y) {
			for (int x = 0; x < image.width(); ++x) {
				colors.insert(image.pixel(x, y));
			}
		}
		updateLayout();
	}

private:
	void updateLayout() {
		QLayoutItem* item;
		while ((item = grid->takeAt(0)) != nullptr) {
			QWidget* widget = item->widget();
			if (widget != nullptr)
				widget->deleteLater();
			delete item;
		}


		int row = 0;
		int col = 0;
		for (const QColor& color : colors) {
			QPushButton* button = new QPushButton;
			button->setFixedSize(20, 20);
			button->setStyleSheet(QString("background-color: %1; border: 1px solid black;").arg(color.name()));

			grid->addWidget(button, row, col);
			++col;
			if (col > 3) {
				col = 0;
				++row;
			}
		}
	}



private:
	QGridLayout* grid;
	QSet<QRgb> colors;

};
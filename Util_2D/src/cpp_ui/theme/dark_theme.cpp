#include "theme_presets.h"

const QString themePresets::dark{
	"QMainWindow { background-color: #303030; }"
/*---------------------------------------------*/
	"QMenuBar {"
	"    background-color: #1D1D1D;"
	"    color: white;"
	"    border: 2px solid #161616;"
	"    border-radius: 4px;"
	"}"
	"QMenuBar::item:selected {"
	"    background-color: #3A5986;"
	"    border: 1px solid #4772B3;"
	"    border-radius: 2px;"
	"}"
	"QMenu {"
	"    background-color: #141414;"
	"    color: white;"
	"    border: 1px solid #101010;"
	"}"
	"QMenu::item:selected {"
	"    background-color: #3A5986;"
	"    border: 2px solid #3A5986;"
	"    border-radius: 4px;"
	"}"
/*---------------------------------------------*/
	"QToolBar {"
	"    background-color: #1D1D1D;"
	"    border: 2px solid #161616;"
	"    border-radius: 6px;"
	"}"
	"QToolButton {"
	"    background-color: transparent;"
	"	 padding: 1px;"//avoid move on push effect
	"    border-radius: 4px;"
	"}"
	"QToolButton:hover {"
	"    background-color: #505050;"
	"    border-radius: 4px;"
	"}"
	"QToolButton:pressed, QToolButton:checked {"
	"    background-color: #4772B3;"
	"    border-radius: 4px;"
	"}"
/*---------------------------------------------*/
	"QDialog { background-color: #161616; }"
	"QLabel { color: white; }"
/*---------------------------------------------*/
    "QSpinBox {"
	"    background-color: #303030;"
	"    color: white;"
	"    border: 1px solid #505050;"
	"    border-radius: 4px;"
	"    padding: 2px;"
	"}"
	"QSpinBox::up-button {"
	"    background-color: #505050;"
	"    border-radius: 2px;"
	"    padding: 2px;"
	"    image: url(icons/arrow_up.png);"
	"}"
	"QSpinBox::down-button {"
	"    background-color: #505050;"
	"    border-radius: 2px;"
	"    padding: 2px;"
	"    image: url(icons/arrow_down.png);"
	"}"
	"QSpinBox::up-button:hover { background-color: #3A5986; }"
	"QSpinBox::down-button:hover { background-color: #3A5986; }"
/*---------------------------------------------*/
    "QComboBox {"
	"    background-color: #303030;"
	"    color: white;"
	"    border: 1px solid #505050;"
	"    border-radius: 4px;"
	"}"
	"QComboBox QAbstractItemView {"
	"    background-color: #1D1D1D;"
	"    selection-background-color: #3A5986;"
	"    selection-color: white;"
	"    color: white;"
	"    border: 1px solid #505050;"
	"}"
	"QComboBox::drop-down {"
	"    background-color: #505050;"
	"    border-radius: 2px;"
	"    padding: 1px;"
	"}"
	"QComboBox::drop-down:hover { background-color: #3A5986; }"
	"QComboBox::down-arrow { image: url(icons/arrow_down.png); }"
/*---------------------------------------------*/
    "QPushButton {"
	"    background-color: #505050;"
	"    color: white;"
	"    border: 1px solid #303030;"
	"    border-radius: 4px;"
	"}"
	"QPushButton:hover {"
	"    background-color: #3A5986;"
	"    border: 1px solid #4772B3;"
	"}"
/*---------------------------------------------*/
	"QSlider::groove:horizontal {"
	"    height: 4px;"
	"    background-color: #1D1D1D;"
	"    border: 1px solid #161616;"
	"    border-radius: 2px;"
	"}"
	"QSlider::handle:horizontal {"
	"    background-color: #161616;"
	"    border: 1px solid #141414;"
	"    width: 8px;"
	"    margin: -4px 0;"//
	"    border-radius: 2px;"
	"}"
	"QSlider::handle:horizontal:hover {"
	"    background-color: #3A5986;"
	"    border: 1px solid #4772B3;"
	"}"
	"QLineEdit {"
	"    background-color: #303030;"
	"    color: white;"
	"    border: 1px solid #505050;"
	"    border-radius: 2px;"
	"    padding: 2px;"
	"}"
/*---------------------------------------------*/
	"QGraphicsView { background-color: #303030; }"
	"QScrollBar:vertical { width: 28px; }"
	"QScrollBar:horizontal { height: 28px; }"
	"QScrollBar::add-page, QScrollBar::sub-page { background: none; height: 0px; }"
	"QScrollBar::add-line, QScrollBar::sub-line { height: 0px; }" //delete buttons
	"QScrollBar {"
	"    background-color: #505050;"
	"    border: 1px solid #161616;"
	"    border-radius: 6px;"
	"}"
	"QScrollBar::handle:vertical { min-height: 30px; }"
	"QScrollBar::handle:horizontal { min-width: 30px; }"
	"QScrollBar::handle {"
	"    background-color: #161616;"
	"    border: 1px solid #141414;"
	"    border-radius: 4px;"
	"}"
	"QScrollBar::handle:hover {"
	"    background-color: #3A5986;"
	"    border: 1px solid #4772B3;"
	"}"
};
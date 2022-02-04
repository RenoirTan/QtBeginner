#include "window.h"
#include <QApplication>
#include <QPushButton>
#include <QProgressBar>
#include <QSlider>

Window::Window(QWidget *parent) : QWidget{parent} {
    setFixedSize(200, 120);

    mClickCount = 0;

    mButton = new QPushButton("Hello world", this);
    mButton->setCheckable(true);
    // Call slotButtonClicked when button is clicked
    connect(mButton, SIGNAL(clicked(bool)), this, SLOT(slotButtonClicked(bool)));
    mButton->setGeometry(10, 10, 180, 40);
    QFont font("Courier");
    mButton->setFont(font);
    QIcon icon = QIcon::fromTheme("face-smile");
    mButton->setIcon(icon);

    mProgressBar = new QProgressBar(this);
    mProgressBar->setRange(0, 100);
    mProgressBar->setValue(0);
    mProgressBar->setGeometry(10, 50, 180, 30);

    mSlider = new QSlider(this);
    mSlider->setOrientation(Qt::Horizontal);
    mSlider->setRange(0, 100);
    mSlider->setValue(0);
    mSlider->setGeometry(10, 90, 180, 30);

    // Set progress bar == slider
    connect(mSlider, SIGNAL(valueChanged(int)), mProgressBar, SLOT(setValue(int)));

    // When click threshold reached, close app
    connect(this, SIGNAL(clickThresholdReached()), QApplication::instance(), SLOT(quit()));
}


void Window::slotButtonClicked(bool checked) {
    mButton->setText(checked ? "Checked" : "Hello world");
    if (++mClickCount >= 10) {
        emit clickThresholdReached();
    }
}

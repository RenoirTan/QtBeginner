#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>


class QPushButton;
class QProgressBar;
class QSlider;


class Window : public QWidget {
    Q_OBJECT
    public:
        explicit Window(QWidget *parent = nullptr);

    private:
        QPushButton *mButton;
        QProgressBar *mProgressBar;
        QSlider *mSlider;
        int mClickCount;

    private slots:
        void slotButtonClicked(bool checked);

    signals:
        void clickThresholdReached();
};

#endif // WINDOW_H

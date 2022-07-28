#include <QMainWindow>
#include <QtWidgets/QLineEdit>
#include <iostream>

class CommandHandler: public QMainWindow {
    Q_OBJECT

private:
    int channelValue, volumeValue;

    const int MAX_CHANNEL_VALUE = 9, MIN_CHANNEL_VALUE = 1, MAX_VOLUME_VALUE = 10, MIN_VOLUME_VALUE = 0;

public:

    QLineEdit* volume = nullptr;

    QLineEdit* channel = nullptr;

    CommandHandler(QWidget* parent = nullptr) : QMainWindow(parent) {
        channelValue = MIN_CHANNEL_VALUE;
        volumeValue = MIN_VOLUME_VALUE;
    }

    int getChannelValue() const {
        return channelValue;
    }

    void setChannelValue(int i) {
        if (i >= MIN_CHANNEL_VALUE && i <= MAX_CHANNEL_VALUE) channelValue = i;
        channelValue = MIN_CHANNEL_VALUE;
    }

    int getVolumeValue() const {
        return volumeValue;
    }

    void setVolumeValue(int i) {
        if (i >= MIN_VOLUME_VALUE && i <= MAX_VOLUME_VALUE) volumeValue = i;
        else volumeValue = MAX_VOLUME_VALUE/2;
    }

    void printValues() {
        volume->setText(QString::number(volumeValue) + "%");
        channel->setText(QString::number(channelValue));
    }


public slots:

    void setChannel1() {
        channel->setText("1");
        channelValue = 1;
    };

    void setChannel2() {
        channel->setText("2");
        channelValue = 2;
    };

    void setChannel3() {
        channel->setText("3");
        channelValue = 3;
    };

    void setChannel4() {
        channel->setText("4");
        channelValue = 4;
    };

    void setChannel5() {
        channel->setText("5");
        channelValue = 5;
    };

    void setChannel6() {
        channel->setText("6");
        channelValue = 6;
    };

    void setChannel7() {
        channel->setText("7");
        channelValue = 7;
    };

    void setChannel8() {
        channel->setText("8");
        channelValue = 8;
    };

    void setChannel9() {
        channel->setText("9");
        channelValue = 9;
    };

    void increaseChannel() {
        channelValue++;
        if (channelValue > MAX_CHANNEL_VALUE) channelValue = MIN_CHANNEL_VALUE;
        channel->setText(QString::number(channelValue));
    }

    void decreaseChannel() {
        channelValue--;
        if (channelValue < MIN_CHANNEL_VALUE) channelValue = MAX_CHANNEL_VALUE;
        channel->setText(QString::number(channelValue));
    }

    void increaseVolume() {
        volumeValue++;
        if (volumeValue > MAX_VOLUME_VALUE) volumeValue = MAX_VOLUME_VALUE;
        volume->setText(QString::number(volumeValue * 10) + "%");
    }

    void decreaseVolume() {
        volumeValue--;
        if (volumeValue < MIN_VOLUME_VALUE) volumeValue = MIN_VOLUME_VALUE;
        volume->setText(QString::number(volumeValue * 10) + "%");
    }

};
#ifndef CLOCK_H
#define CLOCK_H

class Clock {
public:
    Clock();
    void showTime();
    void setTime(int h, int m);
    void advanceTime();

private:
    int hour;
    int minute;
};

#endif // CLOCK_H

#include "clock.hxx"
#include <iostream>
#include <iomanip> // For formatting time

using namespace std;

Clock::Clock() : hour(12), minute(0) {}

void Clock::showTime() {
    cout << "Current time: " << setw(2) << setfill('0') << hour 
         << ":" << setw(2) << setfill('0') << minute << "\n";
}

void Clock::setTime(int h, int m) {
    hour = h % 24;
    minute = m % 60;
    cout << "Time set to: " << setw(2) << setfill('0') << hour 
         << ":" << setw(2) << setfill('0') << minute << "\n";
}

void Clock::advanceTime() {
    minute++;
    if (minute >= 60) {
        minute = 0;
        hour = (hour + 1) % 24;
    }
    showTime();
}

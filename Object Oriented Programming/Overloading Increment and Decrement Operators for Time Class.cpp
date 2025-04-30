#include <iostream>
using namespace std;
class Time {
public:
    int hours, minutes, seconds;

    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    void showTime() {
        cout << hours << ":" << minutes << ":" << seconds << std::endl;
    }

    Time operator++() {
        ++seconds;
        if (seconds >= 60) {
            seconds = 0;
            ++minutes;
            if (minutes >= 60) {
                minutes = 0;
                ++hours;
            }
        }
        return *this;
    }

    Time operator--() {
        if (seconds == 0) {
            if (minutes == 0) {
                --hours;
                minutes = 59;
            } else {
                --minutes;
            }
            seconds = 59;
        } else {
            --seconds;
        }
        return *this;
    }
};

int main() {
    Time t1(10, 25, 19);
    t1.showTime(); 

    ++t1;
    t1.showTime(); 

    t1.showTime(); 

    return 0;
}
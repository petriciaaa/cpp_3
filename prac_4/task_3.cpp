#include <iostream>
using namespace std;

class Time {
private:
    int hrs, min, sec;

public:
    Time() : hrs(0), min(0), sec(0) {}

    Time(int h, int m, int s) {
        setTime(h, m, s);
    }

    void setTime(int h, int m, int s);
    void print() const;

    Time operator +(const Time& t2) const;
    Time operator -(const Time& t2) const;
    Time operator *(const Time& t2) const;

private:
    void normalize();
};

void Time::setTime(int h, int m, int s) {
    hrs = h;
    min = m;
    sec = s;
    normalize();
}

void Time::print() const {
    cout << hrs << ":" << (min < 10 ? "0" : "") << min << ":" << (sec < 10 ? "0" : "") << sec << endl;
}


Time Time::operator +(const Time& t2) const {
    Time result;
    result.hrs = hrs + t2.hrs;
    result.min = min + t2.min;
    result.sec = sec + t2.sec;
    result.normalize();
    return result;
}

Time Time::operator -(const Time& t2) const {
    Time result;

    int total_secs1 = hrs * 3600 + min * 60 + sec;
    int total_secs2 = t2.hrs * 3600 + t2.min * 60 + t2.sec;

    int diff_secs = total_secs1 - total_secs2;

    if (diff_secs < 0) {
        diff_secs += 24 * 3600;
    }

    result.hrs = diff_secs / 3600;
    result.min = (diff_secs % 3600) / 60;
    result.sec = diff_secs % 60;

    return result;
}

Time Time::operator *(const Time& t2) const {
    Time result;
    double factor;

    int total_secs_1 = hrs * 3600 + min * 60 + sec;
    int total_secs_2 = t2.hrs * 3600 + t2.min * 60 + t2.sec;

    factor = (total_secs_2) / 3600.;

    int total_result_secs = static_cast<int>(total_secs_1 * factor);

    result.hrs = total_result_secs / 3600;
    result.min = (total_result_secs % 3600) / 60;
    result.sec = total_result_secs % 60;

    return result;
}

void Time::normalize() {
    if (sec >= 60) {
        min += sec / 60;
        sec %= 60;
    }

    if (min >= 60) {
        hrs += min / 60;
        min %= 60;
    }

    if (hrs < 0 || min < 0 || sec < 0) {
        hrs = min = sec = 0;
    }

    if (hrs >= 24) {
        hrs %= 24;
    }
}

int main() {
    Time time1(2, 0, 0);
    Time time2(0, 45, 00);

    Time time3;
    Time time4;
    Time time5;

    time3 = time1 + time2;
    time4 = time1 - time2;
    time5 = time1 * time2;

    cout << "Time1: ";
    time1.print();

    cout << "Time2: ";
    time2.print();

    cout << "Time3: ";
    time3.print();

    cout << "Time4: ";
    time4.print();

    cout << "Time5: ";
    time5.print();

    return 0;
}
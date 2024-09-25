#include <iostream>
#include <iomanip>


class Time
{

private:
	int hrs;
	int min;
	int sec;

    void normalize() {
        if (sec >= 60) {
            min += sec / 60;
            sec = sec % 60;
        }
        else if (sec < 0) {
            min -= (-sec - 1) / 60 + 1; 
            sec = (sec % 60 + 60) % 60; 
        }

        if (min >= 60) {
            hrs += min / 60;
            min = min % 60;
        }
        else if (min < 0) {
            hrs -= (-min - 1) / 60 + 1; 
            min = (min % 60 + 60) % 60; 
        }

        if (hrs >= 24) {
            hrs = hrs % 24;
        }
        else if (hrs < 0) {
            hrs = (hrs % 24 + 24) % 24;
        }
        std::cout << std::setfill('0');
    }

public:
	Time() : hrs(0), min(0), sec(0) {};
	Time(int hrs , int min , int sec){
		this->hrs = hrs;
		this->min = min;
		this->sec = sec;
	};

	    void display() const {
        std::cout << std::setfill('0') << std::setw(2) << hrs << ":"
                  << std::setfill('0') << std::setw(2) << min << ":"
                  << std::setfill('0') << std::setw(2) << sec << std::endl;
    }

        static Time add_time(const Time& time1, const Time  time2)  {
            Time result;

            result.hrs = time1.hrs + time2.hrs;
            result.min = time1.min + time2.min;
            result.sec = time1.sec + time2.sec;
            result.normalize();
            return result;
        }        
        static Time ded_time(const Time time1, const Time  time2)  {
            Time result;

            result.hrs = time1.hrs - time2.hrs;
            result.min = time1.min - time2.min;
            result.sec = time1.sec - time2.sec;
            result.normalize();
            return result;
        }

};



int main()
{
    const Time time1(10, 0, 40), time2(00, 20, 10);
    Time time3, time4;

    time3 = Time::add_time(time1, time2);
    time4 = Time::ded_time(time1, time2);

    std::cout << "time1 = "; time1.display();
    std::cout << "time2 = "; time2.display();
    std::cout << "time3 = "; time3.display();
    std::cout << "time4 = "; time4.display();
}


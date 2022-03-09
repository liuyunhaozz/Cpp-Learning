#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

class Time {
    private:
        int hour = 0;
        int minute = 0;
        int second = 0;
    public:
        Time() = default;
        Time(int, int, int);
        friend istream& operator>>(istream&, Time&);
        friend ostream& operator<<(ostream&, Time&);
        Time& operator+=(const Time&);
        Time& operator-=(const Time&);
        Time& operator++();
        Time operator++(int);
        Time& operator--();
        Time operator--(int);
};

Time::Time(int hour, int minute, int second) {
    this->hour = hour;
    this->minute = minute;
    this->second = second;
}


istream& operator>>(istream& is, Time& t) {
    is >> t.hour >> t.minute >> t.second;
    return is;
}

ostream& operator<<(ostream& os, Time& t) {
    os << setw(2) << setfill('0') << t.hour << ":" 
    << setw(2) << setfill('0')<< t.minute << ":" 
    << setw(2) << setfill('0') << t.second;
    return os;
}

Time& Time::operator+=(const Time& t) {
    if (t.second + this->second >= 60) {
        this->second = t.second + this->second - 60;
        if (t.minute + this->minute + 1 >= 60) {
            this->minute = t.minute + this->minute + 1 - 60;
            if (t.hour + this->hour + 1 >= 24) {
                this->hour = t.hour + this->hour + 1 - 24;
            }
            else {
                this->hour = t.hour + this->hour + 1;
            }   
        }
        else {
            this->minute = t.minute + this->minute + 1;
            if (t.hour + this->hour >= 24) {
                this->hour = t.hour + this->hour - 24;
            }
            else {
                this->hour = t.hour + this->hour;
            }
        }
    }
    else {
        this->second = t.second + this->second;
        if (t.minute + this->minute>= 60) {
            this->minute = t.minute + this->minute - 60;
            if (t.hour + this->hour + 1 >= 24) {
                this->hour = t.hour + this->hour + 1 - 24;
            }
            else {
                this->hour = t.hour + this->hour + 1;
            }
        }
        else {
            this->minute = t.minute + this->minute;
            if (t.hour + this->hour >= 24) {
                this->hour = t.hour + this->hour - 24;
            }
            else {
                this->hour = t.hour + this->hour;
            }

        }
    }
    return *this;
}

Time& Time::operator-=(const Time& t) {
    if (this->second < t.second) {
        this->second = this->second + 60 - t.second;
        if (this->minute - 1 < t.minute) {
            this->minute = this->minute - 1 + 60 - t.minute;
            if (this->hour - 1 < t.hour) {
                this->hour = this->hour - 1 + 24 - t.hour;
            }
            else {
                this->hour = this->hour - 1 -t.hour;
            }   
        }
        else {
            this->minute = this->minute - 1 - t.minute;
            if (this->hour < t.hour) {
                this->hour = this->hour + 24 - t.hour;
            }
            else {
                this->hour = this->hour - t.hour;
            }
        }
    }
    else {
        this->second = this->second - t.second;
        if (this->minute < t.minute) {
            this->minute = this->minute + 60 - t.minute;
            if (this->hour - 1 < t.hour) {
                this->hour = this->hour - 1 + 24 - t.hour;
            }
            else {
                this->hour = this->hour - 1 - t.hour;
            }
        }
        else {
            this->minute = this->minute - t.minute;
            if (this -> hour < t.hour) {
                this->hour = this->hour + 24 - t.hour;
            }
            else {
                this->hour = this->hour - t.hour;
            }

        }
    }
    return *this;
}

// 前置自增与自减
Time& Time::operator++() {
    Time adder(0, 0, 1);
    *this += adder;
    return *this;
}

Time& Time::operator--() {
    Time suber(0, 0, 1);
    *this -= suber;
    return *this;
}

// 后置自增与自减
Time Time::operator++(int) {
    Time tmp = *this;
    Time adder(0, 0, 1);
    *this += adder;
    return tmp;
}

Time Time::operator--(int) {
    Time tmp = *this;
    Time suber(0, 0, 1);
    *this -= suber;
    return tmp;
}

int main()
{
    Time time1, time2;
    cin >> time1 >> time2;
    cout << (time1 += (time2++)) << endl;
    cout << (time1 -= time2) << endl;
    cout << (++time2) << endl;
    cout << (time2 += (time1--)) << endl;
    cout << (--time1) << endl;
    cout << (time2 -= time1);
}







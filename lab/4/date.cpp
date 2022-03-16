#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

class Date {
    private:
        int year = 0;
        int month = 0;
        int day = 0;
        static int month2Day[12];
        int bitofYear();
    public:
        Date() = default;
        Date(int y, int m, int d) : year(y), month(m), day(d) {}
        int getDay() { return day; }
        int getMonth() { return month; }
        int getYear() { return year; }
	    bool isLeapYear(int year) const;
        int getDayfromMonth(int y, int n);
        friend ostream& operator<<(ostream& os, Date& date);
	    friend istream& operator>>(istream& os, Date& date);
	    Date& operator+=(int n);

};

int Date::bitofYear() {
    int bit = 0;
    int tmp = year;
    while (tmp) {
        bit += 1;
        tmp = tmp / 10;
    }
    return bit;
}

bool Date::isLeapYear(int y) const {
	return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}

int Date::month2Day[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

int Date::getDayfromMonth(int y, int n) {
    if (n == 2)
        return month2Day[n-1] + isLeapYear(y);
    else
        return month2Day[n-1];
}

Date& Date::operator+=(int n) {
    int curDay = 0;
    for (int i = 1; i < month; ++i) {
        // cout << getDayfromMonth(year, i) << endl;
        curDay += getDayfromMonth(year, i);
    }
    curDay += day;
    // cout << curDay << endl;
    // 处理超过一年的天数  
    // cout << 365 + isLeapYear(year) - curDay << endl;
    if (n >= (365 + isLeapYear(year) - curDay)) {
        // 把当前日期增加到 12 月 31 日, 完成 1 年
        n -= (365 + isLeapYear(year) - curDay);
        month = 12;
        day = 31;
        // 增加年数
        while (n >= 365 + isLeapYear(year + 1)) {
            year += 1;
            n = n - (365 + isLeapYear(year));
        }
    }
    // cout << n << endl;
    // 处理不足一年的天数, 从 12 月 31 日开始
    while(n) {
        if (day == getDayfromMonth(year, month)) {
            day = 1;
            if (month == 12) {
                month = 1;
                year += 1;
                // printf("True");
                // cout << n << endl;
            }
            else
                month += 1;
        }
        else
            day = day + 1;
        n = n - 1;
    }
    return *this;  
} 

istream& operator>>(istream& is, Date& date) {
    string str;
    is >> str;
    date.year = stoi(str.substr(0, 4));
    date.month = stoi(str.substr(4, 2));
    date.day = stoi(str.substr(6, 2));
    return is;
}

ostream& operator<<(ostream& os, Date& date) {
    if (date.bitofYear() > 4) {
        os << "out of limitation!";
    }
    else
        os << setw(4) << setfill('0') << date.year
        << setw(2) << setfill('0') << date.month
        << setw(2) << setfill('0') << date.day;
    return os;
}

int main()
{
    Date date;
    int n;
    cin >> date >> n;
    // cout << n << endl;
    // cout << date.getYear() << " " << date.getMonth() << " " << date.getDay();
    date += n;
    // cout << endl;
    cout << date;
}
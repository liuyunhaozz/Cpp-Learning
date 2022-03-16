#include<string>
#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>

using namespace std;

class Student {
    private:
        string name;
        int chinese = 0;
        int math = 0;
        int english = 0;
        int total = 0;
    public:
        void read();
        void print();
        friend bool mycomp(const Student &, const Student &);
};

void Student::read() {
    cin >> name >> chinese >> math >> english;
    total = chinese + math + english;
}

void Student::print() {
    cout << name << " " << total;
}

bool mycomp(const Student &t1, const Student &t2)
{
	if (t1.total != t2.total) 
        return t1.total > t2.total;
    else if (t1.chinese != t2.chinese)
        return t1.chinese > t2.chinese;
    else if (t1.math != t2.math)
        return t1.math > t2.math;
    else if (t1.english != t2.english)
        return t1.english > t2.english;
    else
        return t1.name < t2.name;
}

int main()
{
    int n, k;
    cin >> n;
    vector<Student> stus;
    for (int i = 0; i < n; ++i) {
        Student stu;
        stu.read();
        stus.push_back(stu);
    }
    sort(stus.begin(), stus.end(), mycomp);
    cin >> k;
    stus[k-1].print();
}


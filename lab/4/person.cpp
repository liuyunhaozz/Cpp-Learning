#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

class Person {
    private:
        string *name;
        int age;
        bool gender;
    public:
        Person() : name(new string("Rose")), age(19), gender(1) {
            cout << "Parameterless constructor" << endl;
            print();
        }
        Person(string *str, int a, bool g) :
            name(new string(*str)), age(a), gender(g) {
                cout << "Parameter constructor" << endl;
                print();
            }
        Person(Person &p) :
            name(new string(*p.name)), age(p.age), gender(p.gender) {
                cout << "Copy constructor" << endl;
                print();
            }
        ~Person() { delete name; }
        void print();
};

void Person::print() {
    cout << "Information:" << endl;
    if (gender) {
        cout << "Name: " << *name << "    " << "Sex: " << "female" << "    "
        << "Age: " << age << endl;
    }
    else {
        cout << "Name: " << *name << "    " << "Sex: " << "male" << "    "
        << "Age: " << age << endl;        
    }
}

int main()
{
    string name1, name2;
    bool gender1, gender2;
    int age1, age2;
    cin >> name1 >> gender1 >> age1;
    cin >> name2 >> gender2 >> age2;
    Person a;
    Person b(&name2, age2, gender2);
    Person c(b);
}


#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>

#define MAX_LEN 100
#define INCREASE_LEN 20

using namespace std;

class ListSq {
    private:
        int *p;
        int length;
        int listsize;
    public:
        ListSq() : p(new int[MAX_LEN]), length(0), listsize(MAX_LEN) {} 
        ListSq(const ListSq&);
        ~ListSq();
        void listSort();
        void pushBack(int);
        friend istream& operator>>(istream&, ListSq&);
        friend ostream& operator<<(ostream&, ListSq&);
};

istream& operator>>(istream& is, ListSq& list) {
    int num;
    string line;
    getline(is, line);
    istringstream iss(line);
    while (iss >> num) {
        list.pushBack(num);
    }
    return is;
}

ostream& operator<<(ostream& os, ListSq& list) {
    for (int i = 0; i < list.length; ++i) {
        cout << list.p[i] << " ";
    }
    cout << endl;
    return os;
}

ListSq::~ListSq() {
    delete[] p;
} 

ListSq::ListSq(const ListSq& list) {
    length = list.length;
    listsize = list.listsize;
    p = new int[MAX_LEN];
    for (int i = 0; i < length; ++i) {
        p[i] = list.p[i];
    }
}

void ListSq::listSort() {
    sort(p, p + length);
}

void ListSq::pushBack(int value) {
    if (length == listsize) {
        listsize = MAX_LEN + INCREASE_LEN;
        int *tmp = p;
        p = new int[listsize];
        for (int i = 0; i < length; ++i) {
            p[i] = tmp[i];
        }
        delete[] tmp;
    }
    p[length] = value;
    length += 1;
}

int main()
{
    ListSq list;
    cin >> list;
    list.listSort();
    cout << list;
    list.pushBack(8);
    list.listSort();
    cout << list;
    ListSq newList(list);
    cout << list;
}



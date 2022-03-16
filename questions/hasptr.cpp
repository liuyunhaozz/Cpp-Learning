#include<iostream>
#include<string>

using namespace std;

// 行为像值的类 HasPtr
class HasPtr {
    public:
        HasPtr(const std::string &s = std::string()) :
            ps(new std::string(s)), i(0) {};
        HasPtr(const HasPtr &p) :
            ps(new std::string(*p.ps)), i(p.i) {};
        HasPtr& operator=(const HasPtr &);
        ~HasPtr() {delete ps;}
        
    private:
        std::string *ps;
        int i;
};

/*
对于一个赋值运算符，即使是将一个对象赋予它自身，也要能正常工作。
一个好的方法是在销毁左侧运算对象资源之前拷贝右侧运算对象。
*/

HasPtr& HasPtr::operator=(const HasPtr &rhs) {
    auto newp = new string(*rhs.ps);
    delete ps;
    ps = newp;
    i = rhs.i;
    return *this;
}



// 行为像指针的类
class HasPtr2 {
    public:
        HasPtr2(const string &s = string()) :
            ps(new string(s)), i(0), use(new size_t(1)) {}
        HasPtr2(const HasPtr2 &p) : 
            ps(p.ps), i(p.i), use(p.use) { ++*use; }
        HasPtr2& operator=(const HasPtr2&);
        ~HasPtr2();
        
    private:
        string *ps;
        int i;
        size_t *use;
};

HasPtr2::~HasPtr2()
{
    // 如果引用计数为0，销毁对象
    if (--*use == 0) {
        delete ps;
        delete use;
    }
}

HasPtr2& HasPtr2::operator=(const HasPtr2& rhs) {
    // 如果两个对象相同，那么当我们检查ps(rhs)是否应该释放时，计数器就已经被递增过了，相当于计数器不变
    ++*rhs.use;
    if (--*use == 0) {
        delete ps;
        delete use;
    }
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
    return *this;
}


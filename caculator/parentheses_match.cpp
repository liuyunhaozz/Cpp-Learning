#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>

using namespace std;
template <class T>
class mystack
{ //创建一个栈类
public:
    mystack(); //无参构造函数
    mystack(int initialCapacity)
    { //含参构造函数
        stackLength = initialCapacity;
        stack = new T[stackLength]; //stack为一个数组
        stackTop = -1;              //初始化栈顶元素
    }
    ~mystack() { delete[] stack; }          //析构函数
    bool empty() { return stackTop == -1; } //判断栈是否为空
    int size() { return stackTop + 1; }     //返回栈中元素个数
    T &top()                                //返回栈顶元素
    {
        if (stackTop == -1)
        { //栈空
            cout << "该栈为空" << endl;
        }
        else
            return stack[stackTop];
    }
    void pop() //弹出栈顶元素
    {
        if (stackTop == -1)
        {
            cout << "该栈为空" << endl;
        }
        else
            stack[stackTop--]; //.~T()
    }
    void push(T theElement)
    {                                    //将theElement压入栈
        if (stackTop == stackLength - 1) //栈满扩充
        {
            stackLength *= 2; //将栈的容量扩充二倍
            T newStack[stackLength];
            for (int i = 0; i < stackLength; i++)
            {
                newStack[i] = stack[i];
            }
            delete stack;
            stack = newStack;
        }
        stack[++stackTop] = theElement; //然栈顶元素等于目前需要压入栈中的元素
    }

private:
    int stackTop;    //栈顶元素索引
    int stackLength; //栈大小
    T *stack;        //栈
};

void operate(string s, int length)
{
    bool flag = false;               //用来判断输入-的是否为负号
    mystack<long int> n(length);     //声明一个数字栈
    mystack<char> c(length);         //声明一个字符栈
    for (int i = 0; i < length; i++) //遍历输入的表达式
    {
        if (s[i] == ' ')
            continue;                   //如果输入的如果是空格，跳过
        if (s[i] >= '0' && s[i] <= '9') //当输入为数字时
        {
            int bitcout = 1;
            int floatbit = 0;
            int k = s[i] - '0';
            while (true)
            {
                if (s[i + 1] == '.')
                {
                    floatbit = bitcout;
                    i++;
                }

                else if (s[i + 1] >= '0' && s[i + 1] <= '9')
                {
                    k = 10 * k + (s[i + 1] - '0');
                    i++;
                    bitcout++;
                }
                else
                    break;
            }
            if (flag)
            { //判断是否为负数
                k = -k;
                flag = false; //读到一个负数，标识符归零
            }

            if (floatbit)
                printf("操作数: %g\n", k / pow(10, bitcout - floatbit));
            else
                printf("操作数: %d\n", k);
        }
        else
        {                                                                                         //读到的是字符
            if ((i == 0 || s[i - 1] == '(' || s[i - 1] == '[' || s[i - 1] == '{') && s[i] == '-') //-号前面为（或者-号为第一个代表-为负号而不是减号
            {
                flag = true;
                continue;
            }
            switch (s[i])
            {
            case '+':
                cout << "操作符: 加号"
                     << "\n";
                break;
            case '-':
                cout << "操作符: 减号"
                     << "\n";
                break;
            case '*':
                cout << "操作符: 乘号"
                     << "\n";
                break;
            case '/':
                cout << "操作符: 除号"
                     << "\n";
                break;

            case '(': // 左括号直接入栈
                c.push(s[i]);
                cout << "操作符: 左小括号"
                     << "\n";
                break;
            case '[':
                c.push(s[i]);
                cout << "操作符: 左中括号"
                     << "\n";
                break;
            case '{':
                c.push(s[i]);
                cout << "操作符: 左大括号"
                     << "\n";
                break;

            case ')': //遇到右括号 ，对括号内运算直至运算到左括号
                if (c.empty())
                {
                    cout << "右小括号 匹配错误"
                         << "\n";
                    return;
                }
                else if (c.top() != '(')
                {
                    cout << "右小括号 匹配错误"
                         << "\n";
                    return;
                }
                else
                {
                    cout << "操作符: 右小括号"
                         << "\n";
                    c.pop();
                }

                break;

            case ']':
                if (c.empty())
                {
                    cout << "右中括号 匹配错误"
                         << "\n";
                    return;
                }
                else if (c.top() != '[')
                {
                    cout << "右中括号 匹配错误"
                         << "\n";
                    return;
                }
                else
                {
                    cout << "操作符: 右中括号"
                         << "\n";
                    c.pop();
                }

                break;
            case '}':
                if (c.empty())
                {
                    cout << "右大括号 匹配错误"
                         << "\n";
                    return;
                }
                else if (c.top() != '{')
                {
                    cout << "右大括号 匹配错误"
                         << "\n";
                    return;
                }
                else
                {
                    cout << "操作符: 右大括号"
                         << "\n";
                    c.pop();
                }

                break;

            default:
                break;
            }
        }
    }
}
int main()
{
    while (1)
    {
        string s;   //将输入的表达式存到一个字符串中
        int length; //记录字符串长度
        cout << "请输入一个运算表达式：" << endl;
        cin >> s; //输入表达式
        length = s.length();
        operate(s, length);
    }
    return 0;
}
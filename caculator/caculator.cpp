#include<iostream>
#include<string>
#include<cstdlib>
/*1、创建栈类，采用数组描述；
2、计算数学表达式的值。
输入数学表达式，输出表达式的计算结果。数学表达式由单个数字和
运算符“+”、“-”、“*”、“/”、“(”、“) ”构成，例如 2+3*(4+5)–6/4。
假定表达式输入格式合法。
选做：*3、以一个 m*n 的长方阵表示迷宫，0 和 1 分别表示迷宫中的通路和障碍。
设计一个程序，对任意设定的迷宫，求出一条从入口到出口的通路，或得出没有通路的结论。
迷宫根据一个迷宫数据文件建立。迷宫数据文件由一个包含 0、1 的矩阵
组成。迷宫的通路可以使用通路上各点的坐标序列进行展示(使用图形展示最佳)。*/
using namespace std;
template<class T>
class mystack
{//创建一个栈类 
	public:
		mystack();                  //无参构造函数 
		mystack(int initialCapacity){//含参构造函数 
			stackLength=initialCapacity;
			stack=new T[stackLength];     //stack为一个数组 
			stackTop=-1;//初始化栈顶元素 
		}
		~mystack(){delete [] stack;	}//析构函数 
		bool empty(){ return stackTop==-1;}//判断栈是否为空 
		int size(){ return stackTop+1;}//返回栈中元素个数 
		T & top()//返回栈顶元素 
		{
			if(stackTop==-1){//栈空 
				cout<<"该栈为空"<<endl;
			} 
			else return stack[stackTop];
		}
		void pop()//弹出栈顶元素 
		{
			if(stackTop==-1){
				cout<<"该栈为空"<<endl;
			} 
			else stack[stackTop--];//.~T()
		}
		void push(T theElement){//将theElement压入栈 
			if(stackTop==stackLength-1)//栈满扩充 
			{
				stackLength*=2;      //将栈的容量扩充二倍 
				T newStack[stackLength];
				for(int i=0;i<stackLength;i++)
				{
					newStack[i]=stack[i];
				}
				delete stack;
				stack=newStack;	
			}
			stack[++stackTop]=theElement;//然栈顶元素等于目前需要压入栈中的元素 
		}
	private:
		int stackTop;   //栈顶元素索引 
		int stackLength;//栈大小 
		T * stack;      //栈 
};
void calculate(mystack<long int> &n, mystack<char> &c)
{//定义运算，将数字栈的前两个数和符号栈栈顶元素取出做一次运算 并将结果压入数字栈 
	if(c.top()=='(') return;
	long int a,b;
	a=n.top();    
	//cout<<a<<"    a的值"<<endl;       //取数字栈栈顶元素 
	n.pop();             //弹出栈顶元素 
	b=n.top();   
	//cout<<b<<"    b的值"<<endl;         //取数字栈第二个元素 
	n.pop();             //弹出栈顶元素 
	switch(c.top())
	{                    //根据符号栈的栈顶元素不同进行不同运算 
		case '+':
			n.push(a+b);
			break;
		case '-':
			n.push(b-a);
			break;
		case '*':
			n.push(a*b);
			break;
		case '/':
			n.push(b/a);
			break;	
		default:break;
	}
	c.pop();//将运算完的符号弹出栈 
}
void operate(string s,int length) 
{
	bool flag=false;      //用来判断输入-的是否为负号 
	mystack<long int> n(length);     //声明一个数字栈 
	mystack<char> c(length);       //声明一个字符栈 
	for(int i=0;i<length;i++)      //遍历输入的表达式 
	{
		if(s[i]==' ') continue;       //如果输入的如果是空格，跳过 
		if(s[i]>='0'&&s[i]<='9')      //当输入为数字时 
		{
			int k=s[i]-'0';
			while(s[i+1]>='0'&&s[i+1]<='9')//如果下一个为数字 则记录整个数字
			{
				k=10*k+(s[i+1]-'0');
				i++;
			}
			if(flag){                //判断是否为负数 
			 //   c.pop(); 
				k=-k;
				flag=false;          //读到一个负数，标识符归零 
			}
			n.push(k);               //将读入的数字压到数字栈 
		}
		else
		{//读到的是字符 
			if((i==0||s[i-1]=='(')&&s[i]=='-')//-号前面为（或者-号为第一个代表-为负号而不是减号 
			{
				flag=true;
				continue;
			}
			switch(s[i]){
				case '+':
				case '-':
					if(c.empty()||c.top()=='(') c.push(s[i]);//如果符号栈为空或者栈顶元素为(,+、-直接压入栈 
					else{
						calculate(n,c);                      //+-运算符优先级最低，对之前运算先运算 
						if(!c.empty()&&c.top()!='(') calculate(n,c);
						c.push(s[i]);                        //将读到的符号压入栈 
					}
					break;
				case '*':
				case '/':
					if(c.empty()||c.top()=='(') c.push(s[i]);//如果符号栈为空或者栈顶元素为(,*/直接压入栈 
					else if(c.top()=='+'||c.top()=='-') c.push(s[i]);//如果前一个运算符为+或-，*/直接压入栈 
					else if(c.top()=='*'||c.top()=='/')
						{                                     //前一个运算符为*或/可以直接运算 
							calculate(n,c);
							c.push(s[i]);
						 } 				
					break;
				case '('://左括号直接入栈 
					c.push(s[i]);
					break;
				case ')'://遇到右括号 ，对括号内运算直至运算到左括号 
					while (c.top()!='(') {
					calculate(n,c);
				//	c.pop();
					}
					c.pop();//将左括号弹出栈 
					break;
				default:break;
			}
		}
	}
		cout<<"计算所得的结果是："; 
	while(!c.empty()) calculate(n,c);
			cout<<n.top()<<endl;
}
int main()
{  
    while(1) {
	string s;             //将输入的表达式存到一个字符串中 
	int length;           //记录字符串长度 
	cout << "请输入一个运算表达式：" << endl; 
	cin >> s;               //输入表达式 
	length=s.length();	
    operate(s, length);
	}
    return 0;
} 
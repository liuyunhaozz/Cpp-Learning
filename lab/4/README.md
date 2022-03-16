## 1  date

【问题描述】

设计一个类用于存放日期，并向后推算指定日期经过n天后的具体日期。

【输入形式】

- 输入为长度为8的字符串str和一个正整数n，str前四位表示年份，后四位表示月和日。

【输出形式】

- 当推算出的年份大于4位数时，输出"out of limitation!"，否则输出8位的具体日期。

【样例输入1】

```
00250709 60000
```

【样例输出1】

```
01891017
```

【样例输入2】

```
19310918 5080
```

【样例输出2】

```
19450815
```

【样例输入3】

```
99980208 999
```

【样例输入3】

```
out of limitation!
```

【样例说明】

- 日期的表示必须8位数，年月日不足长度需要添加前缀字符'0'。

- 注意闰年和平年的2月份天数不同。
- 注意判断输出信息是否符合要求。

【评分标准】

共5个测试用例





## 2 Rectan

【问题描述】

设计一个Rectangle类。要求：



（1）包含两个成员变量m_length和m_width，其默认值为1。

（2）包含成员函数Perimeter()计算长方形的周长，Area()计算长方形面积。

（3）包含成员函数SetWidth()和GetWidth()用来设置和得到m_width的值，SetLength()和GetLength()用来设置和得到m_length的值。SetRange()函数应验证m_length和m_width均为0.0到20.0之间的浮点数。

（4）编写主函数，测试Rectangle类。



【输入形式】无

【输出形式】

输出矩阵的长、宽、长和宽是否均为0.0到20.0之间的浮点数、周长和面积。

Length :   Width : 

length and width are both in 0.0 - 20.0





Perimeter: 18

Area: 

【样例输入1】

```
4 5
```

【样例输出1】

```
Length: 4    Width: 5
length and width are both in 0.0 - 20.0
Perimeter: 18
Area: 20
```

【样例输入2】

```
40 5
```

【样例输出2】

```
Length: 40    Width: 5
length is not in 0.0 - 20.0
Perimeter: 90
Area: 200
```

【样例说明】

输入中先后输入矩阵的长和宽。输出第一行为矩阵的长和宽，输出第二行为判断矩阵的长和宽是否为0.0到20.0之间的浮点数，输出第三行为矩阵的周长，输出第四行为矩阵的面积。





## 3 person

【问题描述】

编写一个Person类，包括：



1、普通数据成员：姓名，性别，年龄。

2、三个构造函数：无参数构造函数，有参数构造函数（参数：姓名的指针，年龄，性别），拷贝构造函数。

编写main（）函数，分别调用三种构造函数，创建三个对象P1、P2、P3，其中P3的创建是用P2通过深拷贝复制得到的。


【输入形式】无
【输出形式】输出所使用的构造函数的说明，并输出人员的相关信息。
【样例输入】

```
Rose 1 19
Jack 0 20
```

【样例输出】

```
Parameterless constructor
Information:
Name: Rose    Sex: female    Age: 19
Parameter constructor
Information:
Name: Jack    Sex: male    Age: 20
Copy constructor
Information:
Name: Jack    Sex: male    Age: 20
```

【样例说明】依次说明三个构造函数，之后打印两个人员的姓名，性别和年龄。其中，输入0表示性别男，输入1表示性别女。

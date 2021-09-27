#include <cmath>
#include <iostream>
#include <stdlib.h>

#define LEN 4
 
#ifndef __MATRIX_CLL_H__
#define __MATRIX_CCL_H__

 
class Matrix {
private:
	int rows_num= LEN, cols_num = LEN;
	double **p;
	void initialize();//初始化矩阵
 
public:
	Matrix();
	Matrix(int, int, double);//预配分空间
	Matrix( const Matrix &); // 拷贝构造函数
	Matrix(const double [][LEN]); // 二维数组初始化
	virtual ~Matrix();//析构函数应当是虚函数，除非此类不用做基类
	Matrix& operator=(const Matrix&);//矩阵的复制
	Matrix& operator=(double *);//将数组的值传给矩阵
	Matrix& operator+=(const Matrix&);//矩阵的+=操作
	Matrix& operator-=(const Matrix&);//-=
	Matrix& operator*=(const Matrix&);//*=
	Matrix operator*(const Matrix & m)const;
	Matrix operator+(const Matrix & m)const;
	Matrix operator-(const Matrix & m)const;
	Matrix operator^(const int n)const;
	double* operator[](int i);	
	double Point(int i, int j) const;
	Matrix inverse();//求矩阵的逆矩阵
	Matrix transpose();//矩阵转置的实现,且不改变矩阵
	friend std::istream& operator>>(std::istream&, Matrix&);//实现矩阵的输入
	friend std::ostream& operator<<(std::ostream&, Matrix&);//实现矩阵的输出
};
 
 
#endif
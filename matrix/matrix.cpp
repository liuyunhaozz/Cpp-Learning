#include "matrix.h"
#include<iostream>
#include <iomanip>
using std::endl;
using std::cout;
using std::istream;
using std::ostream;
const double EPS = 1e-10;
void Matrix::initialize() {//初始化矩阵大小
	p = new double*[rows_num];//分配rows_num个指针
	for (int i = 0; i < rows_num; ++i) {
		p[i] = new double[cols_num];//为p[i]进行动态内存分配，大小为cols
	}
}
//声明一个全1矩阵
Matrix::Matrix()
{
	rows_num = LEN;
	cols_num = LEN;
	initialize();
	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < cols_num; j++) {
			p[i][j] = 1;
		}
	}
}
//声明一个值全部为value的矩阵
Matrix::Matrix(int rows, int cols, double value)
{
	rows_num = rows;
	cols_num = cols;
	initialize();
	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < cols_num; j++) {
			p[i][j] = value;
		}
	}
}

// 拷贝构造函数
Matrix::Matrix(const Matrix& m)
{
	initialize();
	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < cols_num; j++) {
			p[i][j] = m.p[i][j];
		}
	}
}


// 二维数组初始化
Matrix::Matrix(const double m[][LEN])
{
	initialize();
	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < cols_num; j++) {
			p[i][j] = m[i][j];
		}
	}
}

 
//析构函数
Matrix::~Matrix() {
 for (int i = 0; i < rows_num; ++i) {
			delete[] p[i];
		}
		delete[] p;
}
//实现矩阵间的赋值
Matrix& Matrix::operator=(const Matrix& m)
{
	if (this == &m) {
		return *this;
	}
 
 
	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < cols_num; j++) {
			p[i][j] = m.p[i][j];
		}
	}
	return *this;
}
// 实现二维数组向矩阵赋值 事实上没必要，因为当二维数组作为右值时隐式构造出了矩阵类赋给左边的矩阵
Matrix& Matrix::operator=(double *a){
	for(int i=0;i<rows_num;i++){
		for(int j=0;j<cols_num;j++){
			p[i][j]= *(a+i*cols_num+j);
		}
	}
	return *this;
}
//+=操作
Matrix& Matrix::operator+=(const Matrix& m)
{
	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < cols_num; j++) {
			p[i][j] += m.p[i][j];
		}
	}
	return *this;
}
//实现-=
Matrix& Matrix::operator-=(const Matrix& m)
{
	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < cols_num; j++) {
			p[i][j] -= m.p[i][j];
		}
	}
	return *this;
}
//实现*=
Matrix& Matrix::operator*=(const Matrix& m)
{
	Matrix temp(rows_num,m.cols_num,0.0);
	for (int i = 0; i < temp.rows_num; i++) {
		for (int j = 0; j < temp.cols_num; j++) {
			for (int k = 0; k < cols_num; k++) {
				temp.p[i][j] += (p[i][k] * m.p[k][j]);
			}
		}
	}
	*this = temp;
	return *this;
}
//实现矩阵的乘法
Matrix Matrix::operator*(const Matrix & m)const{
	Matrix ba_M(rows_num,m.cols_num,0.0);
	for(int i=0;i<rows_num;i++){
		for(int j=0;j<m.cols_num;j++){
			for(int k=0;k<cols_num;k++){
				ba_M.p[i][j]+=(p[i][k]*m.p[k][j]);
			}
		}
	}
	return ba_M;
}

//实现矩阵的加法
Matrix Matrix::operator+(const Matrix & m)const{
	Matrix ba_M(rows_num,m.cols_num,0.0);
	for(int i=0;i<rows_num;i++){
		for(int j=0;j<m.cols_num;j++){
			
			ba_M.p[i][j] = (p[i][j] + m.p[i][j]);
			
		}
	}
	return ba_M;
}

//实现矩阵的减法
Matrix Matrix::operator-(const Matrix & m)const{
	Matrix ba_M(rows_num,m.cols_num,0.0);
	for(int i=0;i<rows_num;i++){
		for(int j=0;j<m.cols_num;j++){
			
			ba_M.p[i][j] = (p[i][j] - m.p[i][j]);
			
		}
	}
	return ba_M;
}

//实现矩阵的乘方
Matrix Matrix::operator^(const int n)const{
	Matrix ba_M(LEN, LEN, 0.0);
    ba_M = *this;
	for(int i = 0; i < n - 1; i++){
		ba_M *= (*this);
	}
	return ba_M;
}
 

double* Matrix::operator[](int i)
{
	if( i >= LEN )
	{
		cout << "索引超过最大值" <<endl; 
		// 返回第一个元素
		return p[0];
	}
	return p[i];
}
 

//返回矩阵第i行第j列的数
double Matrix::Point(int i, int j) const{
	return this->p[i][j];
}
//求矩阵的逆矩阵
Matrix Matrix::inverse(){

	if(rows_num!=cols_num){
		std::cout<<"只有方阵能求逆矩阵"<<std::endl;
		std::abort();//只有方阵能求逆矩阵
	}
	double temp;
	Matrix A_B=Matrix();
	A_B=*this;//为矩阵A做一个备份
	Matrix B= Matrix();
	//将小于EPS的数全部置0
	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < cols_num; j++) {
			if (abs(p[i][j]) <= EPS) {
				p[i][j] = 0;
			}
		}
	}
	//选择需要互换的两行选主元
	for(int i=0;i<rows_num;i++){
		if(abs(p[i][i])<=EPS){
			bool flag=false;
			for(int j=0;(j<rows_num)&&(!flag);j++){
				if((abs(p[i][j])>EPS)&&(abs(p[j][i])>EPS)){
					flag=true;
					for(int k=0;k<cols_num;k++){
						temp=p[i][k];
						p[i][k]=p[j][k];
						p[j][k]=temp;
						temp=B.p[i][k];
						B.p[i][k]=B.p[j][k];
						B.p[j][k]=temp;
					}
				}
			}
			if(!flag){
				std::cout<<"逆矩阵不存在\n";
				std::abort();
			}
		}
	}
	//通过初等行变换将A变为上三角矩阵
	double temp_rate;
	for(int i=0;i<rows_num;i++){
		for(int j=i+1;j<rows_num;j++){
			temp_rate=p[j][i]/p[i][i];
			for(int k=0;k<cols_num;k++){
				p[j][k]-=p[i][k]*temp_rate;
				B.p[j][k]-=B.p[i][k]*temp_rate;
			}
			p[j][i]=0;
		}
	}
	//使对角元素均为1
	for(int i=0;i<rows_num;i++){
		temp=p[i][i];
		for(int j=0;j<cols_num;j++){
			p[i][j]/=temp;
			B.p[i][j]/=temp;
		}
	}
	//std::cout<<"算法可靠性检测，若可靠，输出上三角矩阵"<<std::endl;
	//将已经变为上三角矩阵的A，变为单位矩阵
	for(int i=rows_num-1;i>=1;i--){
		for(int j=i-1;j>=0;j--){
			temp=p[j][i];
			for(int k=0;k<cols_num;k++){
				p[j][k]-=p[i][k]*temp;
				B.p[j][k]-=B.p[i][k]*temp;
			}
		}
	}

	// std::cout<<"算法可靠性检测，若可靠，输出单位矩阵"<<std::endl;
	// for(int i=0;i<rows_num;i++){
	// 	for(int j=0;j<cols_num;j++){
	// 		printf("%7.4lf\t\t",p[i][j]);
	// 	}
	// 	cout << endl;
	// }

	*this=A_B;//还原A
	return B;//返回该矩阵的逆矩阵
}


//实现矩阵的转置
Matrix Matrix::transpose()
{	
	Matrix mt = Matrix();
	for (int i = 0; i <rows_num; i++) {
		for (int j = 0; j <cols_num; j++) {
			mt.p[j][i] = p[i][j];
		}
	}
	return mt;
}

//实现矩阵的输入
istream& operator>>(istream& is, Matrix& m)
{
	for (int i = 0; i < m.rows_num; i++) {
		for (int j = 0; j < m.cols_num; j++) {
			is >> m.p[i][j];
		}
	}
	return is;
}

//实现矩阵的输出
ostream& operator<<(ostream& os, Matrix& m)
{
	os << '\n';
	for (int i = 0; i < m.rows_num; i++) {
		for (int j = 0; j < m.cols_num; j++) {
			os << std::setw(4) << std::setfill(' ') << m.p[i][j] << " ";
		}
		os << "\n";
	}
	return os;
}
 
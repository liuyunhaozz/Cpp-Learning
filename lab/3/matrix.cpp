#include <cmath>
#include <iostream>
using namespace std;

 
class Matrix {
    private:
        int rows_num = 0;
        int cols_num = 0;
        double **p = nullptr;
        void initialize();   // 动态分配一块内存空间
        bool error = false;  // 当矩阵的运算不符合规则时，不能输出
    public:
        Matrix() = default;
        Matrix(int, int, double);   // 生成值全为value的矩阵
        Matrix(int, int);           // 预分配空间,为输入 >> 做准备
        bool isError();
        virtual ~Matrix();          // 析构函数应当是虚函数，除非此类不用做基类
        Matrix& operator=(const Matrix&);      // 矩阵的复制, 注意要为第一个矩阵重新分配空间
        Matrix& operator+=(const Matrix&);     // 矩阵的+=操作
        Matrix& operator*=(const Matrix&);
        double operator()(int i, int j);	   // 重载()运算符
        friend istream& operator>>(istream&, Matrix&);    // 实现矩阵的输入
        friend ostream& operator<<(ostream&, Matrix&);    // 实现矩阵的输出
};

bool Matrix::isError() {
    if (error) {
        error = false;
        return true;
    }
    else
        return false;
}
 
// 动态分配内存空间
void Matrix::initialize() {             // 初始化矩阵大小
    p = new double*[rows_num];          // 分配rows_num个指针
    for (int i = 0; i < rows_num; ++i) {
        p[i] = new double[cols_num];    // 为p[i]进行动态内存分配，大小为cols
    }
}

Matrix::Matrix(int rows, int cols) {
    rows_num = rows;
    cols_num = cols;
    initialize();
}

// 初始化一个值全部为value的矩阵
Matrix::Matrix(int rows, int cols, double value) {
	rows_num = rows;
	cols_num = cols;
	initialize();
	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < cols_num; j++) {
			p[i][j] = value;
		}
	}
}


// 实现矩阵间的赋值
Matrix& Matrix::operator=(const Matrix& m) {
    // 先销毁掉原来的内存空间，再 new 一块新的内存，以匹配 m 的大小
    for (int i = 0; i < rows_num; ++i) {
		delete[] p[i];
	}
	delete[] p;
    rows_num = m.rows_num;
    cols_num = m.cols_num;
    initialize();
	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < cols_num; j++) {
			p[i][j] = m.p[i][j];
		}
	}
	return *this;
}

// 析构函数
Matrix::~Matrix() {
    for (int i = 0; i < rows_num; ++i) {
		delete[] p[i];
	}
	delete[] p;
}


// 实现矩阵的输入
istream& operator>>(istream& is, Matrix& m)
{
	for (int i = 0; i < m.rows_num; i++) {
		for (int j = 0; j < m.cols_num; j++) {
			is >> m.p[i][j];
		}
	}
	return is;
}

// 实现矩阵的输出
ostream& operator<<(ostream& os, Matrix& m) {
	for (int i = 0; i < m.rows_num; i++) {
		for (int j = 0; j < m.cols_num; j++) {
			os << m.p[i][j] << " ";
		}
		os << endl;
	}
	return os;
}

double Matrix::operator()(int i, int j) {
	if(i >= rows_num || j >= cols_num) {
		cout << "ERROR!" << endl; 
        error = true;
		return -1;
	}
	return p[i][j];
}

Matrix& Matrix::operator+=(const Matrix& m) {
    if (rows_num != m.rows_num || cols_num != m.cols_num) {
        cout << "ERROR!" << endl;
        error = true;
        // 返回自己
        return *this;
    }
	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < cols_num; j++) {
			p[i][j] += m.p[i][j];
		}
	}
	return *this;
}

Matrix& Matrix::operator*=(const Matrix& m) {
    if (cols_num != m.rows_num) {
        cout << "ERROR!" << endl;
        error = true;
        // 返回自己
        return *this;
    }
	Matrix temp(rows_num, m.cols_num, 0.0);
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

int main()
{
    int rol1, col1;
    int rol2, col2;

    cin >> rol1 >> col1;
    Matrix table1(rol1, col1);
    cin >> table1;
    
    cin >> rol2 >> col2;
    Matrix table2(rol2, col2);
    cin >> table2;
    
    cout << table1(rol1 / 2, col1 / 2) << endl;

    table1 *= table2;
    if (!table1.isError())
        cout << table1;

    table1 += table2;
    if (!table1.isError()) {
        cout << table1;
    }

    cout << (table1 = table2);
 
}







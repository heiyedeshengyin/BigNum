# BigNum
大整数类的运算,高精度计算

### 简介
到目前为止写的最长的代码  
高精度计算，指超大位数的大整数之间的运算

### 数据结构
```cpp
class bignum
{
	int* num;	//存储大整数的数组,采用倒序存储
	int length;	//大整数的位数
	bool is_positive;	//大整数的符号,true为正,false为负,注意:0为正数
};
```

### 重载的运算符
双目算术运算符： + (加)，-(减)，*(乘)，/(除)，% (取模)  
关系运算符： ==(等于)，!= (不等于)，< (小于)，> (大于>，<=(小于等于)，>=(大于等于)  
自增自减运算符：++(自增)，--(自减)  
赋值运算符：=, +=, -=, *=, /= , %=  

### 函数列表
bignum();	//无参构造函数  
bignum(const char* str);	//用字符串来构造大整数  
bignum(int _num);	//用int类型来构造大整数  
bignum(unsigned long _num);	//用usigned long类型来构造大整数  
bignum(long long _num);	//用long long类型来构造大整数  
bignum(const bignum& ano);	//拷贝构造函数  
~bignum();	//析构函数  
bool isPositive();	//返回大整数的符号  
bool isZero();	//判断大整数是否为零  
int getLength();	//返回大整数的位数  
int* getArray();	//返回存储大整数的数组  
void show();	//打印大整数  
bignum abs();	//返回大整数的绝对值  
bignum& operator=(const bignum& copy_num);	//重载=运算符  
bool operator==(const bignum& compare_num);	//重载==运算符  
bool operator!=(const bignum& compare_num);	//重载!=运算符  
bool operator>(const bignum& compare_num);	//重载>运算符  
bool operator<(const bignum& compare_num);	//重载<运算符  
bool operator>=(const bignum& compare_num);	//重载>=运算符  
bool operator<=(const bignum& compare_num);	//重载<=运算符  
bignum operator+(const bignum& add_num);	//重载+运算符  
bignum operator-(const bignum& sub_num);	//重载-运算符  
bignum operator*(const bignum& mul_num);	//重载\*运算符  
bignum operator/(const bignum& div_num);	//重载/运算符  
bignum operator%(const bignum& div_num);	//重载%运算符  
bignum operator+=(const bignum& add_num);	//重载+=运算符  
bignum operator-=(const bignum& sub_num);	//重载-=运算符  
bignum operator*=(const bignum& mul_num);	//重载*=运算符  
bignum operator/=(const bignum& div_num);	//重载/=运算符  
bignum operator%=(const bignum& div_num);	//重载%=运算符  
bignum operator++();	//重载+\+前缀运算符  
bignum operator++(int);	//重载++后缀运算符  
bignum operator--();	//重载--前缀运算符  
bignum operator--(int);	//重载--后缀运算符  
friend int bignumToInt(const bignum& _num);	//大整数转int类型  
bignum fac(int r);	//求阶乘  
int SubStract(int* p1, int* p2, int len1, int len2);	//数组之间的减法  
ostream& operator<<(ostream& os, bignum num);	//重载<<运算符  

### 使用说明
下载解压后，用Visual Studio打开BigNum.sln即可

### 参考资料
[CSDN C++实现高精度大整数（大数）的四则运算](https://blog.csdn.net/weifenglin1997/article/details/78748998)
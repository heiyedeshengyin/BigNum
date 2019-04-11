/*
	Copyright 2019 heiyedeshengyin All Rights Reserved.

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/
#pragma once

#ifndef BIGNUM_H
#define BIGNUM_H
#include <iostream>
#include <cstring>
using namespace std;

/*大整数*/
class bignum
{
private:
	int* num;	//存储大整数的数组,采用倒序存储
	int length;	//大整数的位数
	bool is_positive;	//大整数的符号,true为正,false为负,注意:0为正数
public:
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
	bignum operator*(const bignum& mul_num);	//重载*运算符
	bignum operator/(const bignum& div_num);	//重载/运算符
	bignum operator%(const bignum& div_num);	//重载%运算符
	bignum operator+=(const bignum& add_num);	//重载+=运算符
	bignum operator-=(const bignum& sub_num);	//重载-=运算符
	bignum operator*=(const bignum& mul_num);	//重载*=运算符
	bignum operator/=(const bignum& div_num);	//重载/=运算符
	bignum operator%=(const bignum& div_num);	//重载%=运算符
	bignum operator++();	//重载++前缀运算符
	bignum operator++(int);	//重载++后缀运算符
	bignum operator--();	//重载--前缀运算符
	bignum operator--(int);	//重载--后缀运算符
	friend int bignumToInt(const bignum& _num);	//大整数转int类型
};
bignum fac(int r);	//求阶乘
int SubStract(int* p1, int* p2, int len1, int len2);	//数组之间的减法
ostream& operator<<(ostream& os, bignum num);	//重载<<运算符

#endif // !BIGNUM_H

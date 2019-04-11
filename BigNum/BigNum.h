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

/*������*/
class bignum
{
private:
	int* num;	//�洢������������,���õ���洢
	int length;	//��������λ��
	bool is_positive;	//�������ķ���,trueΪ��,falseΪ��,ע��:0Ϊ����
public:
	bignum();	//�޲ι��캯��
	bignum(const char* str);	//���ַ��������������
	bignum(int _num);	//��int���������������
	bignum(unsigned long _num);	//��usigned long���������������
	bignum(long long _num);	//��long long���������������
	bignum(const bignum& ano);	//�������캯��
	~bignum();	//��������
	bool isPositive();	//���ش������ķ���
	bool isZero();	//�жϴ������Ƿ�Ϊ��
	int getLength();	//���ش�������λ��
	int* getArray();	//���ش洢������������
	void show();	//��ӡ������
	bignum abs();	//���ش������ľ���ֵ
	bignum& operator=(const bignum& copy_num);	//����=�����
	bool operator==(const bignum& compare_num);	//����==�����
	bool operator!=(const bignum& compare_num);	//����!=�����
	bool operator>(const bignum& compare_num);	//����>�����
	bool operator<(const bignum& compare_num);	//����<�����
	bool operator>=(const bignum& compare_num);	//����>=�����
	bool operator<=(const bignum& compare_num);	//����<=�����
	bignum operator+(const bignum& add_num);	//����+�����
	bignum operator-(const bignum& sub_num);	//����-�����
	bignum operator*(const bignum& mul_num);	//����*�����
	bignum operator/(const bignum& div_num);	//����/�����
	bignum operator%(const bignum& div_num);	//����%�����
	bignum operator+=(const bignum& add_num);	//����+=�����
	bignum operator-=(const bignum& sub_num);	//����-=�����
	bignum operator*=(const bignum& mul_num);	//����*=�����
	bignum operator/=(const bignum& div_num);	//����/=�����
	bignum operator%=(const bignum& div_num);	//����%=�����
	bignum operator++();	//����++ǰ׺�����
	bignum operator++(int);	//����++��׺�����
	bignum operator--();	//����--ǰ׺�����
	bignum operator--(int);	//����--��׺�����
	friend int bignumToInt(const bignum& _num);	//������תint����
};
bignum fac(int r);	//��׳�
int SubStract(int* p1, int* p2, int len1, int len2);	//����֮��ļ���
ostream& operator<<(ostream& os, bignum num);	//����<<�����

#endif // !BIGNUM_H

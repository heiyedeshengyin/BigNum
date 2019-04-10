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

class bignum
{
private:
	int* num;
	int length;
	bool is_positive;
public:
	bignum();
	bignum(const char* str);
	bignum(int _num);
	bignum(unsigned long _num);
	bignum(long long _num);
	bignum(const bignum& ano);
	~bignum();
	bool isPositive();
	bool isZero();
	int getLength();
	void show();
	bignum abs();
	bignum& operator=(const bignum& copy_num);
	bool operator==(const bignum& compare_num);
	bool operator!=(const bignum& compare_num);
	bool operator>(const bignum& compare_num);
	bool operator<(const bignum& compare_num);
	bool operator>=(const bignum& compare_num);
	bool operator<=(const bignum& compare_num);
	bignum operator+(const bignum& add_num);
	bignum operator-(const bignum& sub_num);
};



#endif // !BIGNUM_H

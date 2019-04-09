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

bignum::bignum()
{
	num = new int[1];
	num[0] = 0;
	length = 1;
	is_positive = true;
}

bignum::bignum(const char* str)
{
	int zero_count = 0;
	int str_length = strlen(str);

	if (str_length == 0)
	{
		cout << "构造函数错误:字符串不能为空" << endl;
		num = new int[1];
		num[0] = 0;
		length = 1;
		is_positive = true;
	}

	else if (str_length == 1)
		if (str[0] < '0' || str[0] > '9')
		{
			cout << "构造函数错误:非法字符串" << endl;
			num = new int[1];
			num[0] = 0;
			length = 1;
			is_positive = true;
		}
		else
		{
			num = new int[1];
			num[0] = str[0] - '0';
			length = 1;
			is_positive = true;
		}

	else
		if (str[0] == '+' || str[0] == '-')
		{
			for (int i = 1; i < str_length; i++)
				if (str[i] == '0')
					zero_count++;
				else
					break;

			length = str_length - zero_count - 1;
			if (length == 0)
			{
				cout << "构造函数错误,字符串不能都是0" << endl;
				num = new int[1];
				num[0] = 0;
				length = 1;
				is_positive = true;
			}
			else
			{
				num = new int[length];
				if (str[0] == '+')
					is_positive = true;
				else
					is_positive = false;

				for (int i = str_length - 1; i >= zero_count + 1; i--)
					if (str[i] < '0' || str[i] > '9')
					{
						cout << "构造函数错误:非法字符串" << endl;
						delete num;
						num = new int[1];
						num[0] = 0;
						length = 1;
						is_positive = true;
						break;
					}
					else
						num[str_length - 1 - i] = str[i] - '0';
			}
		}
		else
		{
			for (int i = 0; i < str_length; i++)
				if (str[i] == '0')
					zero_count++;
				else
					break;

			length = str_length - zero_count;
			if (length == 0)
			{
				cout << "构造函数错误,字符串不能都是0" << endl;
				num = new int[1];
				num[0] = 0;
				length = 1;
				is_positive = true;
			}
			else
			{
				num = new int[length];
				is_positive = true;

				for (int i = str_length - 1; i >= zero_count; i--)
					if (str[i] < '0' || str[i] > '9')
					{
						cout << "构造函数错误:非法字符串" << endl;
						delete num;
						num = new int[1];
						num[0] = 0;
						length = 1;
						is_positive = true;
						break;
					}
					else
						num[str_length - 1 - i] = str[i] - '0';
			}
		}
}

bignum::bignum(int _num)
{
	if (_num < -2147483647 || _num > 2147483647)
	{
		cout << "构造函数异常,int类型参数超出范围" << endl;
		num = new int[1];
		num[0] = 0;
		length = 1;
		is_positive = true;

	}
	else
	{
		int m_num = _num;
		int n_num = _num;
		int m_length = 0;

		if (m_num < 0)
		{
			m_num = 0 - m_num;
			n_num = 0 - n_num;
			is_positive = false;
		}
		else
		{
			is_positive = true;
		}

		while (m_num > 0)
		{
			m_length++;
			m_num /= 10;
		}

		if (m_length == 0)
		{
			num = new int[1];
			num[0] = 0;
			length = 1;
		}
		else
		{
			num = new int[m_length];
			length = m_length;
			for (int i = 0; i < length; i++)
			{
				num[i] = n_num % 10;
				n_num /= 10;
			}
		}
	}
}

bignum::bignum(unsigned long _num)
{
	unsigned long m_num = _num;
	unsigned long n_num = _num;
	int m_length = 0;

	if (m_num < 0)
	{
		m_num = 0 - m_num;
		n_num = 0 - n_num;
		is_positive = false;
	}
	else
	{
		is_positive = true;
	}

	while (m_num > 0)
	{
		m_length++;
		m_num /= 10;
	}

	if (m_length == 0)
	{
		num = new int[1];
		num[0] = 0;
		length = 1;
	}
	else
	{
		num = new int[m_length];
		length = m_length;
		for (int i = 0; i < length; i++)
		{
			num[i] = n_num % 10;
			n_num /= 10;
		}
	}
}

bignum::bignum(long long _num)
{
	long long m_num = _num;
	long long n_num = _num;
	int m_length = 0;

	if (m_num < 0)
	{
		m_num = 0 - m_num;
		n_num = 0 - n_num;
		is_positive = false;
	}
	else
	{
		is_positive = true;
	}

	while (m_num > 0)
	{
		m_length++;
		m_num /= 10;
	}

	if (m_length == 0)
	{
		num = new int[1];
		num[0] = 0;
		length = 1;
	}
	else
	{
		num = new int[m_length];
		length = m_length;
		for (int i = 0; i < length; i++)
		{
			num[i] = n_num % 10;
			n_num /= 10;
		}
	}
}

bignum::bignum(const bignum& ano)
{
	length = ano.length;
	is_positive = ano.is_positive;

	num = new int[length];
	for (int i = 0; i < length; i++)
		num[i] = ano.num[i];
}

bignum::~bignum()
{
	delete num;
}

bool bignum::isPositive()
{
	return is_positive;
}

bool bignum::isZero()
{
	return length == 1 && num[0] == 0;
}

int bignum::getLength()
{
	return length;
}

void bignum::show()
{
	if (!is_positive)
		cout << "-";

	for (int i = length - 1; i >= 0; i--)
		cout << num[i];

	cout << endl;
}

bignum& bignum::operator=(const bignum& copy_num)
{
	if (this == &copy_num)
		return *this;

	length = copy_num.length;
	is_positive = copy_num.is_positive;
	delete num;
	num = new int[length];
	for (int i = 0; i < length; i++)
		num[i] = copy_num.num[i];

	return *this;
}

bool bignum::operator==(const bignum& compare_num)
{
	if (length != compare_num.length || is_positive != compare_num.is_positive)
		return false;
	else
	{
		for (int i = 0; i < length; i++)
			if (num[i] != compare_num.num[i])
				return false;

		return true;
	}
}

bool bignum::operator!=(const bignum& compare_num)
{
	if (length != compare_num.length || is_positive != compare_num.is_positive)
		return true;
	else
	{
		for (int i = 0; i < length; i++)
			if (num[i] != compare_num.num[i])
				return true;

		return false;
	}
}

bool bignum::operator>(const bignum& compare_num)
{
	if (is_positive && !compare_num.is_positive)
		return true;

	if (!is_positive && compare_num.is_positive)
		return false;

	if (is_positive && compare_num.is_positive)
	{
		if (length > compare_num.length)
			return true;
		if (length < compare_num.length)
			return false;
		if (length == compare_num.length)
		{
			for (int i = length - 1; i >= 0; i--)
			{
				if (num[i] > compare_num.num[i])
					return true;
				if (num[i] < compare_num.num[i])
					return false;
			}
			return false;
		}
	}

	if (!is_positive && !compare_num.is_positive)
	{
		if (length > compare_num.length)
			return false;
		if (length < compare_num.length)
			return true;
		if (length == compare_num.length)
		{
			for (int i = length - 1; i >= 0; i--)
			{
				if (num[i] > compare_num.num[i])
					return false;
				if (num[i] < compare_num.num[i])
					return true;
			}
			return false;
		}
	}
}

bool bignum::operator<(const bignum& compare_num)
{
	if (is_positive && !compare_num.is_positive)
		return false;

	if (!is_positive && compare_num.is_positive)
		return true;

	if (is_positive && compare_num.is_positive)
	{
		if (length > compare_num.length)
			return false;
		if (length < compare_num.length)
			return true;
		if (length == compare_num.length)
		{
			for (int i = length - 1; i >= 0; i--)
			{
				if (num[i] > compare_num.num[i])
					return false;
				if (num[i] < compare_num.num[i])
					return true;
			}
			return false;
		}
	}

	if (!is_positive && !compare_num.is_positive)
	{
		if (length > compare_num.length)
			return true;
		if (length < compare_num.length)
			return false;
		if (length == compare_num.length)
		{
			for (int i = length - 1; i >= 0; i--)
			{
				if (num[i] > compare_num.num[i])
					return true;
				if (num[i] < compare_num.num[i])
					return false;
			}
			return false;
		}
	}
}

bool bignum::operator>=(const bignum& compare_num)
{
	if (is_positive && !compare_num.is_positive)
		return true;

	if (!is_positive && compare_num.is_positive)
		return false;

	if (is_positive && compare_num.is_positive)
	{
		if (length > compare_num.length)
			return true;
		if (length < compare_num.length)
			return false;
		if (length == compare_num.length)
		{
			for (int i = length - 1; i >= 0; i--)
			{
				if (num[i] > compare_num.num[i])
					return true;
				if (num[i] < compare_num.num[i])
					return false;
			}
			return true;
		}
	}

	if (!is_positive && !compare_num.is_positive)
	{
		if (length > compare_num.length)
			return false;
		if (length < compare_num.length)
			return true;
		if (length == compare_num.length)
		{
			for (int i = length - 1; i >= 0; i--)
			{
				if (num[i] > compare_num.num[i])
					return false;
				if (num[i] < compare_num.num[i])
					return true;
			}
			return true;
		}
	}
}

bool bignum::operator<=(const bignum& compare_num)
{
	if (is_positive && !compare_num.is_positive)
		return false;

	if (!is_positive && compare_num.is_positive)
		return true;

	if (is_positive && compare_num.is_positive)
	{
		if (length > compare_num.length)
			return false;
		if (length < compare_num.length)
			return true;
		if (length == compare_num.length)
		{
			for (int i = length - 1; i >= 0; i--)
			{
				if (num[i] > compare_num.num[i])
					return false;
				if (num[i] < compare_num.num[i])
					return true;
			}
			return true;
		}
	}

	if (!is_positive && !compare_num.is_positive)
	{
		if (length > compare_num.length)
			return true;
		if (length < compare_num.length)
			return false;
		if (length == compare_num.length)
		{
			for (int i = length - 1; i >= 0; i--)
			{
				if (num[i] > compare_num.num[i])
					return true;
				if (num[i] < compare_num.num[i])
					return false;
			}
			return true;
		}
	}
}

bignum bignum::operator+(const bignum& add_num)
{
	bignum result;

	if (is_positive && add_num.is_positive || !is_positive && !add_num.is_positive)
	{
		int carry = 0;
		int result_index = 0;
		int temp = 0;
		int* added_num;
		int* _add_num;
		int* result_num;
		added_num = new int[length + add_num.length];
		_add_num = new int[length + add_num.length];
		result_num = new int[length + add_num.length];
		for (int i = 0; i < length + add_num.length; i++)
		{
			if (i < length)
				added_num[i] = num[i];
			else
				added_num[i] = 0;

			if (i < add_num.length)
				_add_num[i] = add_num.num[i];
			else
				_add_num[i] = 0;

			result_num[i] = 0;
		}
		for (int i = 0; i < length || i < add_num.length; i++)
		{
			temp = added_num[i] + _add_num[i] + carry;
			result_num[result_index] = temp % 10;
			result_index++;
			carry = temp / 10;
		}
		if (carry != 0)
		{
			result_num[result_index] = carry;
			result_index++;
		}

		delete result.num;
		result.num = new int[result_index];
		result.length = result_index;
		for (int i = 0; i < result_index; i++)
			result.num[i] = result_num[i];

		if (is_positive && add_num.is_positive)
		{
			result.is_positive = true;
			return result;
		}
		else if (!is_positive && !add_num.is_positive)
		{
			result.is_positive = false;
			return result;
		}
	}
	else
	{
		cout << "目前只能进行正数与正数的加法和负数与负数的加法" << endl;
		return result;
	}
}

bignum bignum::operator-(const bignum& sub_num)
{
	bignum result;

	if (is_positive && sub_num.is_positive)
	{
		if (*this == sub_num)
			return result;
		else if(*this > sub_num)
		{
			int result_index = 0;
			int* subed_num;
			int* _sub_num;
			int* result_num;
			subed_num = new int[length + sub_num.length];
			_sub_num = new int[length + sub_num.length];
			result_num = new int[length + sub_num.length];
			for (int i = 0; i < length + sub_num.length; i++)
			{
				if (i < length)
					subed_num[i] = num[i];
				else
					subed_num[i] = 0;

				if (i < sub_num.length)
					_sub_num[i] = sub_num.num[i];
				else
					_sub_num[i] = 0;

				result_num[i] = 0;
			}

			for (int i = 0; i < length || i < sub_num.length; i++)
			{
				if (subed_num[i] < _sub_num[i])
					if (subed_num[i + 1] > 0)
					{
						subed_num[i + 1]--;
						subed_num[i] += 10;
					}
				result_num[result_index] = subed_num[i] - _sub_num[i];
				result_index++;
			}
			while (result_index - 1 >= 1 && result_num[result_index - 1] == 0)
				result_index--;

			result.length = result_index;
			result.is_positive = true;
			delete result.num;
			result.num = new int[result.length];
			for (int i = 0; i < result_index; i++)
				result.num[i] = result_num[i];

			return result;
		}
		else
		{
			int result_index = 0;
			int* subed_num;
			int* _sub_num;
			int* result_num;
			subed_num = new int[length + sub_num.length];
			_sub_num = new int[length + sub_num.length];
			result_num = new int[length + sub_num.length];
			for (int i = 0; i < length + sub_num.length; i++)
			{
				if (i < sub_num.length)
					subed_num[i] = sub_num.num[i];
				else
					subed_num[i] = 0;

				if (i < length)
					_sub_num[i] = num[i];
				else
					_sub_num[i] = 0;

				result_num[i] = 0;
			}

			for (int i = 0; i < length || i < sub_num.length; i++)
			{
				if (subed_num[i] < _sub_num[i])
					if (subed_num[i + 1] > 0)
					{
						subed_num[i + 1]--;
						subed_num[i] += 10;
					}
				result_num[result_index] = subed_num[i] - _sub_num[i];
				result_index++;
			}
			while (result_index - 1 >= 1 && result_num[result_index - 1] == 0)
				result_index--;

			result.length = result_index;
			result.is_positive = false;
			delete result.num;
			result.num = new int[result.length];
			for (int i = 0; i < result_index; i++)
				result.num[i] = result_num[i];

			return result;
		}
	}
	else if (!is_positive && !sub_num.is_positive)
	{
		if (*this == sub_num)
			return result;
		else if(*this > sub_num)
		{
			int result_index = 0;
			int* subed_num;
			int* _sub_num;
			int* result_num;
			subed_num = new int[length + sub_num.length];
			_sub_num = new int[length + sub_num.length];
			result_num = new int[length + sub_num.length];
			for (int i = 0; i < length + sub_num.length; i++)
			{
				if (i < sub_num.length)
					subed_num[i] = sub_num.num[i];
				else
					subed_num[i] = 0;

				if (i < length)
					_sub_num[i] = num[i];
				else
					_sub_num[i] = 0;

				result_num[i] = 0;
			}

			for (int i = 0; i < length || i < sub_num.length; i++)
			{
				if (subed_num[i] < _sub_num[i])
					if (subed_num[i + 1] > 0)
					{
						subed_num[i + 1]--;
						subed_num[i] += 10;
					}
				result_num[result_index] = subed_num[i] - _sub_num[i];
				result_index++;
			}
			while (result_index - 1 >= 1 && result_num[result_index - 1] == 0)
				result_index--;

			result.length = result_index;
			result.is_positive = true;
			delete result.num;
			result.num = new int[result.length];
			for (int i = 0; i < result_index; i++)
				result.num[i] = result_num[i];

			return result;
		}
		else
		{
			int result_index = 0;
			int* subed_num;
			int* _sub_num;
			int* result_num;
			subed_num = new int[length + sub_num.length];
			_sub_num = new int[length + sub_num.length];
			result_num = new int[length + sub_num.length];
			for (int i = 0; i < length + sub_num.length; i++)
			{
				if (i < length)
					subed_num[i] = num[i];
				else
					subed_num[i] = 0;

				if (i < sub_num.length)
					_sub_num[i] = sub_num.num[i];
				else
					_sub_num[i] = 0;

				result_num[i] = 0;
			}

			for (int i = 0; i < length || i < sub_num.length; i++)
			{
				if (subed_num[i] < _sub_num[i])
					if (subed_num[i + 1] > 0)
					{
						subed_num[i + 1]--;
						subed_num[i] += 10;
					}
				result_num[result_index] = subed_num[i] - _sub_num[i];
				result_index++;
			}
			while (result_index - 1 >= 1 && result_num[result_index - 1] == 0)
				result_index--;

			result.length = result_index;
			result.is_positive = false;
			delete result.num;
			result.num = new int[result.length];
			for (int i = 0; i < result_index; i++)
				result.num[i] = result_num[i];

			return result;
		}
	}
	else
	{
		cout << "正数与负数的减法尚未做成" << endl;
		return result;
	}
}

#endif // !BIGNUM_H

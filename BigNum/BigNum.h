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
	delete[] num;
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

#endif // !BIGNUM_H

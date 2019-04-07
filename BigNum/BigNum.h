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
	bignum(const bignum& ano);
	~bignum();
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
				num = new int[1];
				num[0] = 0;
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
				num = new int[1];
				num[0] = 0;
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

#endif // !BIGNUM_H

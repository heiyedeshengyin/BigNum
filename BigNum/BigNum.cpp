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

   @file BigNum.cpp
   @brief 大整数的相关函数的实现
   @author heiyedeshengyin
   @date 2019.4.12 12:49:32
   @license Apache License, Version 2.0
*/

#include "BigNum.h";

/*
	无参构造函数
	默认赋值零
*/
bignum::bignum()
{
	num = new int[1];
	num[0] = 0;
	length = 1;
	is_positive = true;
}

/*
	用字符串来构造大整数
	注意字符串必须是整数的形式,允许带'+','-'在字符串首位

	@param[in] const char* str:传入的字符串
*/
bignum::bignum(const char* str)
{
	int zero_count = 0;	//字符串开头零的个数,这些零将被去掉
	int str_length = strlen(str);	//字符串的字符个数

	if (str_length == 0)	//字符串为空的情况
	{
		cout << "构造函数错误:字符串不能为空" << endl;
		num = new int[1];
		num[0] = 0;
		length = 1;
		is_positive = true;
	}

	else if (str_length == 1)	//字符串只有一个字符的情况
		if (str[0] < '0' || str[0] > '9')	//判断字符是否为数字
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

	else  //字符串开头为正负号的情况
		if (str[0] == '+' || str[0] == '-')
		{
			for (int i = 1; i < str_length; i++)	//记录字符串开头零的个数
				if (str[i] == '0')
					zero_count++;
				else
					break;

			length = str_length - zero_count - 1;
			if (length == 0)	//字符串全是零的情况
			{
				cout << "构造函数错误,字符串不能都是0" << endl;
				num = new int[1];
				num[0] = 0;
				length = 1;
				is_positive = true;
			}
			else  //字符串并不是全为零的情况
			{
				if (zero_count > 0)
					cout << "构造函数:已自动将前面的0去除" << endl;

				num = new int[length];
				if (str[0] == '+')	//根据字符串开头的符号来判断大整数的正负
					is_positive = true;
				else
					is_positive = false;

				for (int i = str_length - 1; i >= zero_count + 1; i--)
					if (str[i] < '0' || str[i] > '9')	//依次判断字符串的每个字符是否为数字
					{
						//如果不是数字,直接跳出循环并给大整数赋值为零
						cout << "构造函数错误:非法字符串" << endl;
						delete num;
						num = new int[1];
						num[0] = 0;
						length = 1;
						is_positive = true;
						break;
					}
					else
						num[str_length - 1 - i] = str[i] - '0';	//如果是数字,就倒序赋值并继续循环
			}
		}
		else  //字符串开头没有正负号的情况
		{
			for (int i = 0; i < str_length; i++)	//记录字符串开头零的个数
				if (str[i] == '0')
					zero_count++;
				else
					break;

			length = str_length - zero_count;
			if (length == 0)	//字符串全是零的情况
			{
				cout << "构造函数错误,字符串不能都是0" << endl;
				num = new int[1];
				num[0] = 0;
				length = 1;
				is_positive = true;
			}
			else  //字符串并不是全为零的情况
			{
				if (zero_count > 0)
					cout << "构造函数:已自动将前面的0去除" << endl;

				num = new int[length];
				is_positive = true;	//因为字符串开头没有符号,大整数默认为正数

				for (int i = str_length - 1; i >= zero_count; i--)
					if (str[i] < '0' || str[i] > '9')	//依次判断字符串的每个字符是否为数字
					{
						//如果不是数字,直接跳出循环并给大整数赋值为零
						cout << "构造函数错误:非法字符串" << endl;
						delete num;
						num = new int[1];
						num[0] = 0;
						length = 1;
						is_positive = true;
						break;
					}
					else
						num[str_length - 1 - i] = str[i] - '0';	//如果是数字,就倒序赋值并继续循环
			}
		}
}

/*
	用int类型来构造大整数

	@param[in] int _num:传入的int类型数
*/
bignum::bignum(int _num)
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

/*
	用usigned long类型来构造大整数

	@param[in] unsigned long _num:传入的usigned long类型数
*/
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

/*
	用long long类型来构造大整数

	@param[in] long long _num:传入的long long类型数
*/
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

/*
	拷贝构造函数

	@param[in] const bignum& ano:被拷贝的大整数
*/
bignum::bignum(const bignum& ano)
{
	length = ano.length;
	is_positive = ano.is_positive;

	num = new int[length];
	for (int i = 0; i < length; i++)
		num[i] = ano.num[i];
}

/*
	析构函数
*/
bignum::~bignum()
{
	delete num;
}

/*
	返回大整数的符号
	
	@return bool:true为正,false为负,注意:0为正数
*/
bool bignum::isPositive()
{
	return is_positive;
}

/*
	判断大整数是否为零

	@return bool:true为零,反之不为
*/
bool bignum::isZero()
{
	return length == 1 && num[0] == 0;
}

/*
	返回大整数的位数

	@return int:大整数的位数
*/
int bignum::getLength()
{
	return length;
}

/*
	返回存储大整数的数组
	采用倒序存储

	@return int*:存储大整数的数组
*/
int* bignum::getArray()
{
	int* result;
	result = new int[length];
	for (int i = 0; i < length; i++)
		result[i] = num[i];
	return result;
}

/*
	打印大整数

	@return void
*/
void bignum::show()
{
	if (!is_positive)
		cout << "-";

	for (int i = length - 1; i >= 0; i--)
		cout << num[i];

	cout << endl;
}

/*
	返回大整数的绝对值
	注意:调用此函数的大整数不受影响

	@return bignum
*/
bignum bignum::abs()
{
	bignum result;

	result.length = length;
	delete result.num;
	result.num = new int[length];
	for (int i = 0; i < length; i++)
		result.num[i] = num[i];
	result.is_positive = true;

	return result;
}

/*
	重载=运算符

	@param[in] const bignum& copy_num:赋值的大整数

	@return bignum&:被赋值的大整数
*/
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

/*
	重载==运算符

	@param[in] const bignum& compare_num:与之比较的大整数

	@return bool
*/
bool bignum::operator==(const bignum& compare_num)
{
	if (length != compare_num.length || is_positive != compare_num.is_positive)	//首先比较符号
		return false;
	else  //然后依次比较每一个数
	{
		for (int i = 0; i < length; i++)
			if (num[i] != compare_num.num[i])
				return false;

		return true;
	}
}

/*
	重载!=运算符
	
	@param[in] const bignum& compare_num:与之比较的大整数

	@return bool
*/
bool bignum::operator!=(const bignum& compare_num)
{
	if (length != compare_num.length || is_positive != compare_num.is_positive)	//首先比较符号
		return true;
	else  //然后依次比较每一个数
	{
		for (int i = 0; i < length; i++)
			if (num[i] != compare_num.num[i])
				return true;

		return false;
	}
}

/*
	重载>运算符

	@param[in] const bignum& compare_num:与之比较的大整数

	@return bool
*/
bool bignum::operator>(const bignum& compare_num)
{
	//首先比较两者符号,若符号不同,直接判断
	if (is_positive && !compare_num.is_positive)
		return true;

	if (!is_positive && compare_num.is_positive)
		return false;

	//若符号相同,则需要进一步判断
	if (is_positive && compare_num.is_positive)
	{
		//先比较两者长度
		if (length > compare_num.length)
			return true;
		if (length < compare_num.length)
			return false;
		if (length == compare_num.length)
		{
			//若长度相同,则从高位开始每一位比较
			for (int i = length - 1; i >= 0; i--)
			{
				if (num[i] > compare_num.num[i])
					return true;
				if (num[i] < compare_num.num[i])
					return false;
			}
			//两者完全相等的情况
			return false;
		}
	}

	if (!is_positive && !compare_num.is_positive)
	{
		//先比较两者长度
		if (length > compare_num.length)
			return false;
		if (length < compare_num.length)
			return true;
		if (length == compare_num.length)
		{
			//若长度相同,则从高位开始每一位比较
			for (int i = length - 1; i >= 0; i--)
			{
				if (num[i] > compare_num.num[i])
					return false;
				if (num[i] < compare_num.num[i])
					return true;
			}
			//两者完全相等的情况
			return false;
		}
	}
}

/*
	重载<运算符

	@param[in] const bignum& compare_num:与之比较的大整数

	@return bool
*/
bool bignum::operator<(const bignum& compare_num)
{
	//首先比较两者符号,若符号不同,直接判断
	if (is_positive && !compare_num.is_positive)
		return false;

	if (!is_positive && compare_num.is_positive)
		return true;

	//若符号相同,则需要进一步判断
	if (is_positive && compare_num.is_positive)
	{
		//先比较两者长度
		if (length > compare_num.length)
			return false;
		if (length < compare_num.length)
			return true;
		if (length == compare_num.length)
		{
			//若长度相同,则从高位开始每一位比较
			for (int i = length - 1; i >= 0; i--)
			{
				if (num[i] > compare_num.num[i])
					return false;
				if (num[i] < compare_num.num[i])
					return true;
			}
			//两者完全相等的情况
			return false;
		}
	}

	if (!is_positive && !compare_num.is_positive)
	{
		//先比较两者长度
		if (length > compare_num.length)
			return true;
		if (length < compare_num.length)
			return false;
		if (length == compare_num.length)
		{
			//若长度相同,则从高位开始每一位比较
			for (int i = length - 1; i >= 0; i--)
			{
				if (num[i] > compare_num.num[i])
					return true;
				if (num[i] < compare_num.num[i])
					return false;
			}
			//两者完全相等的情况
			return false;
		}
	}
}

/*
	重载>=运算符

	@param[in] const bignum& compare_num:与之比较的大整数

	@return bool
*/
bool bignum::operator>=(const bignum& compare_num)
{
	//首先比较两者符号,若符号不同,直接判断
	if (is_positive && !compare_num.is_positive)
		return true;

	if (!is_positive && compare_num.is_positive)
		return false;

	//若符号相同,则需要进一步判断
	if (is_positive && compare_num.is_positive)
	{
		//先比较两者长度
		if (length > compare_num.length)
			return true;
		if (length < compare_num.length)
			return false;
		if (length == compare_num.length)
		{
			//若长度相同,则从高位开始每一位比较
			for (int i = length - 1; i >= 0; i--)
			{
				if (num[i] > compare_num.num[i])
					return true;
				if (num[i] < compare_num.num[i])
					return false;
			}
			//两者完全相等的情况
			return true;
		}
	}

	if (!is_positive && !compare_num.is_positive)
	{
		//先比较两者长度
		if (length > compare_num.length)
			return false;
		if (length < compare_num.length)
			return true;
		if (length == compare_num.length)
		{
			//若长度相同,则从高位开始每一位比较
			for (int i = length - 1; i >= 0; i--)
			{
				if (num[i] > compare_num.num[i])
					return false;
				if (num[i] < compare_num.num[i])
					return true;
			}
			//两者完全相等的情况
			return true;
		}
	}
}

/*
	重载<=运算符

	@param[in] const bignum& compare_num:与之比较的大整数

	@return bool
*/
bool bignum::operator<=(const bignum& compare_num)
{
	//首先比较两者符号,若符号不同,直接判断
	if (is_positive && !compare_num.is_positive)
		return false;

	if (!is_positive && compare_num.is_positive)
		return true;

	//若符号相同,则需要进一步判断
	if (is_positive && compare_num.is_positive)
	{
		//先比较两者长度
		if (length > compare_num.length)
			return false;
		if (length < compare_num.length)
			return true;
		if (length == compare_num.length)
		{
			//若长度相同,则从高位开始每一位比较
			for (int i = length - 1; i >= 0; i--)
			{
				if (num[i] > compare_num.num[i])
					return false;
				if (num[i] < compare_num.num[i])
					return true;
			}
			//两者完全相等的情况
			return true;
		}
	}

	if (!is_positive && !compare_num.is_positive)
	{
		//先比较两者长度
		if (length > compare_num.length)
			return true;
		if (length < compare_num.length)
			return false;
		if (length == compare_num.length)
		{
			//若长度相同,则从高位开始每一位比较
			for (int i = length - 1; i >= 0; i--)
			{
				if (num[i] > compare_num.num[i])
					return true;
				if (num[i] < compare_num.num[i])
					return false;
			}
			//两者完全相等的情况
			return true;
		}
	}
}

/*
	重载+运算符

	@param[in] const bignum& add_num:加数

	@return bignum:和
*/
bignum bignum::operator+(const bignum& add_num)
{
	bignum result;	//要返回的结果

	if (is_positive && add_num.is_positive || !is_positive && !add_num.is_positive)	//被加数与加数符号相同时,相当于加法
	{
		int carry = 0;	//进位
		int result_index = 0;	//结果数组的下标,每进一位,下标加一
		int temp = 0;	//记录加法运算中 被加数,加数的同一位 和 进位 三者之和

		//首先将被加数,加数,和 存储在三个不同的数组中
		int* added_num;	//存储被加数的数组
		int* _add_num;	//存储加数的数组
		int* result_num;	//存储结果的数组
		added_num = new int[length + add_num.length];
		_add_num = new int[length + add_num.length];
		result_num = new int[length + add_num.length];

		//给每一个数组赋值,多余的赋值为零
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

		//----------------高精度加法核心算法----------------
		//参考资料: https://blog.csdn.net/weifenglin1997/article/details/78748998
		for (int i = 0; i < length || i < add_num.length; i++)
		{
			temp = added_num[i] + _add_num[i] + carry;	//首先,记录加法运算中 被加数,加数的同一位 和 进位 三者之和
			result_num[result_index] = temp % 10;	//结果的同一位 等于 temp除10的余数
			result_index++;	//记录完结果的一位后,结果的下标加一,准备记录结果的下一位
			carry = temp / 10;	//进位等于 temp除10
		}
		if (carry != 0)	//如果最后一位的进位不为0,直接付给结果的最高位
		{
			result_num[result_index] = carry;
			result_index++;
		}
		//----------------------------------------------------

		//加法(两者符号相同)运算完毕,将存储结果的数组转移给大整数
		delete result.num;
		result.num = new int[result_index];
		result.length = result_index;
		for (int i = 0; i < result_index; i++)
			result.num[i] = result_num[i];

		if (is_positive && add_num.is_positive)	//被加数与加数都是正数的情况,此时和为正数
		{
			result.is_positive = true;
			return result;
		}
		else if (!is_positive && !add_num.is_positive)	//被加数与加数都是负数的情况,此时和为负数
		{
			result.is_positive = false;
			return result;
		}
	}
	else  //被加数与加数符号不同时,相当于减法
	{
		if (is_positive && !add_num.is_positive)	//被加数为正,加数为负的情况
		{
			bignum absed_num(add_num);	//首先获取加数的绝对值
			absed_num.is_positive = true;
			if (*this == absed_num)	//如果被加数与加数的绝对值相等,返回零
				return result;

			int result_index = 0;	//结果数组的下标,每进一位,下标加一
			int* subed_num;	//存储被减数的数组
			int* _sub_num;	//存储减数的数组
			int* result_num;	//存储结果的数组
			subed_num = new int[length + absed_num.length];
			_sub_num = new int[length + absed_num.length];
			result_num = new int[length + absed_num.length];

			if (*this > absed_num)	//当被加数大于加数的绝对值时,相当于 被加数 - 加数
			{
				//此时,被加数 赋值给 存储被减数的数组,加数 赋值给 存储减数的数组
				for (int i = 0; i < length + absed_num.length; i++)
				{
					if (i < length)
						subed_num[i] = num[i];
					else
						subed_num[i] = 0;

					if (i < absed_num.length)
						_sub_num[i] = absed_num.num[i];
					else
						_sub_num[i] = 0;

					result_num[i] = 0;
				}
			}
			else if (*this < absed_num)	//当被加数小于加数的绝对值时,相当于 加数 - 被加数
			{
				//此时,加数 赋值给 存储被减数的数组,被加数 赋值给 存储减数的数组
				for (int i = 0; i < length + absed_num.length; i++)
				{
					if (i < absed_num.length)
						subed_num[i] = absed_num.num[i];
					else
						subed_num[i] = 0;

					if (i < length)
						_sub_num[i] = num[i];
					else
						_sub_num[i] = 0;

					result_num[i] = 0;
				}
			}

			//----------------高精度减法核心算法----------------
			//参考资料: https://blog.csdn.net/weifenglin1997/article/details/78748998
			for (int i = 0; i < length || i < absed_num.length; i++)
			{
				if (subed_num[i] < _sub_num[i])	//如果不够减法,则向高位借位
					if (subed_num[i + 1] > 0)
					{
						subed_num[i + 1]--;
						subed_num[i] += 10;
					}
				result_num[result_index] = subed_num[i] - _sub_num[i];
				result_index++;
			}
			while (result_index - 1 >= 1 && result_num[result_index - 1] == 0)	//去除高位为0的数,同时保留一个最低位
				result_index--;
			//----------------------------------------------------

			//加法(两者符号不同)运算完毕,将存储结果的数组转移给大整数
			result.length = result_index;
			delete result.num;
			result.num = new int[result.length];
			for (int i = 0; i < result_index; i++)
				result.num[i] = result_num[i];

			if (*this > absed_num)
				result.is_positive = true;
			else if (*this < absed_num)
				result.is_positive = false;

			return result;
		}
		else if (!is_positive && add_num.is_positive)	//被加数为负,加数为正的情况
		{
			bignum absed_num(*this);	//首先获取被加数的绝对值
			absed_num.is_positive = true;
			if (absed_num == add_num)	//如果被加数的绝对值与加数相等,返回零
				return result;

			int result_index = 0;	//结果数组的下标,每进一位,下标加一
			int* subed_num;	//存储被减数的数组
			int* _sub_num;	//存储减数的数组
			int* result_num;	//存储结果的数组
			subed_num = new int[length + add_num.length];
			_sub_num = new int[length + add_num.length];
			result_num = new int[length + add_num.length];

			if (absed_num > add_num)	//当被加数的绝对值大于加数时,相当于 被加数 - 加数
			{
				//此时,被加数 赋值给 存储被减数的数组,加数 赋值给 存储减数的数组
				for (int i = 0; i < length + add_num.length; i++)
				{
					if (i < length)
						subed_num[i] = absed_num.num[i];
					else
						subed_num[i] = 0;

					if (i < add_num.length)
						_sub_num[i] = add_num.num[i];
					else
						_sub_num[i] = 0;

					result_num[i] = 0;
				}
			}
			else if (absed_num < add_num)	//当被加数的绝对值小于加数时,相当于 加数 - 被加数
			{
				//此时,加数 赋值给 存储被减数的数组,被加数 赋值给 存储减数的数组
				for (int i = 0; i < length + add_num.length; i++)
				{
					if (i < add_num.length)
						subed_num[i] = add_num.num[i];
					else
						subed_num[i] = 0;

					if (i < length)
						_sub_num[i] = absed_num.num[i];
					else
						_sub_num[i] = 0;

					result_num[i] = 0;
				}
			}

			//----------------高精度减法核心算法----------------
			//参考资料: https://blog.csdn.net/weifenglin1997/article/details/78748998
			for (int i = 0; i < length || i < add_num.length; i++)
			{
				if (subed_num[i] < _sub_num[i])	//如果不够减法,则向高位借位
					if (subed_num[i + 1] > 0)
					{
						subed_num[i + 1]--;
						subed_num[i] += 10;
					}
				result_num[result_index] = subed_num[i] - _sub_num[i];
				result_index++;
			}
			while (result_index - 1 >= 1 && result_num[result_index - 1] == 0)	//去除高位为0的数,同时保留一个最低位
				result_index--;
			//----------------------------------------------------

			//加法(两者符号不同)运算完毕,将存储结果的数组转移给大整数
			result.length = result_index;
			delete result.num;
			result.num = new int[result.length];
			for (int i = 0; i < result_index; i++)
				result.num[i] = result_num[i];

			if (absed_num > add_num)
				result.is_positive = false;
			else if (absed_num < add_num)
				result.is_positive = true;

			return result;
		}
	}
}

/*
	重载-运算符

	@param[in] const bignum& sub_num:减数

	@return bignum:差
*/
bignum bignum::operator-(const bignum& sub_num)
{
	bignum result;	//要返回的结果
	if (*this == sub_num)	//若被减数与减数相等,返回零
		return result;

	if (is_positive && sub_num.is_positive || !is_positive && !sub_num.is_positive)	//当被减数与减数符号相同时,此时相当于减法
	{
		int result_index = 0;	//结果的下标
		int* subed_num;	//存储被减数的数组
		int* _sub_num;	//存储减数的数组
		int* result_num;	//存储结果的数组
		subed_num = new int[length + sub_num.length];
		_sub_num = new int[length + sub_num.length];
		result_num = new int[length + sub_num.length];

		if (*this > sub_num && is_positive && sub_num.is_positive || *this < sub_num && !is_positive && !sub_num.is_positive)
		{
			//当 被减数与减数都为正数 且 被减数大于减数 或者 当 被减数与减数都为负数 且 被减数小于减数
			//此时相当于 被减数 - 减数
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
		}
		else if (*this < sub_num && is_positive && sub_num.is_positive || *this > sub_num && !is_positive && !sub_num.is_positive)
		{
			//当 被减数与减数都为正数 且 被减数小于减数 或者 当 被减数与减数都为负数 且 被减数大于减数
			//此时相当于 减数 - 被减数
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
		}

		//----------------高精度减法核心算法----------------
		//参考资料: https://blog.csdn.net/weifenglin1997/article/details/78748998
		for (int i = 0; i < length || i < sub_num.length; i++)
		{
			if (subed_num[i] < _sub_num[i])	//如果不够减法,则向高位借位
				if (subed_num[i + 1] > 0)
				{
					subed_num[i + 1]--;
					subed_num[i] += 10;
				}
			result_num[result_index] = subed_num[i] - _sub_num[i];
			result_index++;
		}
		while (result_index - 1 >= 1 && result_num[result_index - 1] == 0)	//去除高位为0的数,同时保留一个最低位
			result_index--;
		//----------------------------------------------------

		//减法(两者符号相同)运算完毕,将存储结果的数组转移给大整数
		result.length = result_index;
		delete result.num;
		result.num = new int[result.length];
		for (int i = 0; i < result_index; i++)
			result.num[i] = result_num[i];

		if (*this > sub_num && is_positive && sub_num.is_positive || *this > sub_num && !is_positive && !sub_num.is_positive)
			result.is_positive = true;
		else if (*this < sub_num && is_positive && sub_num.is_positive || *this < sub_num && !is_positive && !sub_num.is_positive)
			result.is_positive = false;

		return result;
	}
	else  //当被减数与减数符号不同时,此时相当于加法
	{
		int carry = 0;	//进位
		int result_index = 0;	//结果数组的下标,每进一位,下标加一
		int temp = 0;	//记录加法运算中 被加数,加数的同一位 和 进位 三者之和
		int* added_num;	//存储被加数的数组
		int* _add_num;	//存储加数的数组
		int* result_num;	//存储结果的数组
		added_num = new int[length + sub_num.length];
		_add_num = new int[length + sub_num.length];
		result_num = new int[length + sub_num.length];

		for (int i = 0; i < length + sub_num.length; i++)
		{
			if (i < length)
				added_num[i] = num[i];
			else
				added_num[i] = 0;

			if (i < sub_num.length)
				_add_num[i] = sub_num.num[i];
			else
				_add_num[i] = 0;

			result_num[i] = 0;
		}

		//----------------高精度加法核心算法----------------
		//参考资料: https://blog.csdn.net/weifenglin1997/article/details/78748998
		for (int i = 0; i < length || i < sub_num.length; i++)
		{
			temp = added_num[i] + _add_num[i] + carry;	//首先,记录加法运算中 被加数,加数的同一位 和 进位 三者之和
			result_num[result_index] = temp % 10;	//结果的同一位 等于 temp除10的余数
			result_index++;	//记录完结果的一位后,结果的下标加一,准备记录结果的下一位
			carry = temp / 10;	//进位等于 temp除10
		}
		if (carry != 0)	//如果最后一位的进位不为0,直接付给结果的最高位
		{
			result_num[result_index] = carry;
			result_index++;
		}
		//----------------------------------------------------

		//减法(两者符号不同)运算完毕,将存储结果的数组转移给大整数
		delete result.num;
		result.num = new int[result_index];
		result.length = result_index;
		for (int i = 0; i < result_index; i++)
			result.num[i] = result_num[i];

		if (is_positive && !sub_num.is_positive)
		{
			result.is_positive = true;
			return result;
		}
		else if (!is_positive && sub_num.is_positive)
		{
			result.is_positive = false;
			return result;
		}
	}
}

/*
	重载*运算符

	@param[in] const bignum& mul_num:乘数

	@return bignum:积
*/
bignum bignum::operator*(const bignum& mul_num)
{
	bignum result;	//要返回的结果
	if (length == 1 && num[0] == 0 || mul_num.length == 1 && mul_num.num[0] == 0)
		return result;	//如果被乘数与乘数中其中一个为零,则返回零
	
	int* result_num;	//存储结果的数组
	int* muled_num;	//存储被乘数的数组
	int* _mul_num;	//存储乘数的数组
	int result_length = length + mul_num.length;
	result_num = new int[length + mul_num.length + 1];
	muled_num = new int[length + mul_num.length + 1];
	_mul_num = new int[length + mul_num.length + 1];
	result_num[0] = 0;
	muled_num[0] = 0;
	_mul_num[0] = 0;
	
	//把大整数的值赋值给数组
	for (int i = 1; i <= length + mul_num.length; i++)
	{
		if (i <= length)
			muled_num[i] = num[i - 1];
		else
			muled_num[i] = 0;

		if (i <= mul_num.length)
			_mul_num[i] = mul_num.num[i - 1];
		else
			_mul_num[i] = 0;

		result_num[i] = 0;
	}

	//----------------高精度乘法核心算法----------------
	//参考资料: https://blog.csdn.net/bxg1065283526/article/details/79782098
	for (int i = 1; i <= length; i++)
		for (int j = 1; j <= mul_num.length; j++)	//注意:循环从 i = 1 和 j = 1 开始,遍历被乘数与乘数的每一位
		{
			result_num[i + j - 1] += muled_num[i] * _mul_num[j];	//被乘数的某一位 与 乘数的某一位 相乘,与 结果 相应的位上 累积的 进位 相加
			result_num[i + j] += result_num[i + j - 1] / 10;	//结果的下一位 开始累积 进位,即 上一行算出来的值 与 10 的 商
			result_num[i + j - 1] %= 10;	//计算进位结束后,结果的这一位 只取 个位 上的值
		}

	while (result_num[result_length] == 0 && result_length > 1)	//去除高位多余的零
		result_length--;
	//----------------------------------------------------

	//乘法运算结束后,将存储结果的数组转换成大整数
	result.length = result_length;
	delete result.num;
	result.num = new int[result_length];
	for (int i = 1; i <= result_length; i++)
		result.num[i - 1] = result_num[i];

	if (is_positive && mul_num.is_positive || !is_positive && !mul_num.is_positive)
		result.is_positive = true;	//如果被乘数与乘数的符号相同,则结果的符号为正
	else if (is_positive && !mul_num.is_positive || !is_positive && mul_num.is_positive)
		result.is_positive = false;	//如果被乘数与乘数的符号不同,则结果的符号为负

	return result;
}

/*
	重载/运算符

	@param[in] const bignum& div_num:除数

	@return bignum:商
*/
bignum bignum::operator/(const bignum& div_num)
{
	bignum result;	//要返回的结果

	//首先 获取被除数与除数的绝对值
	bignum _abs(*this);
	_abs.is_positive = true;
	bignum abs_div_num(div_num);
	abs_div_num.is_positive = true;

	if (abs_div_num.length == 1 && abs_div_num.num[0] == 0)	//如果除数为零,则返回零
	{
		cout << "除法运算符错误:不能除0" << endl;
		return result;
	}
	if (_abs.length == 1 && _abs.num[0] == 0)	//同样,如果被除数为零,则返回零
		return result;

	if (_abs < abs_div_num)	//如果 被除数的绝对值 小于 除数的绝对值,则返回零
		return result;
	else if (_abs == abs_div_num)	//如果 被除数的绝对值 等于 除数的绝对值,则返回 +1 或 -1
	{
		result.num[0] = 1;
		if (is_positive && div_num.is_positive || !is_positive && !div_num.is_positive)
			result.is_positive = true;
		else if (is_positive && !div_num.is_positive || !is_positive && div_num.is_positive)
			result.is_positive = false;
		return result;
	}
	else  //经过上面的过滤后,被除数的绝对值 肯定大于 除数的绝对值
	{
		bignum int_max("999999999");
		if (abs_div_num <= int_max)	//当除数为低精度数时
		{
			int _div_num_int = bignumToInt(abs_div_num);	//先把除数转换为int类型
			int result_length = _abs.length;
			int rem_num = 0;	//余数
			int* result_num;	//存储结果的数组
			int* dived_num;	//存储被除数的数组
			result_num = new int[length + div_num.length];
			dived_num= new int[length + div_num.length];

			//将大整数转移到数组上
			for (int i = 0; i < length + div_num.length; i++)
			{
				if (i < length)
					dived_num[i] = _abs.num[i];
				else
					dived_num[i] = 0;

				result_num[i] = 0;
			}

			//----------------高精度除低精度核心算法----------------
			//参考资料: https://www.cnblogs.com/lfyzoi/p/6737761.html
			for (int i = result_length - 1; i >= 0; i--)	//从高位向低位遍历
			{
				rem_num = rem_num * 10 + dived_num[i];	//上一次循环得到的 余数 乘10,再加上 被除数的某一位
				result_num[i] = rem_num / _div_num_int;	//上一行得到的值 除 低精度的除数 就是 结果相应的位的值
				rem_num %= _div_num_int;	//除法结束后,新的余数等于 自身 模以 除数,给下一次循环用
			}
			
			while (result_length - 1 >= 1 && result_num[result_length - 1] == 0)	//去除高位多余的零
				result_length--;
			//---------------------------------------------------------

			//除法(高精度除低精度)结束后,把存储结果的数组转换成大整数
			result.length = result_length;
			delete result.num;
			result.num = new int[result_length];
			for (int i = 0; i < result_length; i++)
				result.num[i] = result_num[i];

			if (is_positive && div_num.is_positive || !is_positive && !div_num.is_positive)
				result.is_positive = true;
			else if (is_positive && !div_num.is_positive || !is_positive && div_num.is_positive)
				result.is_positive = false;

			return result;
		}
		else //当除数为高精度时
		{	
			int* result_num;	//存储结果的数组
			int* dived_num;	//存储被除数的数组
			int* _div_num;	//存储除数的数组
			int result_length = length;
			int dived_num_length = length;
			int div_num_length = div_num.length;
			int nTimes = 0;
			int nTemps = 0;

			result_num = new int[length + div_num.length];
			dived_num = new int[length + div_num.length];
			_div_num = new int[length + div_num.length];

			//将大整数转换为数组
			for (int i = 0; i < length + div_num.length; i++)
			{
				if (i < length)
					dived_num[i] = num[i];
				else
					dived_num[i] = 0;

				if (i < div_num.length)
					_div_num[i] = div_num.num[i];
				else
					_div_num[i] = 0;

				result_num[i] = 0;
			}
			
			//----------------高精度除高精度核心算法----------------
			//参考资料: https://blog.csdn.net/ljq199926/article/details/79343823
			nTimes = dived_num_length - div_num_length;
			for (int i = dived_num_length - 1; i >= 0; i--)	//首先,给除数的低位补零 到 位数与被除数相等
			{
				if (i >= nTimes)
					_div_num[i] = _div_num[i - nTimes];
				else
					_div_num[i] = 0;
			}
			div_num_length = dived_num_length;

			for (int i = 0; i <= nTimes; i++)	//然后,尽可能按照最大数量级 将 被除数 与 除数 相减
			{
				while ((nTemps = SubStract(dived_num, _div_num + i, dived_num_length, div_num_length - i)) >= 0)
				{
					dived_num_length = nTemps;
					result_num[nTimes - i]++;	//减成功了,结果的相应数量级加一
				}
				//减不成功,将除数降一个数量级,继续减
			}

			while (result_length - 1 >= 1 && result_num[result_length - 1] == 0)	//运算完成后,将结果高位的零去除
				result_length--;
			//---------------------------------------------------------

			//除法(高精度除高精度)结束后,把存储结果的数组转换成大整数
			result.length = result_length;
			delete result.num;
			result.num = new int[result_length];
			for (int i = 0; i < result_length; i++)
				result.num[i] = result_num[i];

			if (is_positive && div_num.is_positive || !is_positive && !div_num.is_positive)
				result.is_positive = true;
			else if (is_positive && !div_num.is_positive || !is_positive && div_num.is_positive)
				result.is_positive = false;

			return result;
		}
	}
}

/*
	重载%运算符

	@param[in] const bignum& div_num:除数

	@return bignum:余数
*/
bignum bignum::operator%(const bignum& div_num)
{
	bignum result;	//要返回的结果

	//首先 获取被除数与除数的绝对值
	bignum _abs(*this);
	_abs.is_positive = true;
	bignum abs_div_num(div_num);
	abs_div_num.is_positive = true;

	if (abs_div_num.length == 1 && abs_div_num.num[0] == 0)	//如果除数为零,则返回零
	{
		cout << "取余运算符错误:不能除0" << endl;
		return result;
	}
	if (_abs.length == 1 && _abs.num[0] == 0)	//同样,如果被除数为零,则返回零
		return result;

	if (_abs < abs_div_num)	//如果 被除数的绝对值 小于 除数的绝对值,则返回被除数
	{
		result = _abs;
		result.is_positive = is_positive;
		return result;
	}
	else if (_abs == abs_div_num)	//如果 被除数的绝对值 等于 除数的绝对值,则返回零
		return result;
	else  //经过上面的过滤后,被除数的绝对值 肯定大于 除数的绝对值
	{
		bignum int_max("999999999");
		if (abs_div_num <= int_max)	//除数为低精度数的情况
		{
			int ans = 0;
			int div_num_int = bignumToInt(abs_div_num);

			//----------------高精度取余低精度核心算法----------------
			//参考资料: https://blog.csdn.net/qq_42217376/article/details/86722805
			for (int i = _abs.length - 1; i >= 0; i--)
			{
				ans = (10 * ans + _abs.num[i]) % div_num_int;
			}
			//-----------------------------------------------------------

			//将结果转换成大整数
			bignum return_num(ans);
			return_num.is_positive = is_positive;
			return return_num;
		}
		else
		{
			bignum div_result = _abs / abs_div_num;
			bignum mul_result = div_result * abs_div_num;
			result = _abs - mul_result;
			result.is_positive = is_positive;
			return result;
		}
	}
}

/*
	重载+=运算符

	@param[in] const bignum& add_num:加数

	@return bignum
*/
bignum bignum::operator+=(const bignum& add_num)
{
	*this = *this + add_num;
	return *this;
}

/*
	重载-=运算符

	@param[in] const bignum& sub_num:减数

	@return bignum
*/
bignum bignum::operator-=(const bignum& sub_num)
{
	*this = *this - sub_num;
	return *this;
}

/*
	重载*=运算符

	@param[in] const bignum& mul_num:乘数

	@return bignum
*/
bignum bignum::operator*=(const bignum& mul_num)
{
	*this = *this * mul_num;
	return *this;
}

/*
	重载/=运算符

	@param[in] const bignum& div_num:除数

	@return bignum
*/
bignum bignum::operator/=(const bignum& div_num)
{
	*this = *this / div_num;
	return *this;
}

/*
	重载%=运算符

	@param[in] const bignum& div_num:除数

	@return bignum
*/
bignum bignum::operator%=(const bignum& div_num)
{
	*this = *this % div_num;
	return *this;
}

/*
	重载++前缀运算符

	@return bignum
*/
bignum bignum::operator++()
{
	bignum added("1");
	*this = *this + added;
	return *this;
}

/*
	重载++后缀运算符

	@return bignum
*/
bignum bignum::operator++(int)
{
	bignum return_num(*this);
	bignum added("1");
	*this = *this + added;
	return return_num;
}

/*
	重载--前缀运算符

	@return bignum
*/
bignum bignum::operator--()
{
	bignum subed("1");
	*this = *this - subed;
	return *this;
}

/*
	重载--后缀运算符

	@return bignum
*/
bignum bignum::operator--(int)
{
	bignum return_num(*this);
	bignum subed("1");
	*this = *this - subed;
	return return_num;
}

/*
	大整数转int类型

	@param[in] const bignum& _num:要转换的大整数

	@return int
*/
int bignumToInt(const bignum& _num)
{
	bignum trans_num(_num);
	bignum int_max("2147483647");
	bignum int_min("-2147483647");
	if (trans_num < int_min || trans_num > int_max)
	{
		cout << "bignumToInt函数错误:传入的参数超出范围" << endl;
		return 0;
	}
	else
	{
		int mi = 1;
		int result = 0;
		for (int i = 0; i < trans_num.length; i++)
		{
			result += trans_num.num[i] * mi;
			mi *= 10;
		}
		if (!trans_num.is_positive)
			result = 0 - result;

		return result;
	}
}

/*
	求阶乘

	@param[in] int r:阶数

	@return bignum
*/
bignum fac(int r)
{
	bignum result("1");
	if (r < 1)
	{
		cout << "fac函数错误,传入的参数不符合规范" << endl;
		return result;
	}
	else
	{
		bignum m1("1");
		for (int i = 1; i <= r; i++)
		{
			result = result * m1;
			++m1;
		}
		return result;
	}
}

/*
	数组之间的减法
	主要用于重载/运算符

	@param[in] int* p1:被减数
	@param[in] int* p2:减数
	@param[in] int len1:被减数的长度
	@param[in] int len2:减数的长度

	@return int
*/
int SubStract(int* p1, int* p2, int len1, int len2)
{
	int i;
	if (len1 < len2)
		return -1;
	if (len1 == len2)
	{                        //判断p1 > p2
		for (i = len1 - 1; i >= 0; i--)
		{
			if (p1[i] > p2[i])   //若大，则满足条件，可做减法
				break;
			else if (p1[i] < p2[i]) //否则返回-1
				return -1;
		}
	}
	for (i = 0; i <= len1 - 1; i++)  //从低位开始做减法
	{
		p1[i] -= p2[i];
		if (p1[i] < 0)          //若p1<0，则需要借位
		{
			p1[i] += 10;         //借1当10
			p1[i + 1]--;           //高位减1
		}
	}
	for (i = len1 - 1; i >= 0; i--)       //查找结果的最高位
		if (p1[i])                  //最高位第一个不为0
			return (i + 1);       //得到位数并返回
	return 0;                  //两数相等的时候返回0
}

/*
	重载<<运算符

	@param[in] ostream& os:输出流
	@param[in] bignum num:大整数

	@return ostream&
*/
ostream& operator<<(ostream& os, bignum num)
{
	if (!num.isPositive())
		os << "-";

	int* _num = num.getArray();
	for (int i = num.getLength() - 1; i >= 0; i--)
		os << _num[i];

	return os;
}

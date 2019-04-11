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

#include "BigNum.h";

/*
	�޲ι��캯��
	Ĭ�ϸ�ֵ��
*/
bignum::bignum()
{
	num = new int[1];
	num[0] = 0;
	length = 1;
	is_positive = true;
}

/*
	���ַ��������������
	ע���ַ�����������������ʽ,�����'+','-'���ַ�����λ
	const char* str:������ַ���
*/
bignum::bignum(const char* str)
{
	int zero_count = 0;
	int str_length = strlen(str);

	if (str_length == 0)
	{
		cout << "���캯������:�ַ�������Ϊ��" << endl;
		num = new int[1];
		num[0] = 0;
		length = 1;
		is_positive = true;
	}

	else if (str_length == 1)
		if (str[0] < '0' || str[0] > '9')
		{
			cout << "���캯������:�Ƿ��ַ���" << endl;
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
				cout << "���캯������,�ַ������ܶ���0" << endl;
				num = new int[1];
				num[0] = 0;
				length = 1;
				is_positive = true;
			}
			else
			{
				if (zero_count > 0)
					cout << "���캯��:���Զ���ǰ���0ȥ��" << endl;

				num = new int[length];
				if (str[0] == '+')
					is_positive = true;
				else
					is_positive = false;

				for (int i = str_length - 1; i >= zero_count + 1; i--)
					if (str[i] < '0' || str[i] > '9')
					{
						cout << "���캯������:�Ƿ��ַ���" << endl;
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
				cout << "���캯������,�ַ������ܶ���0" << endl;
				num = new int[1];
				num[0] = 0;
				length = 1;
				is_positive = true;
			}
			else
			{
				if (zero_count > 0)
					cout << "���캯��:���Զ���ǰ���0ȥ��" << endl;

				num = new int[length];
				is_positive = true;

				for (int i = str_length - 1; i >= zero_count; i--)
					if (str[i] < '0' || str[i] > '9')
					{
						cout << "���캯������:�Ƿ��ַ���" << endl;
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

/*
	��int���������������
	int _num:�����int������
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
	��usigned long���������������
	unsigned long _num:�����usigned long������
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
	��long long���������������
	long long _num:�����long long������
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
	�������캯��
	const bignum& ano:�������Ĵ�����
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
	��������
*/
bignum::~bignum()
{
	delete num;
}

/*
	���ش������ķ���
	trueΪ��,falseΪ��,ע��:0Ϊ����

	@Return bool
*/
bool bignum::isPositive()
{
	return is_positive;
}

/*
	�жϴ������Ƿ�Ϊ��

	@Return bool
*/
bool bignum::isZero()
{
	return length == 1 && num[0] == 0;
}

/*
	���ش�������λ��

	@Return int
*/
int bignum::getLength()
{
	return length;
}

/*
	���ش洢������������
	���õ���洢

	@Return int*
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
	��ӡ������

	@Return void
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
	���ش������ľ���ֵ
	ע��:���ô˺����Ĵ���������Ӱ��

	@Return bignum
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
	����=�����
	const bignum& copy_num:��ֵ�Ĵ�����

	@Return bignum&
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
	����==�����
	const bignum & compare_num:��֮�ȽϵĴ�����

	@Return bool
*/
bool bignum::operator==(const bignum & compare_num)
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

/*
	����!=�����
	const bignum & compare_num:��֮�ȽϵĴ�����

	@Return bool
*/
bool bignum::operator!=(const bignum & compare_num)
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

/*
	����>�����
	const bignum & compare_num:��֮�ȽϵĴ�����

	@Return bool
*/
bool bignum::operator>(const bignum & compare_num)
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

/*
	����<�����
	const bignum & compare_num:��֮�ȽϵĴ�����

	@Return bool
*/
bool bignum::operator<(const bignum & compare_num)
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

/*
	����>=�����
	const bignum & compare_num:��֮�ȽϵĴ�����

	@Return bool
*/
bool bignum::operator>=(const bignum & compare_num)
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

/*
	����<=�����
	const bignum & compare_num:��֮�ȽϵĴ�����

	@Return bool
*/
bool bignum::operator<=(const bignum & compare_num)
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

/*
	����+�����
	const bignum & add_num:����

	@Return bignum
*/
bignum bignum::operator+(const bignum & add_num)
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
		if (is_positive && !add_num.is_positive)
		{
			bignum absed_num(add_num);
			absed_num.is_positive = true;
			if (*this == absed_num)
				return result;

			int result_index = 0;
			int* subed_num;
			int* _sub_num;
			int* result_num;
			subed_num = new int[length + absed_num.length];
			_sub_num = new int[length + absed_num.length];
			result_num = new int[length + absed_num.length];

			if (*this > absed_num)
			{
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
			else if (*this < absed_num)
			{
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

			for (int i = 0; i < length || i < absed_num.length; i++)
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
		else if (!is_positive && add_num.is_positive)
		{
			bignum absed_num(*this);
			absed_num.is_positive = true;
			if (absed_num == add_num)
				return result;

			int result_index = 0;
			int* subed_num;
			int* _sub_num;
			int* result_num;
			subed_num = new int[length + add_num.length];
			_sub_num = new int[length + add_num.length];
			result_num = new int[length + add_num.length];

			if (absed_num > add_num)
			{
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
			else if (absed_num < add_num)
			{
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

			for (int i = 0; i < length || i < add_num.length; i++)
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
	����-�����
	const bignum& sub_num:����

	@Return bignum
*/
bignum bignum::operator-(const bignum& sub_num)
{
	bignum result;
	if (*this == sub_num)
		return result;

	if (is_positive && sub_num.is_positive || !is_positive && !sub_num.is_positive)
	{
		int result_index = 0;
		int* subed_num;
		int* _sub_num;
		int* result_num;
		subed_num = new int[length + sub_num.length];
		_sub_num = new int[length + sub_num.length];
		result_num = new int[length + sub_num.length];

		if (*this > sub_num && is_positive && sub_num.is_positive || *this < sub_num && !is_positive && !sub_num.is_positive)
		{
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
	else
	{
		int carry = 0;
		int result_index = 0;
		int temp = 0;
		int* added_num;
		int* _add_num;
		int* result_num;
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
		for (int i = 0; i < length || i < sub_num.length; i++)
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
	����*�����
	const bignum& mul_num:����

	@Return bignum
*/
bignum bignum::operator*(const bignum& mul_num)
{
	bignum result;
	if (length == 1 && num[0] == 0 || mul_num.length == 1 && mul_num.num[0] == 0)
		return result;
	
	int* result_num;
	int* muled_num;
	int* _mul_num;
	int result_length = length + mul_num.length;
	result_num = new int[length + mul_num.length + 1];
	muled_num = new int[length + mul_num.length + 1];
	_mul_num = new int[length + mul_num.length + 1];
	result_num[0] = 0;
	muled_num[0] = 0;
	_mul_num[0] = 0;
	
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

	for (int i = 1; i <= length; i++)
		for (int j = 1; j <= mul_num.length; j++)
		{
			result_num[i + j - 1] += muled_num[i] * _mul_num[j];
			result_num[i + j] += result_num[i + j - 1] / 10;
			result_num[i + j - 1] %= 10;
		}

	while (result_num[result_length] == 0 && result_length > 1)
		result_length--;

	result.length = result_length;
	delete result.num;
	result.num = new int[result_length];
	for (int i = 1; i <= result_length; i++)
		result.num[i - 1] = result_num[i];

	if (is_positive && mul_num.is_positive || !is_positive && !mul_num.is_positive)
		result.is_positive = true;
	else if (is_positive && !mul_num.is_positive || !is_positive && mul_num.is_positive)
		result.is_positive = false;

	return result;
}

/*
	����/�����
	const bignum& div_num:����

	@Return bignum
*/
bignum bignum::operator/(const bignum& div_num)
{
	bignum result;
	bignum _abs(*this);
	_abs.is_positive = true;
	bignum abs_div_num(div_num);
	abs_div_num.is_positive = true;

	if (abs_div_num.length == 1 && abs_div_num.num[0] == 0)
	{
		cout << "�������������:���ܳ�0" << endl;
		return result;
	}
	if (_abs.length == 1 && _abs.num[0] == 0)
		return result;

	if (_abs < abs_div_num)
		return result;
	else if (_abs == abs_div_num)
	{
		result.num[0] = 1;
		if (is_positive && div_num.is_positive || !is_positive && !div_num.is_positive)
			result.is_positive = true;
		else if (is_positive && !div_num.is_positive || !is_positive && div_num.is_positive)
			result.is_positive = false;
		return result;
	}
	else
	{
		bignum int_max("999999999");
		if (abs_div_num <= int_max)
		{
			int _div_num_int = bignumToInt(abs_div_num);
			int result_length = _abs.length;
			int rem_num = 0;
			int* result_num;
			int* dived_num;
			result_num = new int[length + div_num.length];
			dived_num= new int[length + div_num.length];

			for (int i = 0; i < length + div_num.length; i++)
			{
				if (i < length)
					dived_num[i] = _abs.num[i];
				else
					dived_num[i] = 0;

				result_num[i] = 0;
			}

			for (int i = result_length - 1; i >= 0; i--)
			{
				if (rem_num < 0 || rem_num >214748363)
				{
					cout << "��������:rem_num������Χ" << endl;
					return result;
				}
				rem_num = rem_num * 10 + dived_num[i];
				result_num[i] = rem_num / _div_num_int;
				rem_num %= _div_num_int;
			}
			
			while (result_length - 1 >= 1 && result_num[result_length - 1] == 0)
				result_length--;

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
		else
		{
			/*int* result_num;
			int result_length = 0;
			int result_index = 0;
			int index_of_dived = _abs.length - 1;
			int simple_result = 0;
			bignum dived_pro_num;
			bignum div_mul_num;
			bignum simple_mul_num;
			bignum subed_pro_num;

			dived_pro_num.length = abs_div_num.length;
			delete dived_pro_num.num;
			dived_pro_num.num = new int[dived_pro_num.length];
			for (int i = dived_pro_num.length - 1; i >= 0; i--)
			{
				dived_pro_num.num[i] = _abs.num[index_of_dived];
				index_of_dived--;
			}

			if (dived_pro_num >= abs_div_num)
			{
				result_length = _abs.length - abs_div_num.length + 1;
				result_num = new int[result_length];
			}
			else if(dived_pro_num < abs_div_num)
			{
				result_length = _abs.length - abs_div_num.length;
				result_num = new int[result_length];
				result_index = result_length - 1;
				index_of_dived += dived_pro_num.length;

				dived_pro_num.length++;
				delete dived_pro_num.num;
				dived_pro_num.num = new int[dived_pro_num.length];
				for (int i = dived_pro_num.length - 1; i >= 0; i--)
				{
					dived_pro_num.num[i] = _abs.num[index_of_dived];
					index_of_dived--;
				}

				for (int i = 1; i <= 9; i++)
				{
					simple_mul_num.num[0] = i;
					div_mul_num = abs_div_num * simple_mul_num;
					subed_pro_num = dived_pro_num - div_mul_num;
					if (subed_pro_num < abs_div_num)
					{
						result_num[result_index] = i;
						result_index--;
						break;
					}
				}
			}
			*/
			
			int* result_num;
			int* dived_num;
			int* _div_num;
			int result_length = length;
			int dived_num_length = length;
			int div_num_length = div_num.length;
			int nTimes = 0;
			int nTemps = 0;

			result_num = new int[length + div_num.length];
			dived_num = new int[length + div_num.length];
			_div_num = new int[length + div_num.length];

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

			nTimes = dived_num_length - div_num_length;
			for (int i = dived_num_length - 1; i >= 0; i--)
			{
				if (i >= nTimes)
					_div_num[i] = _div_num[i - nTimes];
				else
					_div_num[i] = 0;
			}
			div_num_length = dived_num_length;

			for (int i = 0; i <= nTimes; i++)
			{
				while ((nTemps = SubStract(dived_num, _div_num + i, dived_num_length, div_num_length - i)) >= 0)
				{
					dived_num_length = nTemps;
					result_num[nTimes - i]++;
				}
			}

			while (result_length - 1 >= 1 && result_num[result_length - 1] == 0)
				result_length--;

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
	����%�����
	const bignum& div_num:����

	@Return bignum
*/
bignum bignum::operator%(const bignum& div_num)
{
	bignum result;
	bignum _abs(*this);
	_abs.is_positive = true;
	bignum abs_div_num(div_num);
	abs_div_num.is_positive = true;

	if (abs_div_num.length == 1 && abs_div_num.num[0] == 0)
	{
		cout << "ȡ�����������:���ܳ�0" << endl;
		return result;
	}
	if (_abs.length == 1 && _abs.num[0] == 0)
		return result;

	if (_abs < abs_div_num)
	{
		result = _abs;
		result.is_positive = is_positive;
		return result;
	}
	else if (_abs == abs_div_num)
		return result;
	else
	{
		bignum int_max("999999999");
		if (abs_div_num <= int_max)
		{
			int ans = 0;
			int b = bignumToInt(abs_div_num);
			for (int i = _abs.length - 1; i >= 0; i--)
			{
				ans = (10 * ans + _abs.num[i]) % b;
			}
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
	����+=�����
	const bignum& add_num:����

	@Return bignum
*/
bignum bignum::operator+=(const bignum& add_num)
{
	*this = *this + add_num;
	return *this;
}

/*
	����-=�����
	const bignum& sub_num:����

	@Return bignum
*/
bignum bignum::operator-=(const bignum& sub_num)
{
	*this = *this - sub_num;
	return *this;
}

/*
	����*=�����
	const bignum& mul_num:����

	@Return bignum
*/
bignum bignum::operator*=(const bignum& mul_num)
{
	*this = *this * mul_num;
	return *this;
}

/*
	����/=�����
	const bignum& div_num:����

	@Return bignum
*/
bignum bignum::operator/=(const bignum& div_num)
{
	*this = *this / div_num;
	return *this;
}

/*
	����%=�����
	const bignum& div_num:����

	@Return bignum
*/
bignum bignum::operator%=(const bignum& div_num)
{
	*this = *this % div_num;
	return *this;
}

/*
	����++ǰ׺�����

	@Return bignum
*/
bignum bignum::operator++()
{
	bignum added("1");
	*this = *this + added;
	return *this;
}

/*
	����++��׺�����

	@Return bignum
*/
bignum bignum::operator++(int)
{
	bignum return_num(*this);
	bignum added("1");
	*this = *this + added;
	return return_num;
}

/*
	����--ǰ׺�����

	@Return bignum
*/
bignum bignum::operator--()
{
	bignum subed("1");
	*this = *this - subed;
	return *this;
}

/*
	����--��׺�����

	@Return bignum
*/
bignum bignum::operator--(int)
{
	bignum return_num(*this);
	bignum subed("1");
	*this = *this - subed;
	return return_num;
}

/*
	������תint����
	const bignum& _num:Ҫת���Ĵ�����

	@Return int
*/
int bignumToInt(const bignum& _num)
{
	bignum trans_num(_num);
	bignum int_max("2147483647");
	bignum int_min("-2147483647");
	if (trans_num < int_min || trans_num > int_max)
	{
		cout << "bignumToInt��������:����Ĳ���������Χ" << endl;
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
	��׳�
	int r:����

	@Return bignum
*/
bignum fac(int r)
{
	bignum result("1");
	if (r < 1)
	{
		cout << "fac��������,����Ĳ��������Ϲ淶" << endl;
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
	����֮��ļ���
	��Ҫ��������/�����
	int* p1:������
	int* p2:����
	int len1:�������ĳ���
	int len2:�����ĳ���

	@Return int
*/
int SubStract(int* p1, int* p2, int len1, int len2)
{
	int i;
	if (len1 < len2)
		return -1;
	if (len1 == len2)
	{                        //�ж�p1 > p2
		for (i = len1 - 1; i >= 0; i--)
		{
			if (p1[i] > p2[i])   //������������������������
				break;
			else if (p1[i] < p2[i]) //���򷵻�-1
				return -1;
		}
	}
	for (i = 0; i <= len1 - 1; i++)  //�ӵ�λ��ʼ������
	{
		p1[i] -= p2[i];
		if (p1[i] < 0)          //��p1<0������Ҫ��λ
		{
			p1[i] += 10;         //��1��10
			p1[i + 1]--;           //��λ��1
		}
	}
	for (i = len1 - 1; i >= 0; i--)       //���ҽ�������λ
		if (p1[i])                  //���λ��һ����Ϊ0
			return (i + 1);       //�õ�λ��������
	return 0;                  //������ȵ�ʱ�򷵻�0
}

/*
	����<<�����
	ostream& os:�����
	bignum num:������

	@Return ostream&
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

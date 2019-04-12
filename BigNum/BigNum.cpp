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
   @brief ����������غ�����ʵ��
   @author heiyedeshengyin
   @date 2019.4.12 12:49:32
   @license Apache License, Version 2.0
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

	@param[in] const char* str:������ַ���
*/
bignum::bignum(const char* str)
{
	int zero_count = 0;	//�ַ�����ͷ��ĸ���,��Щ�㽫��ȥ��
	int str_length = strlen(str);	//�ַ������ַ�����

	if (str_length == 0)	//�ַ���Ϊ�յ����
	{
		cout << "���캯������:�ַ�������Ϊ��" << endl;
		num = new int[1];
		num[0] = 0;
		length = 1;
		is_positive = true;
	}

	else if (str_length == 1)	//�ַ���ֻ��һ���ַ������
		if (str[0] < '0' || str[0] > '9')	//�ж��ַ��Ƿ�Ϊ����
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

	else  //�ַ�����ͷΪ�����ŵ����
		if (str[0] == '+' || str[0] == '-')
		{
			for (int i = 1; i < str_length; i++)	//��¼�ַ�����ͷ��ĸ���
				if (str[i] == '0')
					zero_count++;
				else
					break;

			length = str_length - zero_count - 1;
			if (length == 0)	//�ַ���ȫ��������
			{
				cout << "���캯������,�ַ������ܶ���0" << endl;
				num = new int[1];
				num[0] = 0;
				length = 1;
				is_positive = true;
			}
			else  //�ַ���������ȫΪ������
			{
				if (zero_count > 0)
					cout << "���캯��:���Զ���ǰ���0ȥ��" << endl;

				num = new int[length];
				if (str[0] == '+')	//�����ַ�����ͷ�ķ������жϴ�����������
					is_positive = true;
				else
					is_positive = false;

				for (int i = str_length - 1; i >= zero_count + 1; i--)
					if (str[i] < '0' || str[i] > '9')	//�����ж��ַ�����ÿ���ַ��Ƿ�Ϊ����
					{
						//�����������,ֱ������ѭ��������������ֵΪ��
						cout << "���캯������:�Ƿ��ַ���" << endl;
						delete num;
						num = new int[1];
						num[0] = 0;
						length = 1;
						is_positive = true;
						break;
					}
					else
						num[str_length - 1 - i] = str[i] - '0';	//���������,�͵���ֵ������ѭ��
			}
		}
		else  //�ַ�����ͷû�������ŵ����
		{
			for (int i = 0; i < str_length; i++)	//��¼�ַ�����ͷ��ĸ���
				if (str[i] == '0')
					zero_count++;
				else
					break;

			length = str_length - zero_count;
			if (length == 0)	//�ַ���ȫ��������
			{
				cout << "���캯������,�ַ������ܶ���0" << endl;
				num = new int[1];
				num[0] = 0;
				length = 1;
				is_positive = true;
			}
			else  //�ַ���������ȫΪ������
			{
				if (zero_count > 0)
					cout << "���캯��:���Զ���ǰ���0ȥ��" << endl;

				num = new int[length];
				is_positive = true;	//��Ϊ�ַ�����ͷû�з���,������Ĭ��Ϊ����

				for (int i = str_length - 1; i >= zero_count; i--)
					if (str[i] < '0' || str[i] > '9')	//�����ж��ַ�����ÿ���ַ��Ƿ�Ϊ����
					{
						//�����������,ֱ������ѭ��������������ֵΪ��
						cout << "���캯������:�Ƿ��ַ���" << endl;
						delete num;
						num = new int[1];
						num[0] = 0;
						length = 1;
						is_positive = true;
						break;
					}
					else
						num[str_length - 1 - i] = str[i] - '0';	//���������,�͵���ֵ������ѭ��
			}
		}
}

/*
	��int���������������

	@param[in] int _num:�����int������
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

	@param[in] unsigned long _num:�����usigned long������
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

	@param[in] long long _num:�����long long������
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

	@param[in] const bignum& ano:�������Ĵ�����
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
	
	@return bool:trueΪ��,falseΪ��,ע��:0Ϊ����
*/
bool bignum::isPositive()
{
	return is_positive;
}

/*
	�жϴ������Ƿ�Ϊ��

	@return bool:trueΪ��,��֮��Ϊ
*/
bool bignum::isZero()
{
	return length == 1 && num[0] == 0;
}

/*
	���ش�������λ��

	@return int:��������λ��
*/
int bignum::getLength()
{
	return length;
}

/*
	���ش洢������������
	���õ���洢

	@return int*:�洢������������
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
	���ش������ľ���ֵ
	ע��:���ô˺����Ĵ���������Ӱ��

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
	����=�����

	@param[in] const bignum& copy_num:��ֵ�Ĵ�����

	@return bignum&:����ֵ�Ĵ�����
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

	@param[in] const bignum& compare_num:��֮�ȽϵĴ�����

	@return bool
*/
bool bignum::operator==(const bignum& compare_num)
{
	if (length != compare_num.length || is_positive != compare_num.is_positive)	//���ȱȽϷ���
		return false;
	else  //Ȼ�����αȽ�ÿһ����
	{
		for (int i = 0; i < length; i++)
			if (num[i] != compare_num.num[i])
				return false;

		return true;
	}
}

/*
	����!=�����
	
	@param[in] const bignum& compare_num:��֮�ȽϵĴ�����

	@return bool
*/
bool bignum::operator!=(const bignum& compare_num)
{
	if (length != compare_num.length || is_positive != compare_num.is_positive)	//���ȱȽϷ���
		return true;
	else  //Ȼ�����αȽ�ÿһ����
	{
		for (int i = 0; i < length; i++)
			if (num[i] != compare_num.num[i])
				return true;

		return false;
	}
}

/*
	����>�����

	@param[in] const bignum& compare_num:��֮�ȽϵĴ�����

	@return bool
*/
bool bignum::operator>(const bignum& compare_num)
{
	//���ȱȽ����߷���,�����Ų�ͬ,ֱ���ж�
	if (is_positive && !compare_num.is_positive)
		return true;

	if (!is_positive && compare_num.is_positive)
		return false;

	//��������ͬ,����Ҫ��һ���ж�
	if (is_positive && compare_num.is_positive)
	{
		//�ȱȽ����߳���
		if (length > compare_num.length)
			return true;
		if (length < compare_num.length)
			return false;
		if (length == compare_num.length)
		{
			//��������ͬ,��Ӹ�λ��ʼÿһλ�Ƚ�
			for (int i = length - 1; i >= 0; i--)
			{
				if (num[i] > compare_num.num[i])
					return true;
				if (num[i] < compare_num.num[i])
					return false;
			}
			//������ȫ��ȵ����
			return false;
		}
	}

	if (!is_positive && !compare_num.is_positive)
	{
		//�ȱȽ����߳���
		if (length > compare_num.length)
			return false;
		if (length < compare_num.length)
			return true;
		if (length == compare_num.length)
		{
			//��������ͬ,��Ӹ�λ��ʼÿһλ�Ƚ�
			for (int i = length - 1; i >= 0; i--)
			{
				if (num[i] > compare_num.num[i])
					return false;
				if (num[i] < compare_num.num[i])
					return true;
			}
			//������ȫ��ȵ����
			return false;
		}
	}
}

/*
	����<�����

	@param[in] const bignum& compare_num:��֮�ȽϵĴ�����

	@return bool
*/
bool bignum::operator<(const bignum& compare_num)
{
	//���ȱȽ����߷���,�����Ų�ͬ,ֱ���ж�
	if (is_positive && !compare_num.is_positive)
		return false;

	if (!is_positive && compare_num.is_positive)
		return true;

	//��������ͬ,����Ҫ��һ���ж�
	if (is_positive && compare_num.is_positive)
	{
		//�ȱȽ����߳���
		if (length > compare_num.length)
			return false;
		if (length < compare_num.length)
			return true;
		if (length == compare_num.length)
		{
			//��������ͬ,��Ӹ�λ��ʼÿһλ�Ƚ�
			for (int i = length - 1; i >= 0; i--)
			{
				if (num[i] > compare_num.num[i])
					return false;
				if (num[i] < compare_num.num[i])
					return true;
			}
			//������ȫ��ȵ����
			return false;
		}
	}

	if (!is_positive && !compare_num.is_positive)
	{
		//�ȱȽ����߳���
		if (length > compare_num.length)
			return true;
		if (length < compare_num.length)
			return false;
		if (length == compare_num.length)
		{
			//��������ͬ,��Ӹ�λ��ʼÿһλ�Ƚ�
			for (int i = length - 1; i >= 0; i--)
			{
				if (num[i] > compare_num.num[i])
					return true;
				if (num[i] < compare_num.num[i])
					return false;
			}
			//������ȫ��ȵ����
			return false;
		}
	}
}

/*
	����>=�����

	@param[in] const bignum& compare_num:��֮�ȽϵĴ�����

	@return bool
*/
bool bignum::operator>=(const bignum& compare_num)
{
	//���ȱȽ����߷���,�����Ų�ͬ,ֱ���ж�
	if (is_positive && !compare_num.is_positive)
		return true;

	if (!is_positive && compare_num.is_positive)
		return false;

	//��������ͬ,����Ҫ��һ���ж�
	if (is_positive && compare_num.is_positive)
	{
		//�ȱȽ����߳���
		if (length > compare_num.length)
			return true;
		if (length < compare_num.length)
			return false;
		if (length == compare_num.length)
		{
			//��������ͬ,��Ӹ�λ��ʼÿһλ�Ƚ�
			for (int i = length - 1; i >= 0; i--)
			{
				if (num[i] > compare_num.num[i])
					return true;
				if (num[i] < compare_num.num[i])
					return false;
			}
			//������ȫ��ȵ����
			return true;
		}
	}

	if (!is_positive && !compare_num.is_positive)
	{
		//�ȱȽ����߳���
		if (length > compare_num.length)
			return false;
		if (length < compare_num.length)
			return true;
		if (length == compare_num.length)
		{
			//��������ͬ,��Ӹ�λ��ʼÿһλ�Ƚ�
			for (int i = length - 1; i >= 0; i--)
			{
				if (num[i] > compare_num.num[i])
					return false;
				if (num[i] < compare_num.num[i])
					return true;
			}
			//������ȫ��ȵ����
			return true;
		}
	}
}

/*
	����<=�����

	@param[in] const bignum& compare_num:��֮�ȽϵĴ�����

	@return bool
*/
bool bignum::operator<=(const bignum& compare_num)
{
	//���ȱȽ����߷���,�����Ų�ͬ,ֱ���ж�
	if (is_positive && !compare_num.is_positive)
		return false;

	if (!is_positive && compare_num.is_positive)
		return true;

	//��������ͬ,����Ҫ��һ���ж�
	if (is_positive && compare_num.is_positive)
	{
		//�ȱȽ����߳���
		if (length > compare_num.length)
			return false;
		if (length < compare_num.length)
			return true;
		if (length == compare_num.length)
		{
			//��������ͬ,��Ӹ�λ��ʼÿһλ�Ƚ�
			for (int i = length - 1; i >= 0; i--)
			{
				if (num[i] > compare_num.num[i])
					return false;
				if (num[i] < compare_num.num[i])
					return true;
			}
			//������ȫ��ȵ����
			return true;
		}
	}

	if (!is_positive && !compare_num.is_positive)
	{
		//�ȱȽ����߳���
		if (length > compare_num.length)
			return true;
		if (length < compare_num.length)
			return false;
		if (length == compare_num.length)
		{
			//��������ͬ,��Ӹ�λ��ʼÿһλ�Ƚ�
			for (int i = length - 1; i >= 0; i--)
			{
				if (num[i] > compare_num.num[i])
					return true;
				if (num[i] < compare_num.num[i])
					return false;
			}
			//������ȫ��ȵ����
			return true;
		}
	}
}

/*
	����+�����

	@param[in] const bignum& add_num:����

	@return bignum:��
*/
bignum bignum::operator+(const bignum& add_num)
{
	bignum result;	//Ҫ���صĽ��

	if (is_positive && add_num.is_positive || !is_positive && !add_num.is_positive)	//�����������������ͬʱ,�൱�ڼӷ�
	{
		int carry = 0;	//��λ
		int result_index = 0;	//���������±�,ÿ��һλ,�±��һ
		int temp = 0;	//��¼�ӷ������� ������,������ͬһλ �� ��λ ����֮��

		//���Ƚ�������,����,�� �洢��������ͬ��������
		int* added_num;	//�洢������������
		int* _add_num;	//�洢����������
		int* result_num;	//�洢���������
		added_num = new int[length + add_num.length];
		_add_num = new int[length + add_num.length];
		result_num = new int[length + add_num.length];

		//��ÿһ�����鸳ֵ,����ĸ�ֵΪ��
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

		//----------------�߾��ȼӷ������㷨----------------
		//�ο�����: https://blog.csdn.net/weifenglin1997/article/details/78748998
		for (int i = 0; i < length || i < add_num.length; i++)
		{
			temp = added_num[i] + _add_num[i] + carry;	//����,��¼�ӷ������� ������,������ͬһλ �� ��λ ����֮��
			result_num[result_index] = temp % 10;	//�����ͬһλ ���� temp��10������
			result_index++;	//��¼������һλ��,������±��һ,׼����¼�������һλ
			carry = temp / 10;	//��λ���� temp��10
		}
		if (carry != 0)	//������һλ�Ľ�λ��Ϊ0,ֱ�Ӹ�����������λ
		{
			result_num[result_index] = carry;
			result_index++;
		}
		//----------------------------------------------------

		//�ӷ�(���߷�����ͬ)�������,���洢���������ת�Ƹ�������
		delete result.num;
		result.num = new int[result_index];
		result.length = result_index;
		for (int i = 0; i < result_index; i++)
			result.num[i] = result_num[i];

		if (is_positive && add_num.is_positive)	//������������������������,��ʱ��Ϊ����
		{
			result.is_positive = true;
			return result;
		}
		else if (!is_positive && !add_num.is_positive)	//��������������Ǹ��������,��ʱ��Ϊ����
		{
			result.is_positive = false;
			return result;
		}
	}
	else  //��������������Ų�ͬʱ,�൱�ڼ���
	{
		if (is_positive && !add_num.is_positive)	//������Ϊ��,����Ϊ�������
		{
			bignum absed_num(add_num);	//���Ȼ�ȡ�����ľ���ֵ
			absed_num.is_positive = true;
			if (*this == absed_num)	//���������������ľ���ֵ���,������
				return result;

			int result_index = 0;	//���������±�,ÿ��һλ,�±��һ
			int* subed_num;	//�洢������������
			int* _sub_num;	//�洢����������
			int* result_num;	//�洢���������
			subed_num = new int[length + absed_num.length];
			_sub_num = new int[length + absed_num.length];
			result_num = new int[length + absed_num.length];

			if (*this > absed_num)	//�����������ڼ����ľ���ֵʱ,�൱�� ������ - ����
			{
				//��ʱ,������ ��ֵ�� �洢������������,���� ��ֵ�� �洢����������
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
			else if (*this < absed_num)	//��������С�ڼ����ľ���ֵʱ,�൱�� ���� - ������
			{
				//��ʱ,���� ��ֵ�� �洢������������,������ ��ֵ�� �洢����������
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

			//----------------�߾��ȼ��������㷨----------------
			//�ο�����: https://blog.csdn.net/weifenglin1997/article/details/78748998
			for (int i = 0; i < length || i < absed_num.length; i++)
			{
				if (subed_num[i] < _sub_num[i])	//�����������,�����λ��λ
					if (subed_num[i + 1] > 0)
					{
						subed_num[i + 1]--;
						subed_num[i] += 10;
					}
				result_num[result_index] = subed_num[i] - _sub_num[i];
				result_index++;
			}
			while (result_index - 1 >= 1 && result_num[result_index - 1] == 0)	//ȥ����λΪ0����,ͬʱ����һ�����λ
				result_index--;
			//----------------------------------------------------

			//�ӷ�(���߷��Ų�ͬ)�������,���洢���������ת�Ƹ�������
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
		else if (!is_positive && add_num.is_positive)	//������Ϊ��,����Ϊ�������
		{
			bignum absed_num(*this);	//���Ȼ�ȡ�������ľ���ֵ
			absed_num.is_positive = true;
			if (absed_num == add_num)	//����������ľ���ֵ��������,������
				return result;

			int result_index = 0;	//���������±�,ÿ��һλ,�±��һ
			int* subed_num;	//�洢������������
			int* _sub_num;	//�洢����������
			int* result_num;	//�洢���������
			subed_num = new int[length + add_num.length];
			_sub_num = new int[length + add_num.length];
			result_num = new int[length + add_num.length];

			if (absed_num > add_num)	//���������ľ���ֵ���ڼ���ʱ,�൱�� ������ - ����
			{
				//��ʱ,������ ��ֵ�� �洢������������,���� ��ֵ�� �洢����������
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
			else if (absed_num < add_num)	//���������ľ���ֵС�ڼ���ʱ,�൱�� ���� - ������
			{
				//��ʱ,���� ��ֵ�� �洢������������,������ ��ֵ�� �洢����������
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

			//----------------�߾��ȼ��������㷨----------------
			//�ο�����: https://blog.csdn.net/weifenglin1997/article/details/78748998
			for (int i = 0; i < length || i < add_num.length; i++)
			{
				if (subed_num[i] < _sub_num[i])	//�����������,�����λ��λ
					if (subed_num[i + 1] > 0)
					{
						subed_num[i + 1]--;
						subed_num[i] += 10;
					}
				result_num[result_index] = subed_num[i] - _sub_num[i];
				result_index++;
			}
			while (result_index - 1 >= 1 && result_num[result_index - 1] == 0)	//ȥ����λΪ0����,ͬʱ����һ�����λ
				result_index--;
			//----------------------------------------------------

			//�ӷ�(���߷��Ų�ͬ)�������,���洢���������ת�Ƹ�������
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

	@param[in] const bignum& sub_num:����

	@return bignum:��
*/
bignum bignum::operator-(const bignum& sub_num)
{
	bignum result;	//Ҫ���صĽ��
	if (*this == sub_num)	//����������������,������
		return result;

	if (is_positive && sub_num.is_positive || !is_positive && !sub_num.is_positive)	//�������������������ͬʱ,��ʱ�൱�ڼ���
	{
		int result_index = 0;	//������±�
		int* subed_num;	//�洢������������
		int* _sub_num;	//�洢����������
		int* result_num;	//�洢���������
		subed_num = new int[length + sub_num.length];
		_sub_num = new int[length + sub_num.length];
		result_num = new int[length + sub_num.length];

		if (*this > sub_num && is_positive && sub_num.is_positive || *this < sub_num && !is_positive && !sub_num.is_positive)
		{
			//�� �������������Ϊ���� �� ���������ڼ��� ���� �� �������������Ϊ���� �� ������С�ڼ���
			//��ʱ�൱�� ������ - ����
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
			//�� �������������Ϊ���� �� ������С�ڼ��� ���� �� �������������Ϊ���� �� ���������ڼ���
			//��ʱ�൱�� ���� - ������
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

		//----------------�߾��ȼ��������㷨----------------
		//�ο�����: https://blog.csdn.net/weifenglin1997/article/details/78748998
		for (int i = 0; i < length || i < sub_num.length; i++)
		{
			if (subed_num[i] < _sub_num[i])	//�����������,�����λ��λ
				if (subed_num[i + 1] > 0)
				{
					subed_num[i + 1]--;
					subed_num[i] += 10;
				}
			result_num[result_index] = subed_num[i] - _sub_num[i];
			result_index++;
		}
		while (result_index - 1 >= 1 && result_num[result_index - 1] == 0)	//ȥ����λΪ0����,ͬʱ����һ�����λ
			result_index--;
		//----------------------------------------------------

		//����(���߷�����ͬ)�������,���洢���������ת�Ƹ�������
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
	else  //����������������Ų�ͬʱ,��ʱ�൱�ڼӷ�
	{
		int carry = 0;	//��λ
		int result_index = 0;	//���������±�,ÿ��һλ,�±��һ
		int temp = 0;	//��¼�ӷ������� ������,������ͬһλ �� ��λ ����֮��
		int* added_num;	//�洢������������
		int* _add_num;	//�洢����������
		int* result_num;	//�洢���������
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

		//----------------�߾��ȼӷ������㷨----------------
		//�ο�����: https://blog.csdn.net/weifenglin1997/article/details/78748998
		for (int i = 0; i < length || i < sub_num.length; i++)
		{
			temp = added_num[i] + _add_num[i] + carry;	//����,��¼�ӷ������� ������,������ͬһλ �� ��λ ����֮��
			result_num[result_index] = temp % 10;	//�����ͬһλ ���� temp��10������
			result_index++;	//��¼������һλ��,������±��һ,׼����¼�������һλ
			carry = temp / 10;	//��λ���� temp��10
		}
		if (carry != 0)	//������һλ�Ľ�λ��Ϊ0,ֱ�Ӹ�����������λ
		{
			result_num[result_index] = carry;
			result_index++;
		}
		//----------------------------------------------------

		//����(���߷��Ų�ͬ)�������,���洢���������ת�Ƹ�������
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

	@param[in] const bignum& mul_num:����

	@return bignum:��
*/
bignum bignum::operator*(const bignum& mul_num)
{
	bignum result;	//Ҫ���صĽ��
	if (length == 1 && num[0] == 0 || mul_num.length == 1 && mul_num.num[0] == 0)
		return result;	//��������������������һ��Ϊ��,�򷵻���
	
	int* result_num;	//�洢���������
	int* muled_num;	//�洢������������
	int* _mul_num;	//�洢����������
	int result_length = length + mul_num.length;
	result_num = new int[length + mul_num.length + 1];
	muled_num = new int[length + mul_num.length + 1];
	_mul_num = new int[length + mul_num.length + 1];
	result_num[0] = 0;
	muled_num[0] = 0;
	_mul_num[0] = 0;
	
	//�Ѵ�������ֵ��ֵ������
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

	//----------------�߾��ȳ˷������㷨----------------
	//�ο�����: https://blog.csdn.net/bxg1065283526/article/details/79782098
	for (int i = 1; i <= length; i++)
		for (int j = 1; j <= mul_num.length; j++)	//ע��:ѭ���� i = 1 �� j = 1 ��ʼ,�����������������ÿһλ
		{
			result_num[i + j - 1] += muled_num[i] * _mul_num[j];	//��������ĳһλ �� ������ĳһλ ���,�� ��� ��Ӧ��λ�� �ۻ��� ��λ ���
			result_num[i + j] += result_num[i + j - 1] / 10;	//�������һλ ��ʼ�ۻ� ��λ,�� ��һ���������ֵ �� 10 �� ��
			result_num[i + j - 1] %= 10;	//�����λ������,�������һλ ֻȡ ��λ �ϵ�ֵ
		}

	while (result_num[result_length] == 0 && result_length > 1)	//ȥ����λ�������
		result_length--;
	//----------------------------------------------------

	//�˷����������,���洢���������ת���ɴ�����
	result.length = result_length;
	delete result.num;
	result.num = new int[result_length];
	for (int i = 1; i <= result_length; i++)
		result.num[i - 1] = result_num[i];

	if (is_positive && mul_num.is_positive || !is_positive && !mul_num.is_positive)
		result.is_positive = true;	//���������������ķ�����ͬ,�����ķ���Ϊ��
	else if (is_positive && !mul_num.is_positive || !is_positive && mul_num.is_positive)
		result.is_positive = false;	//���������������ķ��Ų�ͬ,�����ķ���Ϊ��

	return result;
}

/*
	����/�����

	@param[in] const bignum& div_num:����

	@return bignum:��
*/
bignum bignum::operator/(const bignum& div_num)
{
	bignum result;	//Ҫ���صĽ��

	//���� ��ȡ������������ľ���ֵ
	bignum _abs(*this);
	_abs.is_positive = true;
	bignum abs_div_num(div_num);
	abs_div_num.is_positive = true;

	if (abs_div_num.length == 1 && abs_div_num.num[0] == 0)	//�������Ϊ��,�򷵻���
	{
		cout << "�������������:���ܳ�0" << endl;
		return result;
	}
	if (_abs.length == 1 && _abs.num[0] == 0)	//ͬ��,���������Ϊ��,�򷵻���
		return result;

	if (_abs < abs_div_num)	//��� �������ľ���ֵ С�� �����ľ���ֵ,�򷵻���
		return result;
	else if (_abs == abs_div_num)	//��� �������ľ���ֵ ���� �����ľ���ֵ,�򷵻� +1 �� -1
	{
		result.num[0] = 1;
		if (is_positive && div_num.is_positive || !is_positive && !div_num.is_positive)
			result.is_positive = true;
		else if (is_positive && !div_num.is_positive || !is_positive && div_num.is_positive)
			result.is_positive = false;
		return result;
	}
	else  //��������Ĺ��˺�,�������ľ���ֵ �϶����� �����ľ���ֵ
	{
		bignum int_max("999999999");
		if (abs_div_num <= int_max)	//������Ϊ�;�����ʱ
		{
			int _div_num_int = bignumToInt(abs_div_num);	//�Ȱѳ���ת��Ϊint����
			int result_length = _abs.length;
			int rem_num = 0;	//����
			int* result_num;	//�洢���������
			int* dived_num;	//�洢������������
			result_num = new int[length + div_num.length];
			dived_num= new int[length + div_num.length];

			//��������ת�Ƶ�������
			for (int i = 0; i < length + div_num.length; i++)
			{
				if (i < length)
					dived_num[i] = _abs.num[i];
				else
					dived_num[i] = 0;

				result_num[i] = 0;
			}

			//----------------�߾��ȳ��;��Ⱥ����㷨----------------
			//�ο�����: https://www.cnblogs.com/lfyzoi/p/6737761.html
			for (int i = result_length - 1; i >= 0; i--)	//�Ӹ�λ���λ����
			{
				rem_num = rem_num * 10 + dived_num[i];	//��һ��ѭ���õ��� ���� ��10,�ټ��� ��������ĳһλ
				result_num[i] = rem_num / _div_num_int;	//��һ�еõ���ֵ �� �;��ȵĳ��� ���� �����Ӧ��λ��ֵ
				rem_num %= _div_num_int;	//����������,�µ��������� ���� ģ�� ����,����һ��ѭ����
			}
			
			while (result_length - 1 >= 1 && result_num[result_length - 1] == 0)	//ȥ����λ�������
				result_length--;
			//---------------------------------------------------------

			//����(�߾��ȳ��;���)������,�Ѵ洢���������ת���ɴ�����
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
		else //������Ϊ�߾���ʱ
		{	
			int* result_num;	//�洢���������
			int* dived_num;	//�洢������������
			int* _div_num;	//�洢����������
			int result_length = length;
			int dived_num_length = length;
			int div_num_length = div_num.length;
			int nTimes = 0;
			int nTemps = 0;

			result_num = new int[length + div_num.length];
			dived_num = new int[length + div_num.length];
			_div_num = new int[length + div_num.length];

			//��������ת��Ϊ����
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
			
			//----------------�߾��ȳ��߾��Ⱥ����㷨----------------
			//�ο�����: https://blog.csdn.net/ljq199926/article/details/79343823
			nTimes = dived_num_length - div_num_length;
			for (int i = dived_num_length - 1; i >= 0; i--)	//����,�������ĵ�λ���� �� λ���뱻�������
			{
				if (i >= nTimes)
					_div_num[i] = _div_num[i - nTimes];
				else
					_div_num[i] = 0;
			}
			div_num_length = dived_num_length;

			for (int i = 0; i <= nTimes; i++)	//Ȼ��,�����ܰ������������ �� ������ �� ���� ���
			{
				while ((nTemps = SubStract(dived_num, _div_num + i, dived_num_length, div_num_length - i)) >= 0)
				{
					dived_num_length = nTemps;
					result_num[nTimes - i]++;	//���ɹ���,�������Ӧ��������һ
				}
				//�����ɹ�,��������һ��������,������
			}

			while (result_length - 1 >= 1 && result_num[result_length - 1] == 0)	//������ɺ�,�������λ����ȥ��
				result_length--;
			//---------------------------------------------------------

			//����(�߾��ȳ��߾���)������,�Ѵ洢���������ת���ɴ�����
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

	@param[in] const bignum& div_num:����

	@return bignum:����
*/
bignum bignum::operator%(const bignum& div_num)
{
	bignum result;	//Ҫ���صĽ��

	//���� ��ȡ������������ľ���ֵ
	bignum _abs(*this);
	_abs.is_positive = true;
	bignum abs_div_num(div_num);
	abs_div_num.is_positive = true;

	if (abs_div_num.length == 1 && abs_div_num.num[0] == 0)	//�������Ϊ��,�򷵻���
	{
		cout << "ȡ�����������:���ܳ�0" << endl;
		return result;
	}
	if (_abs.length == 1 && _abs.num[0] == 0)	//ͬ��,���������Ϊ��,�򷵻���
		return result;

	if (_abs < abs_div_num)	//��� �������ľ���ֵ С�� �����ľ���ֵ,�򷵻ر�����
	{
		result = _abs;
		result.is_positive = is_positive;
		return result;
	}
	else if (_abs == abs_div_num)	//��� �������ľ���ֵ ���� �����ľ���ֵ,�򷵻���
		return result;
	else  //��������Ĺ��˺�,�������ľ���ֵ �϶����� �����ľ���ֵ
	{
		bignum int_max("999999999");
		if (abs_div_num <= int_max)	//����Ϊ�;����������
		{
			int ans = 0;
			int div_num_int = bignumToInt(abs_div_num);

			//----------------�߾���ȡ��;��Ⱥ����㷨----------------
			//�ο�����: https://blog.csdn.net/qq_42217376/article/details/86722805
			for (int i = _abs.length - 1; i >= 0; i--)
			{
				ans = (10 * ans + _abs.num[i]) % div_num_int;
			}
			//-----------------------------------------------------------

			//�����ת���ɴ�����
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

	@param[in] const bignum& add_num:����

	@return bignum
*/
bignum bignum::operator+=(const bignum& add_num)
{
	*this = *this + add_num;
	return *this;
}

/*
	����-=�����

	@param[in] const bignum& sub_num:����

	@return bignum
*/
bignum bignum::operator-=(const bignum& sub_num)
{
	*this = *this - sub_num;
	return *this;
}

/*
	����*=�����

	@param[in] const bignum& mul_num:����

	@return bignum
*/
bignum bignum::operator*=(const bignum& mul_num)
{
	*this = *this * mul_num;
	return *this;
}

/*
	����/=�����

	@param[in] const bignum& div_num:����

	@return bignum
*/
bignum bignum::operator/=(const bignum& div_num)
{
	*this = *this / div_num;
	return *this;
}

/*
	����%=�����

	@param[in] const bignum& div_num:����

	@return bignum
*/
bignum bignum::operator%=(const bignum& div_num)
{
	*this = *this % div_num;
	return *this;
}

/*
	����++ǰ׺�����

	@return bignum
*/
bignum bignum::operator++()
{
	bignum added("1");
	*this = *this + added;
	return *this;
}

/*
	����++��׺�����

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
	����--ǰ׺�����

	@return bignum
*/
bignum bignum::operator--()
{
	bignum subed("1");
	*this = *this - subed;
	return *this;
}

/*
	����--��׺�����

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
	������תint����

	@param[in] const bignum& _num:Ҫת���Ĵ�����

	@return int
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

	@param[in] int r:����

	@return bignum
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

	@param[in] int* p1:������
	@param[in] int* p2:����
	@param[in] int len1:�������ĳ���
	@param[in] int len2:�����ĳ���

	@return int
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

	@param[in] ostream& os:�����
	@param[in] bignum num:������

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

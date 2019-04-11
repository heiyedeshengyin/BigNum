# BigNum
�������������,�߾��ȼ���

### ���
��ĿǰΪֹд����Ĵ���  
�߾��ȼ��㣬ָ����λ���Ĵ�����֮�������

### ���ݽṹ
```cpp
class bignum
{
	int* num;	//�洢������������,���õ���洢
	int length;	//��������λ��
	bool is_positive;	//�������ķ���,trueΪ��,falseΪ��,ע��:0Ϊ����
};
```

### ���ص������
˫Ŀ����������� + (��)��-(��)��*(��)��/(��)��% (ȡģ)  
��ϵ������� ==(����)��!= (������)��< (С��)��> (����>��<=(С�ڵ���)��>=(���ڵ���)  
�����Լ��������++(����)��--(�Լ�)  
��ֵ�������=, +=, -=, *=, /= , %=  

### �����б�
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
bignum operator*(const bignum& mul_num);	//����\*�����  
bignum operator/(const bignum& div_num);	//����/�����  
bignum operator%(const bignum& div_num);	//����%�����  
bignum operator+=(const bignum& add_num);	//����+=�����  
bignum operator-=(const bignum& sub_num);	//����-=�����  
bignum operator*=(const bignum& mul_num);	//����*=�����  
bignum operator/=(const bignum& div_num);	//����/=�����  
bignum operator%=(const bignum& div_num);	//����%=�����  
bignum operator++();	//����+\+ǰ׺�����  
bignum operator++(int);	//����++��׺�����  
bignum operator--();	//����--ǰ׺�����  
bignum operator--(int);	//����--��׺�����  
friend int bignumToInt(const bignum& _num);	//������תint����  
bignum fac(int r);	//��׳�  
int SubStract(int* p1, int* p2, int len1, int len2);	//����֮��ļ���  
ostream& operator<<(ostream& os, bignum num);	//����<<�����  

### ʹ��˵��
���ؽ�ѹ����Visual Studio��BigNum.sln����

### �ο�����
[CSDN C++ʵ�ָ߾��ȴ�����������������������](https://blog.csdn.net/weifenglin1997/article/details/78748998)
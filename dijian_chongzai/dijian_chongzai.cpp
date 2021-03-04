#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//实现递减运算符重载
class MyInteger
{
	friend ostream& operator<<(ostream& cout, MyInteger myint);
public:
	MyInteger();
	MyInteger& operator--();
	MyInteger operator--(int);
private:
	int m_Num;
};
ostream& operator<<(ostream& cout, MyInteger myint)
{
	cout << myint.m_Num << endl;
	return cout;
}
MyInteger::MyInteger()
{
	m_Num = 1;
}
MyInteger& MyInteger::operator--()
{
	this->m_Num--;
	return *this;
}
MyInteger MyInteger::operator--(int)
{
	MyInteger temp;
	temp = *this;
	m_Num--;
	return temp;
}

void test01()
{
	MyInteger myint;
	cout << --myint << endl;
	cout << myint << endl;
}
void test02()
{
	MyInteger myint;
	cout << myint-- << endl;
	cout << myint << endl;
}
int main()
{
	//test01();
	test02();
	system("pause");
	return 0;

}
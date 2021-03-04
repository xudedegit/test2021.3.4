#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//µİÔöÔËËã·ûÖØÔØ
class MyInteger
{
	friend ostream& operator<<(ostream& cout, MyInteger myint);
public:
	MyInteger();
	MyInteger& operator++()
	{
		this->m_Num++;
		return *this;
	}
	MyInteger operator++(int)
	{
		MyInteger temp;
		temp = *this;
		m_Num++;
		return temp;

	}
private:
	int m_Num;
};
MyInteger::MyInteger()
{
	m_Num = 0;
}
ostream& operator<<(ostream& cout, MyInteger myint)
{
	cout << myint.m_Num << endl;
	return cout;
}
void test01()
{
	MyInteger myint;
	cout << ++myint << endl;

	cout << myint << endl;
}
void test02()
{
	MyInteger myint;
	cout << myint++ << endl;
	cout << myint << endl;
}
int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}
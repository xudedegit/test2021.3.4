#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//赋值运算符重载函数
class person
{
	friend void test01();
public:
	person(int age)
	{
		m_Age = new int (age);
	}
	~person()
	{
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
	}
	person& operator=(person& p)
	{
		if (m_Age != NULL)     //将原本的调用该重载函数的对象（p1）中在堆区开辟的空间（p1(24)）释放干净，
			                      //释放干净之后再进行重新开辟，并赋值
		{
			delete m_Age;
			m_Age = NULL;
		}
		m_Age = new int(*p.m_Age);
		return *this;
	}
private:
	int* m_Age;

};
void test01()
{
	person p1(24);
	person p2(18);
	person p3(30);
	p3 = p1 = p2;
	cout << "p1的年龄为：" << *p1.m_Age << endl;
	cout << "p2的年龄为：" << *p2.m_Age << endl;
	cout << "p3的年龄为：" << *p3.m_Age << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;

}
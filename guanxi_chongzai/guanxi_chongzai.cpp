#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//关系运算符重载函数
class person
{
public:
	person(string name, int age)
	{
		m_Name = name;
		m_Age = age;
	}
	//重载关系运算符==

	int operator==(person &p)
	{
		if ((this->m_Name == p.m_Name) && this->m_Age == p.m_Age)
		{
			return 1;
		}
		else
		{
			return 0;
		}
		
	}
	bool operator!=(person& p)
	{
		if ((this->m_Age != p.m_Age) || (this->m_Name != p.m_Name))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
private:
	string m_Name;
	int m_Age;
};
void test01()
{
	person p1("Jack", 17);
	person p2("Jack", 18);
	if (p1 == p2)
	{
		cout << "p1和p2是同一个人" << endl;
	}
	else
	{
		cout << "p1和p2不是同一个人" << endl;
	}
}
void test02()
{
	person p1("Jack", 17);
	person p2("Jack", 18);
	if (p1 != p2)
	{
		cout << "p1和p2不是同一个人" << endl;
	}
	else
	{
		cout << "p1和p2是同一个人" << endl;
	}
}
int main()
{
	//test01();
	test02();
	system("pause");
	return 0;

}
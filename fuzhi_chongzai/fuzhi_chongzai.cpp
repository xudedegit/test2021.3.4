#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//��ֵ��������غ���
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
		if (m_Age != NULL)     //��ԭ���ĵ��ø����غ����Ķ���p1�����ڶ������ٵĿռ䣨p1(24)���ͷŸɾ���
			                      //�ͷŸɾ�֮���ٽ������¿��٣�����ֵ
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
	cout << "p1������Ϊ��" << *p1.m_Age << endl;
	cout << "p2������Ϊ��" << *p2.m_Age << endl;
	cout << "p3������Ϊ��" << *p3.m_Age << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;

}
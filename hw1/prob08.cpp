#include <prob08.cpp>
#include <iostream>

using namespace std;

class ClassOne
{
	public:
		ClassOne()
		{
			cout << "ClassOne default constructor called" << endl;
		}

		ClassOne(int, int)
		{
			
			cout << "ClassOne alternate constructor called" << endl;
		}

		int m_member1;
		int func1();

	private:
		int member2;
		void func2(int);
};

class ClassTwo
{
	public:
		ClassTwo()
		{
			cout << "ClassTwo default constructor called" << endl;
		}

		ClassTwo(double)
		{
			cout << "ClassTwo alternate constructor called" << endl;
		}

		ClassOne m_data1;
		double m_data2;
};

int main()
{
	ClassTwo *ptr;
	ptr = new ClassTwo(3.1);

	cout << "m_member1: " << ptr->m_data1.m_member1 << endl;
}

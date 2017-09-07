#include <iostream>
#include <prob08.cpp>

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

int ClassOne::func1()
{
	func2(0);
}

void ClassOne::func2(int i)
{
	return;
}

int main()
{
//	ClassOne* ptr;
//	ptr->func2(3);
}

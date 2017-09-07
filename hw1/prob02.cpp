#include <iostream>

using namespace std;

class Box
{
	public:
		Box()
		{
			cout << "Default constructor called" << endl;
		}	
};

int main()
{
	Box *ptr;
	ptr = new Box[5];

	return 0;
}

#include <iostream>

using namespace std;

int main() {
	int m = 5, n = 7;
	int *p;

	p = &n;
	*p = 2 * n + m;
	*p = 2 * n + m;
	p = &m;
	*p = 2 * n + m;
	*p = 2 * n + m;

	cout << "m = " << m << ", ";
	cout << "n = " << n << ", ";
	cout << "*p = " << *p << endl;

	return 0;
}

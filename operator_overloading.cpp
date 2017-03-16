// operator_overloading.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class two_dimensional {
	int x, y;
public:
	two_dimensional() { x = y = 0; }
	two_dimensional(int i, int j) { x = i; y = j; }
	two_dimensional operator+(two_dimensional op2);
	two_dimensional operator=(two_dimensional op2);

	void show();
};
two_dimensional two_dimensional::operator+(two_dimensional op2)
{
	two_dimensional temp;
	temp.x = x + op2.x;
	temp.y = y + op2.y;
	return temp;
}
two_dimensional two_dimensional::operator=(two_dimensional op2)
{
	x = op2.x;
	y = op2.y;
	return *this;
}
void two_dimensional::show()
{
	cout << x << ", ";
	cout << y << "\n";
}
int main()
{
	two_dimensional a(7, 3), b(2, 9), c;

	a.show();
	b.show();

	c = a + b;
	c.show();

	c = a + b + c;
	c.show();

	c = b = a;
	c.show();
	b.show();

	system("pause");
	return 0;
}
// LR3-2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class MyMoney
{
public:
	string name;
	double money;
	double rate;
	int time;
	double getMoney()
	{
		double s = money;
		for (int k = 1; k <= time; ++k)
		{
			s *= (1 + rate / 100);
		}
		return s;
	}
	void showAll()
	{
		cout << "Full Name:" << name << endl;
		cout << "Deposit:" << money << endl;
		cout << "Rate(%):" << rate << endl;
		cout << "Time(years):" << time << endl;
		cout << "Final Sum:" << getMoney() << endl;
		for (int k = 1; k < 35; ++k) {
			cout << "-";
		}
		cout << endl;
	}
	void setAll(string n, double m, double r, int t)
	{
		name = n;
		money = m;
		rate = r;
		time = t;
	}
	MyMoney(string n, double m, double r, int t) {
		setAll(n, m, r, t);
	}
	MyMoney()
	{
		setAll("", 0, 0, 0);
	}
};
class BigMoney :public MyMoney {
public:
	int periods;
	double getMoney() {
		double s = money;
		for (int k = 1; k <= time*periods; ++k)
		{
			s *= (1 + rate / 100 / periods);
		}
		return s;
	}
void showAll()
{
	cout << "Full Name:" << name << endl;
	cout << "Deposit:" << money << endl;
	cout << "Rate(%):" << rate << endl;
	cout << "Time(years):" << time << endl;
	cout << "Accruals per year:" << periods << endl;
	cout << "Final Sum:" << getMoney() << endl;
	for (int k = 1; k < 35; ++k) {
		cout << "-";
	}
	cout << endl;
}
void setAll(string n, double m, double r, int t, int p) {
	MyMoney::setAll(n, m, r, t);
	periods = p;
}
BigMoney(string n, double m, double r, int t, int p = 1) :MyMoney(n, m, r, t) {
	periods = p;
}
BigMoney() :MyMoney() {
	periods = 1;
}
};


int main()
{
	MyMoney objA("Romanov Roman Dmitrievich", 3000, 3, 10);
	BigMoney objB("Jesters Lawrence Rostislavovich", 200, 3, 2, 2);
	BigMoney objC("Kuklow Dmitry Anatolyevich", 8000, 13, 9);
	BigMoney objD;
	objD.setAll("Kaktusistov Lavrushey Cheburashek", 200, 3, 2, 4);
	objA.showAll();
	cout << endl;
	objB.showAll();
	cout << endl;
	objC.showAll();
	cout << endl;
	objD.showAll();
	system("pause");
    return 0;
}


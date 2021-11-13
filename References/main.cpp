#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	int a = 2;
	int& ra = a;
	cout << ra << endl;		// 2
	ra += 3;
	cout << a << endl;		// 5
	cout << &a << endl;		// 008FF89C
	cout << &ra << endl;	// 008FF89C такой же адрес, т.к. ссылка уже разыменована

}
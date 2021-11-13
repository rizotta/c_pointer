#include<iostream>
using namespace std;

//#define POINTERS_BASICS
#define POINTERS_AND_ARRAYS

void main()
{
	setlocale(LC_ALL, "");

#ifdef POINTERS_BASICS

	int a = 2;
	int* pa = &a;	// pa - pointer to 'a' (ptr)

	cout << a << endl;	// ����� �������� ���������� 'a' �� �����
	cout << &a << endl;	// ��������� ������ ���������� 'a' ����� ��� ������ 
	cout << pa << endl;	// ����� ������ ���������� 'a', ����������� � ��������� 'pa'
	cout << *pa << endl;// ������������� ��������� 'pa' � ��������� �������� �� ������ � ���� ���������


	int* pb;
	int b = 3;
	pb = &b; // (int*) (int*)
	// *pb = &b; // ������, �.�. � �������� �� ������ �������� �������� �����

	// int - int
	// int* - ��������� �� ��� int
	// double - double
	// double* - ��������� �� double

	cout << b << endl;
	cout << pb << endl;

#endif // POINTERS_BASICS

#ifdef POINTERS_AND_ARRAYS

	const int n = 5;
	int arr[n] = { 3,5,8,13,21 };
	cout << *arr << endl;

	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;

#endif // POINTERS_AND_ARRAYS
}
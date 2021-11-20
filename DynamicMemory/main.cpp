#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int* arr, const int n);

void main()
{
	setlocale(LC_ALL, "");
	int n; // размер массива
	cout << "Введите размер массива: "; 	
	cin >> n;

	int* arr = new int[n]; // объявление динамического массива

	FillRand(arr, n);
	Print(arr, n);

	delete[] arr; // удаление динамического массива
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		// обращение через арифметику указателей и оператор разыменования
		*(arr + i) = rand() % 100;
	}
}

void Print(int* arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		// обращение через оператор индексирования
		cout << arr[i] << "\t"; // оператор индексирования возвращает значение по индексу
	}
	cout << endl;
}
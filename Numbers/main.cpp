#include<iostream>
using namespace std;
const unsigned int N = 10;

void FillRand(int arr[], const unsigned int N, int minRand = 0, int maxRand = 100);
void Print(int arr[], const unsigned int N);
int GetLengthEven(int arr[], const unsigned int N);
int GetLengthOdd(int arr[], const unsigned int N);
void FillEven(int arr[], int* arr2, const unsigned int N);
void FillOdd(int arr[], int* arr2, const unsigned int N);

void main()
{
	setlocale(LC_ALL, "");
	int arr[N];
	FillRand(arr, N);
	Print(arr, N);

	int lengthEven = GetLengthEven(arr, N);
	int* even = new int[lengthEven];
	FillEven(arr, even, N);
	Print(even, lengthEven);
	delete[] even;

	int lengthOdd = GetLengthOdd(arr, N);
	int* odd = new int[lengthOdd];
	FillOdd(arr, odd, N);
	Print(odd, lengthOdd);
	delete[] odd;
}

void FillRand(int arr[], const unsigned int N, int minRand, int maxRand)
{
	for (unsigned int i = 0; i < N; i++)
	{
		arr[i] = rand() % (maxRand - minRand) + minRand;
	}
}

void Print(int arr[], const unsigned int N)
{
	for (unsigned int i = 0; i < N; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

int GetLengthEven(int arr[], const unsigned int N)
{
	int length = 0;
	for (int unsigned i = 0; i < N; i++)
	{
		if (arr[i] % 2 == 0) {
			length++;
		}
	}
	return length;
}

int GetLengthOdd(int arr[], const unsigned int N)
{
	int length = 0;
	for (int unsigned i = 0; i < N; i++)
	{
		if (arr[i] % 2 != 0) {
			length++;
		}
	}
	return length;
}

void FillEven(int arr[], int* arr2, const unsigned int N)
{
	int j = 0;
	for (int unsigned i = 0; i < N; i++)
	{
		if (arr[i] % 2 == 0) {
			arr2[j++] = arr[i];
		}
	}
}

void FillOdd(int arr[], int* arr2, const unsigned int N)
{
	int j = 0;
	for (int unsigned i = 0; i < N; i++)
	{
		if (arr[i] % 2 != 0) {
			arr2[j++] = arr[i];
		}
	}
}
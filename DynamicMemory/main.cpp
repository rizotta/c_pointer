#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int* arr, const int n);
int* push_back(int arr[], int& n, int value); // ��������� ������� � ����� �������
int* push_front(int arr[], int& n, int value); // ��������� ������� � ������ �������
// insert - ������� � ����������� ����� - ����� ��� for, ����� ����� ������, ����� ����� ��������� ��������
int* pop_back(int arr[], int& n); // �������� ���������� ��-�� � �������
// ��� �������� ������� ��-�� � ������� - �������� �� ���������

#define DYNAMIC_MEMORY_1

void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	int n; // ������ �������
	cout << "������� ������ �������: "; 	
	cin >> n;

	int* arr = new int[n]; // ���������� ������������� �������
	//int* arr = new int[n] {}; // ���������� ������������� ������� � �������������� ������ (��-� - ����)

	FillRand(arr, n);
	Print(arr, n);

	int value; // ����������� ��������
	cout << "������� ����������� ��������: ";
	cin >> value;
	arr = push_back(arr, n, value); // ���������� ��������� ����� ������ ���-��, ���-� ������� �-� push_back
	Print(arr, n);

	cout << "������� ����������� ��������: ";
	cin >> value;
	arr = push_front(arr, n, value); 
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);

	delete[] arr; // �������� ������������� �������
#endif // DYNAMIC_MEMORY_1
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		// ��������� ����� ���������� ���������� � �������� �������������
		*(arr + i) = rand() % 100;
	}
}

void Print(int* arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		// ��������� ����� �������� ��������������
		cout << arr[i] << "\t"; // �������� �������������� ���������� �������� �� �������
	}
	cout << endl;
}

int* push_back(int arr[], int& n, int value) {
	// ����� ���������� �������� � ������
	// 1. ������ �������� ������ ������� �������
	int* buffer = new int[n + 1]{};
	// 2. �������� ���������� ���-�� ������� � ����� (��������) ������
	for (int i = 0; i < n; i++) {
		buffer[i] = arr[i];
	}
	// 3. ����� ����, ��� ������ �����������, �������� ������ ����� �������
	delete[] arr;
	// 4. ��������� ����� ������� ������� ������� ������ ������� (�� ����������� � �������)
	arr = buffer;
	// 5. ������ ����� ����� � ������� 'arr' ���������� ��� ���� �������, � ������� ����� ��������� ����������� ��-�
	arr[n] = value;
	// 6. ����� ����, ��� � ������� �������� ��� ���� ��-�, ���-�� ��� ��-� ����������� �� 1
	n++;
	return arr;
}

// �����
int* push_front(int arr[], int& n, int value) {
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++) {
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	buffer[0] = value;
	n++;
	return buffer;
}

// �������� ���������� �������� � �������
int* pop_back(int arr[], int& n) {
	int* buffer = new int[--n]{};
	for (int i = 0; i < n; i++) {
		buffer[i] = arr[i];
	}
	delete[] arr;
	return buffer;
}
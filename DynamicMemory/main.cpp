#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int* arr, const int n);
int* push_back(int arr[], int& n, int value); // добавляем элемент в конец массива
int* push_front(int arr[], int& n, int value); // добавляем элемент в начало массива
// insert - вставка в определённом месте - через два for, можно через индекс, можно через тернарный оператор
int* pop_back(int arr[], int& n); // удаление последнего эл-та в массиве
// при удалении первого эл-та в массиве - копируем со смещением

#define DYNAMIC_MEMORY_1

void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	int n; // размер массива
	cout << "Введите размер массива: "; 	
	cin >> n;

	int* arr = new int[n]; // объявление динамического массива
	//int* arr = new int[n] {}; // объявление динамического массива с инициализацией памяти (зн-я - нули)

	FillRand(arr, n);
	Print(arr, n);

	int value; // добавляемое значение
	cout << "Введите добавляемое значение: ";
	cin >> value;
	arr = push_back(arr, n, value); // необходимо запомнить адрес нового мас-ва, кот-й вернула ф-я push_back
	Print(arr, n);

	cout << "Введите добавляемое значение: ";
	cin >> value;
	arr = push_front(arr, n, value); 
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);

	delete[] arr; // удаление динамического массива
#endif // DYNAMIC_MEMORY_1
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

int* push_back(int arr[], int& n, int value) {
	// Этапы добавления значения в массив
	// 1. создаём буферный массив нужного размера
	int* buffer = new int[n + 1]{};
	// 2. копируем содержимое исх-го массива в новый (буферный) массив
	for (int i = 0; i < n; i++) {
		buffer[i] = arr[i];
	}
	// 3. после того, как данные скопированы, буферный массив можно удалить
	delete[] arr;
	// 4. подменяем адрес старого массива адресом нового массива (не обязательно в функции)
	arr = buffer;
	// 5. только после этого в массиве 'arr' появляется ещё один элемент, в который можно сохранить добавляемое зн-е
	arr[n] = value;
	// 6. после того, как в массиве появился ещё один эл-т, кол-во его эл-в увеличилось на 1
	n++;
	return arr;
}

// Добав
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

// Удаление последнего элемента в массиве
int* pop_back(int arr[], int& n) {
	int* buffer = new int[--n]{};
	for (int i = 0; i < n; i++) {
		buffer[i] = arr[i];
	}
	delete[] arr;
	return buffer;
}
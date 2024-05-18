#include<iostream>
#include<stack>

using namespace std;

#define tab "\t"

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

int* push_back(int arr[], int& n, const int value);
int* push_front(int arr[], int& n, const int value);

int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);

void main()
{
	setlocale(LC_ALL, "");
	int n = 5;
	cout << "Введите размер массива:"; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "Введите добавляемое значение:"; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);

	arr = push_front(arr, n, value);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);
	arr = pop_front(arr, n);
	Print(arr, n);

	delete[] arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
		//Обращение к элементам массива через арифметику указателей и оператор разыменования
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
		//Обращение к элементам массива через оператор индексирования []
	}
	cout << endl;
}
int* push_back(int arr[], int& n, const int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	int a = 2;
	int b = 3;
	a = b;
	arr = buffer;
	arr[n] = value;
	n++;
	return arr;
}
int* push_front(int arr[], int& n, const int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	buffer[0] = value;
	n++;
	return buffer;
}
int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	return buffer;
}
int* pop_front(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	return buffer;
}
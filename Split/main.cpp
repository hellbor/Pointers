#include<iostream>
using namespace std;

#define tab "\t"

void FillRand(int arr[], const int n);
void Print(const int arr[], const int n);
void Print(const int arr[], int even_arr[], int odd_arr[], const int n, const int m, const int k);

void main()
{
	setlocale(LC_ALL, "");
	const int n = 10;
	int* arr = new int[n];
	cout << "Выведите массив на экран:" << endl;

	FillRand(arr, n);
	Print(arr, n);

	cout << endl;

	int* even_arr = new int[n];
	cout << "Четные числа массива:" << tab;
	FillRand(even_arr, n);
	Print(even_arr, n);

	cout << endl;

	int* odd_arr = new int[n];
	cout << "Нечетные числа массива:" << tab;
	FillRand(odd_arr, n);
	Print(odd_arr, n);

	delete[] arr;
	delete[] even_arr;
	delete[] odd_arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}
void Print(const int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
}

void Print(const int arr[], int even_arr[], int odd_arr[], const int n, int m, int k)
{
	for (int i = 0; i < m; i++)
	{
		for (int i = 0; i < k; i++)
			{
				cout << (*(arr + i) % 2 == *(arr + i) ? even_arr[m] : odd_arr[k]);
			}
			cout << endl;
	}
}
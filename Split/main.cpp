#include<iostream>
using namespace std;

#define tab "\t"

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "");
	const int n = 10;
	int arr [n];
	cout << "Выведите массив на экран:" << tab;
	FillRand(arr, n);
	Print(arr, n);
	cout << endl;

	int even = 0;
	int odd = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)even++;
		else odd++;
	}
	cout << "Количество четных чисел:" << even << endl;
	cout << "Количество нечетных чисел:" << odd << endl;

	cout << endl;

	int* even_arr = new int[even];
	int* odd_arr = new int[odd];

	for (int i = 0, j = 0, k = 0; i < n; i++)
	{
		(arr[i] % 2 == 0 ? even_arr[j++] : odd_arr[k++]) = arr[i];
	}
	cout << "Четные числа массива:" << tab;
	Print(even_arr, even);

	cout << "Нечетные числа массива:" << tab;
	Print(odd_arr, odd);

	delete[] even_arr;
	delete[] odd_arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}

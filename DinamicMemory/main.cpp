﻿#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

template<typename T>T** Allocate(const int rows, const int cols);
template<typename T>void Clear(T** arr, const int rows);

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(double arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(char arr[], const int n, int minRand = 0, int maxRand = 100);

void FillRand(int** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);
void FillRand(double** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);
void FillRand(char** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);

template<typename T>void Print(T arr[], const int n);
template<typename T>void Print(T** arr, const int rows, const int cols);

template<typename T>T* push_back(T arr[], int& n, const T value);
template<typename T>T* push_front(T arr[], int& n, const T value);
template<typename T>T* insert(T arr[], int& n, const T value, const int index);

template<typename T>T* pop_back(T arr[], int& n);
template<typename T>T* pop_front(T arr[], int& n);
template<typename T>T* erase(T arr[], int& n, const int index);

template<typename T>T** push_row_back(T** arr, int& rows, const int cols);
template<typename T>T** push_row_front(T** arr, int& rows, const int cols);
template<typename T>T** insert_row(T** arr, int& rows, const int cols, int position);

template<typename T>T** pop_row_back(T** arr, int& rows, const int cols);
template<typename T>T** pop_row_front(T** arr, int& rows, const int cols);
template<typename T>T** erase_row(T** arr, int& rows, const int cols, const int index);

template<typename T>T** push_col_back(T** arr, const int rows, int& cols);
template<typename T>T** push_col_front(T** arr, const int rows, int& cols);
template<typename T>T** insert_col(T** arr, const int rows, int& cols, const int index);

template<typename T>T** pop_col_back(T** arr, const int rows, int& cols);
template<typename T>T** pop_col_front(T** arr, const int rows, int& cols);
template<typename T>T** erase_col(T** arr, const int rows, int& cols, const int index);

//#define DINAMIC_MEMORY_1
#define DINAMIC_MEMORY_2
//#define SYNTAX

void main()
{
	setlocale(LC_ALL, "");

	typedef double DataType;

#ifdef DINAMIC_MEMORY_1
	int n = 5;
	cout << "Введите размер массива:"; cin >> n;

	DataType* arr = new DataType[n];

	FillRand(arr, n);
	Print(arr, n);

	DataType value;
	cout << "Введите добавляемое значение в конец массива:"; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);

	cout << "Введите добавляемое значение в начало массива:"; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	int index;
	cout << "Введите индекс добавляемого значения:"; cin >> index;
	cout << "Введите добавляемое значение:"; cin >> value;
	arr = insert(arr, n, value, index);
	Print(arr, n);

	cout << "Удаление значения в конце массива:" << endl;
	arr = pop_back(arr, n);
	Print(arr, n);

	cout << "Удаление значения в начале массива:" << endl;
	arr = pop_front(arr, n);
	Print(arr, n);

	cout << "Введите индекс удаляемого элемента:"; cin >> index;
	arr = erase(arr, n, index);
	Print(arr, n);

	delete[] arr;
#endif // DINAMIC_MEMORY_1

#ifdef DINAMIC_MEMORY_2
	int rows;
	int cols;
	cout << "Введите количество строк:"; cin >> rows;
	cout << "Введите количество элементов строки:"; cin >> cols;

#ifdef SYNTAX
	double** arr = new double* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new double[cols];
	}
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
#endif // SYNTAX

	DataType** arr = Allocate<DataType>(rows, cols);

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Добавление строки в конец массива:" << endl;
	arr = push_row_back(arr, rows, cols);
	FillRand(arr[rows - 1], cols, 100, 1000);
	Print(arr, rows, cols);

	cout << "Добавление строки в начало массива:" << endl;
	arr = push_row_front(arr, rows, cols);
	FillRand(arr[0], cols, 100, 1000);
	Print(arr, rows, cols);

	int index;
	cout << "Введите позицию добавляемой строки:"; cin >> index;
	arr = insert_row(arr, rows, cols, index);
	if (index < rows)FillRand(arr[index], cols, 100, 1000);
	Print(arr, rows, cols);

	cout << "Удаление последней строки в массиве:" << endl;
	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Удаление нулевой строки в массиве:" << endl;
	arr = pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Введите позицию удаляемой строки:"; cin >> index;
	arr = erase_row(arr, rows, cols, index);
	Print(arr, rows, cols);


	cout << "Добавление столбца в конец массива:" << endl;
	arr = push_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	
	cout << "Добавление столбца в начало массива:" << endl;
	arr = push_col_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Введите позицию добавляемого стролбца:"; cin >> index;
	arr = insert_col(arr, rows, cols, index);
	Print(arr, rows, cols);

	cout << "Удаление последнего столбца в массиве:" << endl;
	arr = pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Удаление нулевого столбца в массиве:" << endl;
	arr = pop_col_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Введите позицию удаляемого стролбца:"; cin >> index;
	arr = erase_col(arr, rows, cols, index);
	Print(arr, rows, cols);


	Clear(arr, rows);

#endif // DINAMIC_MEMORY_2

}

template<typename T>T** Allocate(const int rows, const int cols)
{
	T** arr = new T* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new T[cols];
	}
	return arr;
}
template<typename T>void Clear(T** arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % (maxRand - minRand) + minRand;
		//Обращение к элементам массива через арифметику указателей и оператор разыменования
	}
}
void FillRand(double arr[], const int n, int minRand, int maxRand)
{
	minRand *= 100;
	maxRand *= 100;
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % (maxRand - minRand) + minRand;
		*(arr + i) /= 100;
	}
}
void FillRand(char arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand();
	}
}

void FillRand(int** arr, const int rows, const int cols, int minRand, int maxRand)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void FillRand(double** arr, const int rows, const int cols, int minRand, int maxRand)
{
	minRand *= 100;
	maxRand *= 100;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = double(rand() % (maxRand - minRand) + minRand / 100);
		}
	}
}
void FillRand(char** arr, const int rows, const int cols, int minRand, int maxRand)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand();
		}
	}
}

template<typename T>void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
		//Обращение к элементам массива через оператор индексирования []
	}
	cout << endl;
}
template<typename T>void Print(T** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
	cout << endl;
}

template<typename T>T* push_back(T arr[], int& n, const T value)
{
	T* buffer = new T[n + 1];
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
template<typename T>T* push_front(T arr[], int& n, const T value)
{
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	buffer[0] = value;
	n++;
	return buffer;
}
template<typename T>T* insert(T arr[], int& n, const T value, const int index)
{
	T* buffer = new T[n + 1];
	/*for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}*/
	for (int i = 0; i < n; i++)
		/*{
			if (i < index)buffer[i] = arr[i];
			else buffer[i + 1] = arr[i];
		}*/
		//i < index ? buffer[i] = arr[i] : buffer[i + 1] = arr[i];
	buffer[i < index ? i : i + 1] = arr[i];

	delete[] arr;
	buffer[index] = value;
	n++;
	return buffer;
}

template<typename T>T* pop_back(T arr[], int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	return buffer;
}
template<typename T>T* pop_front(T arr[], int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	return buffer;
}
template<typename T>T* erase(T arr[], int& n, const int index)
{
	T* buffer = new T[--n];
	//for (int i = 0; i < index; i++)buffer[i] = arr[i];
	//for (int i = index; i < n; i++)buffer[i] = arr[i + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i < index ? i : i + 1];
	}
	delete[] arr;
	return buffer;
}

template<typename T>T** push_row_back(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [rows + 1];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr;
	buffer[rows] = new T[cols] {};
	rows++;
	return buffer;
}
template<typename T>T** push_row_front(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [rows + 1];
	for (int i = 0; i < rows; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[0] = new T[cols] {};
	rows++;
	return buffer;
}
template<typename T>T** insert_row(T** arr, int& rows, const int cols, int position)
{
	if (position >= rows)return arr;
	T** buffer = new T*[rows + 1];
	for (int i = 0; i < position; i++)buffer[i] = arr[i];
	for (int i = position; i < rows; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[position] = new T[cols];
	rows++;
	return buffer;
}

template<typename T>T** pop_row_back(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [--rows];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr[rows];
	delete[] arr;
	return buffer;
}
template<typename T>T** pop_row_front(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [--rows];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i + 1];
	delete[] arr[0];
	delete[] arr;
	return buffer;
}
template<typename T>T** erase_row(T** arr, int& rows, const int cols, const int index)
{
	T** buffer = new T* [--rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i < index ? i : i + 1];
	}
	delete[] arr[index];
	delete[] arr;
	return buffer;
}

template<typename T>T** push_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1];
		for (int j = 0; j < cols; j++)
		{
			buffer[j] = arr[i][j];
		}
		buffer[cols] = rand() % 100;
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
	return arr;
}
template<typename T>T** push_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1];
		for (int j = 0; j < cols; j++)
		{
			buffer[j + 1] = arr[i][j];
		}
		buffer[0] = rand() % 100;
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
	return arr;
}
template<typename T>T** insert_col(T** arr, const int rows, int& cols, const int index)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1];
		for (int j = 0; j < index; j++)
		{
			buffer[j] = arr[i][j];
			buffer[index] = rand() % 100;
		}
		for (int j = index; j < cols; j++)
		{
			buffer[j + 1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
	return arr;
}

template<typename T>T** pop_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1];
		for (int j = 0; j < cols-1; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
	return arr;
}
template<typename T>T** pop_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T [cols - 1];
		for (int j = 0; j < cols - 1; j++)buffer[j] = arr[i][j + 1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
	return arr;
}
template<typename T>T** erase_col(T** arr, const int rows, int& cols, const int index)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1];
		for (int j = 0; j < index; j++)buffer[j] = arr[i][j];
		for (int j = index; j < cols; j++)buffer[j] = arr[i][j + 1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
	return arr;
}
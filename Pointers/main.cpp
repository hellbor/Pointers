#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

//#define POINTERS_BASICS

void main()
{
	setlocale(LC_ALL, "");

#ifdef POINTERS_BASICS
	int a = 2;
	int* pa = &a;
	cout << a << endl;
	cout << &a << endl;  //ѕолучаем адрес переменной 'a' пр€мо при выводе
	cout << pa << endl;  //¬ывод адреса, хран€щегос€ в указателе
	cout << *pa << endl; //–азыменовываем уазатель 'pa' и получаем значение хран€щеес€ по адресу

	int* pb;
	int b = 3;
	pb = &b;
#endif // POINTERS_BASICS

	const int n = 5;
	int arr[n] = { 3,5,8,13,21 };
	cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;
}
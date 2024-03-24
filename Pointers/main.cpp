//#include<iostream>
//
//using namespace std;
////#define POINTERS_BASICS
//#define DEBUG
//void main()
//{
//	setlocale(LC_ALL, "rus");
//#ifdef POINTERS_BASICS
//	int a = 2;
//	int* pa = &a;
//	int b = 0;
//	cout << a << endl;
//	cout << &a << endl;
//	cout << pa << endl;
//	cout << *pa << endl;
//#endif //POINTERS_BASICS
//
//#ifdef DEBUG
//	const int n = 5;
//	int arr[n] = { 3,5,8,13,21 };
//	//cout << *(arr + 2) << endl;
//	for (int i = 0; i < n; i++)
//	{
//		cout << *(arr + i) << "\t";
//	}
//#endif // DEBUG	
//}

//Pointers
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define POINTERS_BASICS
//#define POINTERS_AND_ARRAYS

void main()
{
	setlocale(LC_ALL, "");
#ifdef POINTERS_BASICS
	int a = 2;
	int* pa = &a;	//pa - Pointer to 'a'
	//https://ru.wikipedia.org/wiki/%D0%92%D0%B5%D0%BD%D0%B3%D0%B5%D1%80%D1%81%D0%BA%D0%B0%D1%8F_%D0%BD%D0%BE%D1%82%D0%B0%D1%86%D0%B8%D1%8F
	cout << a << endl;	//����� ��������� ���������� 'a' �� �����
	cout << &a << endl;	//������ ������ ���������� 'a' ����� ��� ������
	cout << pa << endl; //����� ������ ���������� 'a', ����������� � ��������� 'pa'
	cout << *pa << endl;//������������� ��������� 'pa' � ����� �� ����� �������� �� ������ � ���� ���������
	cout << pa[0] << endl;
	/*
	-------------------------------
	& - �������� ������ ������ (Address-of operator)
	* - �������� ������������� (Dereference operator)
	-------------------------------
	*/

	int* pb;
	int b = 3;
	pb = &b;
	cout << typeid(pb).name() << endl;
	//int - 'int'
	//int* - ��������� �� 'int'
	//double - 'double'
	//double* - ��������� �� 'double'
	//char - 'char'
	//char* - �������� �� 'char'  
#endif // POINTERS_BASICS

#ifdef POINTERS_AND_ARRAYS
	const int n = 5;
	short arr[n] = { 3, 5, 8, 13, 21 };
	cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;
	/*
	-----------------------------------
	+
	-
	++
	--
	-----------------------------------
	*/
#endif // POINTERS_AND_ARRAYS

}
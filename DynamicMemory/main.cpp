#include<iostream>
using std::cin;
using std::cout;
using std::endl;
#define tab "\t"

void FillRand(int arr[], const int n);
void Print(const int arr[], const int n);


//void 

void main() 
{
	setlocale(LC_ALL, "rus");
	int n = 5;
	cout << "enter  size ";
	cin >> n;
	//���������� ������������� �������
	int* arr = new int[n];
	cout << arr << endl;

	FillRand(arr, n);
	Print(arr, n);
	
	int Value;
	cout << "enter the value to be completed "; cin >> Value;
	//1) ������� ������ ������� �������
	int* buffer = new int[n + 1];

	//2)�������� ��� �������� �� ��������� ������� � ������
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3)������� ������ ������
	delete[]arr;
	//4)��������� ����� �������� ������� ������� ������
	arr = buffer;
	//5)��������� �������
	arr[n] = Value;
	//6)
	n++;

	delete[] arr;

	cout << endl;
	//������ ������ �������
	cout << arr << endl;
	//FillRand(arr, n);
	//Print(arr, n);
	arr = nullptr;
	cout << arr << endl;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//��������� � ��������� �������
		*(arr + i) = rand() % 100;
	}
}

void Print(const int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//��������� � ��������� �������
		cout<<*(arr + i) << "\t";
	}
}

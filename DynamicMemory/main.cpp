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
	//объ€вление динамического массива
	int* arr = new int[n];
	cout << arr << endl;

	FillRand(arr, n);
	Print(arr, n);
	
	int Value;
	cout << "enter the value to be completed "; cin >> Value;
	//1) создаем массив нужного массива
	int* buffer = new int[n + 1];

	//2)копируем все значение из исходного массива в буффер
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3)удал€ем старый массив
	delete[]arr;
	//4)подмен€ем адрес стаорого массива адресом нового
	arr = buffer;
	//5)добавл€ем элемент
	arr[n] = Value;
	//6)
	n++;

	delete[] arr;

	cout << endl;
	//отдаем пам€ть обратно
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
		//обращение к элементам массива
		*(arr + i) = rand() % 100;
	}
}

void Print(const int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//обращение к элементам массива
		cout<<*(arr + i) << "\t";
	}
}

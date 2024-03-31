#include<iostream>
using std::cin;
using std::cout;
using std::endl;
#define tab "\t"

void FillRand(int arr[], const int n);
void Print(const int arr[], const int n);
void Print( int** arr, const int rows, const int cols);

int* push_back(int arr[], int& n, int value);
int* push_front(int arr[], int& n,const int value);

int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);
int* erase(int arr[], int& n, const int index);
int* insert(int arr[], int& n, const int index, const int value);

//void 
#define DYNAMIC_MEMORY1
//#define DYNAMIC_MEMORY2
void main() 
{
	setlocale(LC_ALL, "rus");
#ifdef DYNAMIC_MEMORY1
	int n = 5;
	cout << "enter  size ";
	//cin >> n;
	//объ€вление динамического массива
	int* arr = new int[n];
	cout << arr << endl;

	FillRand(arr, n);
	cout << tab << tab; Print(arr, n);

	int Value=101;
	
	//cout << "\nenter the value to be completed \n";
	//cin >> Value;
	 arr = push_back(arr, n, Value);
	 cout << "push_back\t"; Print(arr, n);
	
	// cout << "\nenter the value to be completed \n";
	//cin >> Value;
	arr = push_front(arr, n, Value);
	cout << "push_front\t"; Print(arr, n);

	arr = pop_back(arr, n);
	cout << "pop_back\t"; Print(arr, n);
	
	arr = pop_front(arr, n);
	cout << "pop_front\t"; Print(arr, n);

	arr = erase(arr, n,0);
	cout << "erase\t\t"; Print(arr, n);

	arr = insert(arr, n, 0,34);
	cout << "insert\t\t"; Print(arr, n);

	delete[] arr;

	cout << endl;
	//отдаем пам€ть обратно
	cout << arr << endl;
	//FillRand(arr, n);
	//Print(arr, n);
	arr = nullptr;
	cout << arr << endl;

#endif // DYNAMIC_MEMORY1
#ifdef DYNAMIC_MEMORY2
	///объ€вление двумерного динамического массива///
////////////////////////////////////////////////
/////////////////////////////////////////////////
	int rows;
	int cols;
	cout << "¬ведите кол-во строк: "; cin >> rows;
	cout << "¬ведите кол-во элементов строки: "; cin >> cols;
	//1) создаем массив указателей
	int** arr = new int* [rows];
	//2) выдел€ем пам€ть под строки
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	///////////////////////////////////////////////////////////
	///////использование двухмерного динамического массива/////
	///////////////////////////////////////////////////////////

	Print(arr, rows, cols);

	///////////////////////////////////////////////////////////
	///////удаление двухмерного динамического массива//////////
	///////////////////////////////////////////////////////////

	//1)сначала удалем€ строки двухмерного массива
	for (int i = 0; i < rows; i++)
	{
		delete[]arr[i];
		arr[i] = nullptr;
	}
	//2)удал€ем массив указателей
	delete[]arr;
	arr = nullptr;
#endif // DYNAMIC_MEMORY2

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
	cout << endl;
}

void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
}

int* push_back(int arr[], int& n, int value)
{
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
	arr[n] = value;
	//6)
	n++;
	return arr;
}

int* push_front(int arr[], int& n, const int value)
{
	//1) создаем массив нужного массива
	int* buffer = new int[n + 1];
	
	//2)копируем все значение из исходного массива в буффер
	for (int i = 0; i < n; i++)
	{
		buffer[i+1] = arr[i];
	}
	//3)удал€ем старый массив
	delete[]arr;
	
	//4)добавл€ем элемент
	buffer[0] = value;
	//6)
	n++;
	return buffer;
}

int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[]arr;
	return buffer;
}

int* pop_front(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i+1];
	delete[]arr;
	return buffer;
}

int* erase(int arr[], int& n, const int index)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
	{
		//if-else
		//if (i < index)buffer[i] = arr[i];
		//else buffer[i] = arr[i+1];

		//ternary operator
		i < index ? buffer[i] = arr[i] : buffer[i] = arr[i + 1];
	}
	delete[]arr;
	return buffer;
}

int* insert(int arr[], int& n, const int index, const int value)
{
	int* buffer = new int[++n];
	for (int i = 0; i < n; i++)
	{
		//if-else
		//if (i < index)buffer[i] = arr[i];
		//else buffer[i+1] = arr[i];
		
		//ternary operator
		i < index ? buffer[i] = arr[i] : buffer[i + 1] = arr[i];
	}
	buffer[index] = value;
	delete[]arr;
	return buffer;
}

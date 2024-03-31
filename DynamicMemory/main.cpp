#include<iostream>
using std::cin;
using std::cout;
using std::endl;
#define tab "\t"

void FillRand(int arr[], const int n);
void Print(const int arr[], const int n);
void Print( int** arr, const int rows, const int cols);

int* push_back(int arr[], int& n, int value);		//добавляющий значение в конец массива в функцию
int* push_front(int arr[], int& n,const int value); //добавляет значение в начало массива

int* pop_back(int arr[], int& n);					//удаляет последний элемент массива
int* pop_front(int arr[], int& n);					//удаляет нулевой элемент массива
int* erase(int arr[], int& n, const int index);		//удаляет элемент из массива по заданному индексу
int* insert(int arr[], int& n, const int index, const int value);//вставляет значение в массив по заданному индексу

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
	//объявление динамического массива
	int* arr = new int[n];
	cout << arr << endl;

	FillRand(arr, n);
	cout << tab << tab; Print(arr, n);

	int Value=101;
	
	//cout << "enter the value to be completed \n";cin >> Value;
	 arr = push_back(arr, n, Value);//добавляющий значение в конец массива в функцию
	 cout << "push_back\t"; Print(arr, n);
	
	// cout << "enter the value to be completed \n";cin >> Value;
	arr = push_front(arr, n, Value);//добавляет значение в начало массива
	cout << "push_front\t"; Print(arr, n);

	arr = pop_back(arr, n);//удаляет последний элемент массива
	cout << "pop_back\t"; Print(arr, n);
	
	arr = pop_front(arr, n);//удаляет нулевой элемент массива
	cout << "pop_front\t"; Print(arr, n);

	//cout << "enter the index to be completed \n";cin >> index;
	arr = erase(arr, n,2);//удаляет элемент из массива по заданному индексу
	cout << "erase\t\t"; Print(arr, n);

	//cout << "enter the value to be completed \n";cin >> Value;
	//int index;
	//cout << "enter the index to be completed \n";cin >> index;
	arr = insert(arr, n, 2,34);//вставляет значение в массив по заданному индексу
	cout << "insert\t\t"; Print(arr, n);

	delete[] arr;

	cout << endl;
	//отдаем память обратно
	cout << arr << endl;
	//FillRand(arr, n);
	//Print(arr, n);
	arr = nullptr;
	cout << arr << endl;

#endif // DYNAMIC_MEMORY1
#ifdef DYNAMIC_MEMORY2
	///объявление двумерного динамического массива///
////////////////////////////////////////////////
/////////////////////////////////////////////////
	int rows;
	int cols;
	cout << "Введите кол-во строк: "; cin >> rows;
	cout << "Введите кол-во элементов строки: "; cin >> cols;
	//1) создаем массив указателей
	int** arr = new int* [rows];
	//2) выделяем память под строки
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

	//1)сначала удалемя строки двухмерного массива
	for (int i = 0; i < rows; i++)
	{
		delete[]arr[i];
		arr[i] = nullptr;
	}
	//2)удаляем массив указателей
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
	//3)удаляем старый массив
	delete[]arr;
	//4)подменяем адрес стаорого массива адресом нового
	arr = buffer;
	//5)добавляем элемент
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
	//3)удаляем старый массив
	delete[]arr;
	
	//4)добавляем элемент
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

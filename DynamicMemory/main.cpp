#include<iostream>
using std::cin;
using std::cout;
using std::endl;
#define tab "\t"

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);
void Print(const int arr[], const int n);
void Print( int** arr, const int rows, const int cols);

int* push_back(int arr[], int& n, int value);		//добавляющий значение в конец массива в функцию
int* push_front(int arr[], int& n,const int value); //добавляет значение в начало массива

int* pop_back(int arr[], int& n);					//удаляет последний элемент массива
int* pop_front(int arr[], int& n);					//удаляет нулевой элемент массива
int* erase(int arr[], int& n, const int index);		//удаляет элемент из массива по заданному индексу
int* insert(int arr[], int& n, const int index, const int value);//вставляет значение в массив по заданному индексу

int** Allocate(const int rows, const int cols);		//выделяет память под двумерный динамиеский массив
void Clear(int** arr,const int rows);				//удаляет двумерный динамиеский массив из памяти

int** push_row_back(int** arr,int&rows,const int cols, int* arr1=nullptr);					//добавляет строку в конец массива
int** push_row_front(int** arr, int& rows, const int cols, int* arr1=nullptr);				//добавляет строку в начало массива
int** insert_row(int** arr, int& rows, const int cols, const int index,int* arr1=nullptr);	//вставляет строку в массив по указанному индексу

int** pop_row_back(int** arr,int&rows);						//удаляет последнюю строку из массива
int** pop_row_front(int** arr, int& rows);					//удаляет нулевую строку из массива
int** erase_row(int** arr, int& rows, const int rowIndex);	//удаляет строку из массива по заданному индексу

void push_col_back(int** arr, const int rows, int& cols, int* arr1=nullptr);	//добавляет столбец в конец массива
void push_col_front(int** arr, const int rows, int& cols, int* arr1=nullptr);	//добавляет столбец в начало массива
void insert_col(int** arr, const int rows,  int& cols, const int index,int* arr1=nullptr); //вставляет столбец в массив по указанному индексу

int** pop_col_back(int** arr,const int rows,int&cols);						//удаляет последний столбец из массива
int** pop_col_front(int** arr, const int rows, int& cols);					//удаляет нулевой столбец из массива
int** erase_col(int** arr, const int rows, int& cols,const int index);		//удаляет столбец из массива по указанному индексу



//#define DYNAMIC_MEMORY1
#define DYNAMIC_MEMORY2
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
	
	int rows=3;
	int cols=3;
	//cout << "Введите кол-во строк: "; cin >> rows;
	//cout << "Введите кол-во элементов строки: "; cin >> cols;
	int** TwoArray = Allocate(rows, cols);//creation
	cout << endl << "dd" << endl;
	Print(TwoArray, rows, cols);//show
	int* arr1x = new int[cols];//creat arr1x
	FillRand(arr1x,cols);//filling
	FillRand(TwoArray,rows,cols);
	//Print(arr1x, cols);
	//TwoArray = 
	cout << endl <<"push_row_back" << endl;
	TwoArray=push_row_back(TwoArray,rows,cols, arr1x);
	Print(TwoArray, rows, cols);//show
	
	cout << endl << "push_row_front" << endl;
	TwoArray = push_row_front(TwoArray, rows, cols, arr1x);
	Print(TwoArray, rows, cols);//show
	
	cout << endl << "insert_row" << endl;
	TwoArray = insert_row(TwoArray, rows, cols,2,arr1x);
	Print(TwoArray, rows, cols);//show

	cout << endl << "pop_row_back" << endl;
	TwoArray = pop_row_back(TwoArray, rows);
	Print(TwoArray, rows, cols);//show

	cout << endl << "pop_row_front" << endl;
	TwoArray = pop_row_front(TwoArray, rows);
	Print(TwoArray, rows, cols);//show

	cout << endl << "erase_row" << endl;
	TwoArray = erase_row(TwoArray, rows,1);
	Print(TwoArray, rows, cols);//show

	cout << endl << "push_col_back" << endl;
	push_col_back(TwoArray, rows, cols,arr1x);
	Print(TwoArray, rows, cols);//show

	cout << endl << "push_col_front" << endl;
	push_col_front(TwoArray, rows, cols, arr1x);
	Print(TwoArray, rows, cols);//show

	cout << endl << "insert_col" << endl;
	insert_col(TwoArray, rows, cols,2, arr1x);
	Print(TwoArray, rows, cols);//show

	cout << endl << "pop_col_back" << endl;
	TwoArray = pop_col_back(TwoArray, rows, cols);
	Print(TwoArray, rows, cols);//show

	cout << endl << "pop_col_front" << endl;
	TwoArray = pop_col_front(TwoArray, rows, cols);
	Print(TwoArray, rows, cols);//show

	cout << endl << "erase_col" << endl;
	TwoArray = erase_col(TwoArray, rows, cols,1);
	Print(TwoArray, rows, cols);//show

	Clear(TwoArray,rows);//delete
	if (arr1x)
	{
		delete[]arr1x;
		arr1x = nullptr;
	}

	

	
#endif // DYNAMIC_MEMORY2

}

void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		//обращение к элементам массива
		*(arr + i) = rand() % ((maxRand + 1) - (-minRand) + minRand);
	}
}

void FillRand(int** arr, const int rows, const int cols, int minRand, int maxRand)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % ((maxRand + 1) - (-minRand) + minRand);
		}
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

int** Allocate(const int rows,const int cols)
{
	///////////////////////////////////////////////////////////
	///////использование двухмерного динамического массива/////
	///////////////////////////////////////////////////////////
	// 
	//1) создаем массив указателей
	int ** array = new int* [rows];
	//2) выделяем память под строки
	for (int i = 0; i < rows; i++)
	{
		array[i] = new int[cols] {};
	}
	return array;
}

void Clear(int** arr, const int rows)
{
	///////////////////////////////////////////////////////////
	///////удаление двухмерного динамического массива//////////
	///////////////////////////////////////////////////////////
	// 
	//1)сначала удалемя строки двухмерного массива
	for (int i = 0; i < rows; i++)
	{
		delete[]arr[i];
		arr[i] = nullptr;
	}
	//2)удаляем массив указателей
	delete[]arr;
	arr = nullptr;
}

int ** push_row_back(int** arr, int& rows, const int cols, int* arr1)
{
	
	
	int** buffer=new int*[rows+1]; //creat 2Darr address
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];        //copy address
	}
	delete[]arr;
	buffer[rows] = new int [cols] {}; //creat last row
	if (arr1)
	{
		for (int i = 0; i < cols; i++)
		{
			buffer[rows][i] = arr1[i]; //copy address new row
		}
	}
	arr = buffer;
	rows++;
	return buffer;
}

int** push_row_front(int** arr, int& rows, const int cols, int* arr1)
{
	int** buffer = new int* [rows + 1]; //creat 2Darr address
	for (int i = 0; i < rows; i++)
	{
		buffer[i+1] = arr[i];        //copy address
	}
	delete[]arr;
	buffer[0] = new int[cols] {}; //creat last row
	if (arr1)
	{
		for (int i = 0; i < cols; i++)
		{
			buffer[0][i] = arr1[i]; //copy address new row
		}
	}
	arr = buffer;
	rows++;
	return buffer;
}

int** insert_row(int** arr, int& rows, const int cols,  const int index,int* arr1)
{
	int** buffer = new int* [rows + 1]; //creat 2Darr address
	for (int i = 0; i < rows; i++)
	{
		i < index ? buffer[i] = arr[i] : buffer[i + 1] = arr[i];//copy address
	}
	delete[]arr;
	buffer[index] = new int[cols] {}; //creat last row
	if (arr1)
	{
		for (int i = 0; i < cols; i++)
		{
			buffer[index][i] = arr1[i]; //copy address new row
		}
	}
	arr = buffer;
	rows++;
	return buffer;
}

int** pop_row_back(int** arr, int& rows)
{
	int** buffer = new int* [--rows]; //creat 2Darr address
	delete[]arr[rows];
	arr[rows] = nullptr;
	for (int i = 0; i < rows; i++) buffer[i] = arr[i];        //copy address
	delete[]arr;
	arr = buffer;
	return buffer;
}

int** pop_row_front(int** arr, int& rows)
{
	int** buffer = new int* [--rows]; //creat 2Darr address
	delete[]arr[0];
	arr[0] = nullptr;
	for (int i = 0; i < rows; i++) buffer[i] = arr[i+1];        //copy address
	delete[]arr;
	arr = buffer;
	return buffer;
}

int** erase_row(int** arr, int& rows, const int rowIndex)
{
	int** buffer = new int* [--rows]; //creat 2Darr address
	
	for (int i = 0; i < rows; i++) 
	{
		i < rowIndex ? buffer[i] = arr[i] : buffer[i] = arr[i + 1];
	}
	delete[]arr[rowIndex];
	arr[rowIndex] = nullptr;
	delete[]arr;
	arr = buffer;
	return buffer;
}

void push_col_back(int** arr, const int rows, int& cols, int* arr1)
{
	for (int i = 0; i < rows; i++)
	{
		int* bufferRows = new int[cols + 1] {};
		for (int j = 0; j < cols; j++)
		{
			bufferRows[j] = arr[i][j];
		}
		delete[]arr[i];
		arr[i] = bufferRows;
		
	}
	if (arr1)
	{
		for (int i = 0; i < cols; i++) arr[i][cols] = arr1[i];
	}
	cols++;
	
	
	/*int** buffer = Allocate(rows, cols + 1); //creat 2Darr address
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols ; j++)
		{
			buffer[i][j] = arr[i][j];
		}
	}
	if (arr1)
	{
		for (int i = 0; i < rows; i++)
		{
			buffer[i][cols] = arr1[i];
		}
	}
	Clear(arr, rows);
	arr = buffer;
	cols++;
	return buffer;
	*/
}

void push_col_front(int** arr, const int rows, int& cols, int* arr1)
{
	
	for (int i = 0; i < rows; i++)
	{
		int* bufferRows = new int[cols + 1] {};
		for (int j = 0; j < cols; j++)
		{
			bufferRows[j+1] = arr[i][j];
		}
		delete[]arr[i];
		arr[i] = bufferRows;

	}

	if (arr1)
	{
		for (int i = 0; i < rows; i++) arr[i][0] = arr1[i];
	}
	cols++;
	
	
	
	
	/*int** buffer = Allocate(rows, cols + 1); //creat 2Darr address

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j+1] = arr[i][j];
		}
	}
	if (arr1)
	{
		for (int i = 0; i < rows; i++)
		{
			buffer[i][0] = arr1[i];
		}
	}
	Clear(arr, rows);
	arr = buffer;
	cols++;
	return buffer;
	*/
}

void insert_col(int** arr, const int rows, int& cols,  const int index,int* arr1)
{
	
	for (int i = 0; i < rows; i++)
	{
		int* bufferRows = new int[cols + 1] {};
		for (int j = 0; j < cols; j++)
		{
			j < index ? bufferRows[j] = arr[i][j] : bufferRows[j + 1] = arr[i][j];
		}
		delete[]arr[i];
		arr[i] = bufferRows;

	}
	if (arr1)
	{
		for (int i = 0; i < rows; i++) arr[i][index] = arr1[i];
	}
	cols++;
	
	
	
	
	/*int** buffer = Allocate(rows, cols + 1); //creat 2Darr address

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			j < index ? buffer[i][j] = arr[i][j] : buffer[i ][j+1] = arr[i][j];
		}
	}
	if (arr1)
	{
		for (int i = 0; i < rows; i++)
		{
			buffer[i][index] = arr1[i];
		}
	}
	Clear(arr, rows);
	arr = buffer;
	cols++;
	return buffer;
	*/
}

int** pop_col_back(int** arr, const int rows, int& cols)
{
	int** buffer = Allocate(rows, --cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j] = arr[i][j];
		}
	}
	Clear(arr, rows);
	arr = buffer;
	return buffer;
}

int** pop_col_front(int** arr, const int rows, int& cols)
{
	int** buffer = Allocate(rows, --cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j] = arr[i][j+1];
		}
	}
	Clear(arr, rows);
	arr = buffer;
	return buffer;
}

int** erase_col(int** arr, const int rows, int& cols, const int index)
{
	int** buffer = Allocate(rows, --cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			j < index ? buffer[i][j] = arr[i][j] : buffer[i][j] = arr[i][j+1];
		}
	}
	Clear(arr, rows);
	arr = buffer;
	return buffer;
}

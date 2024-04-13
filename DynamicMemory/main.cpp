#include<iostream>
using std::cin;
using std::cout;
using std::endl;
#define tab "\t"

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(double arr[], const int n, int minRand = 0, int maxRand = 100);

void FillRand(int** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);
void FillRand(double** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);

template<typename T>void Print(const T arr[], const int n);
template<typename T>void Print( T** arr, const int rows, const int cols);

template<typename T>T* push_back(T arr[], int& n, T value=NULL);		//добавляющий значение в конец массива в функцию
template<typename T>T* push_front(T arr[], int& n,const T value = NULL);		//добавляет значение в начало массива

template<typename T>T* pop_back(T arr[], int& n);					//удаляет последний элемент массива
template<typename T>T* pop_front(T arr[], int& n);					//удаляет нулевой элемент массива
template<typename T>T* erase(T arr[], int& n, const int index);		//удаляет элемент из массива по заданному индексу
template<typename T>T* insert(T arr[], int& n, const int index, const T value=NULL);//вставляет значение в массив по заданному индексу

template<typename T>T** Allocate(const int rows, const int cols);		//выделяет память под двумерный динамиеский массив
template<typename T>void Clear(T** arr,const int rows);				//удаляет двумерный динамиеский массив из памяти

template<typename T>T** push_row_back(T** arr,int&rows,const int cols);					//добавляет строку в конец массива
template<typename T>T** push_row_front(T** arr, int& rows, const int cols);				//добавляет строку в начало массива
template<typename T>T** insert_row(T** arr, int& rows, const int cols, const int index);	//вставляет строку в массив по указанному индексу

template<typename T>T** pop_row_back(T** arr,int&rows);						//удаляет последнюю строку из массива
template<typename T>T** pop_row_front(T** arr, int& rows);					//удаляет нулевую строку из массива
template<typename T>T** erase_row(T** arr, int& rows, const int rowIndex);	//удаляет строку из массива по заданному индексу

template<typename T>void push_col_back(T** arr, const int rows, int& cols);	//добавляет столбец в конец массива
template<typename T>void push_col_front(T** arr, const int rows, int& cols);	//добавляет столбец в начало массива
template<typename T>void insert_col(T** arr, const int rows,  int& cols, const int index); //вставляет столбец в массив по указанному индексу

template<typename T>void pop_col_back(T** arr,const int rows,int&cols);						//удаляет последний столбец из массива
template<typename T>void pop_col_front(T** arr, const int rows, int& cols);					//удаляет нулевой столбец из массива
template<typename T>void erase_col(T** arr, const int rows, int& cols,const int index);		//удаляет столбец из массива по указанному индексу



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
	//double* arr = new double[n];
	cout << arr << endl;

	FillRand(arr, n);
	cout << tab << tab; Print(arr, n);

	int Value=101;
	
	//cout << "enter the value to be completed \n";cin >> Value;
	 arr = push_back(arr, n,Value);//добавляющий значение в конец массива в функцию
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
	//int** TwoArray = Allocate<int>(rows, cols);//creation
	double** TwoArray = Allocate<double>(rows, cols);
	Print(TwoArray, rows, cols);//show
	//int* arr1x = new int[cols];//creat arr1x
	FillRand(TwoArray,rows,cols);

	cout << endl <<"push_row_back" << endl;
	TwoArray=push_row_back(TwoArray,rows,cols);
	Print(TwoArray, rows, cols);//show
	
	cout << endl << "push_row_front" << endl;
	TwoArray = push_row_front(TwoArray, rows, cols);
	Print(TwoArray, rows, cols);//show
	
	cout << endl << "insert_row" << endl;
	TwoArray = insert_row(TwoArray, rows, cols,2);
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
	push_col_back(TwoArray, rows, cols);
	Print(TwoArray, rows, cols);//show

	cout << endl << "push_col_front" << endl;
	push_col_front(TwoArray, rows, cols);
	Print(TwoArray, rows, cols);//show

	cout << endl << "insert_col" << endl;
	insert_col(TwoArray, rows, cols,2);
	Print(TwoArray, rows, cols);//show

	cout << endl << "pop_col_back" << endl;
	 pop_col_back(TwoArray, rows, cols);
	Print(TwoArray, rows, cols);//show

	cout << endl << "pop_col_front" << endl;
	 pop_col_front(TwoArray, rows, cols);
	Print(TwoArray, rows, cols);//show

	cout << endl << "erase_col" << endl;
	 erase_col(TwoArray, rows, cols,1);
	Print(TwoArray, rows, cols);//show

	Clear(TwoArray,rows);//delete
#endif // DYNAMIC_MEMORY2

}

void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		//обращение к элементам массива
		*(arr + i) = rand() % (maxRand  - minRand) + minRand;
		//*(arr + i) = rand() % (maxRand  - minRand) + minRand;

	}
}

void FillRand(double arr[], const int n, int minRand, int maxRand)
{
	if (minRand > maxRand)
	{
		int buffer = minRand;
		minRand = maxRand;
		maxRand = minRand;
	}
	minRand *= 100;
	maxRand *= 100;

	for (int i = 0; i < n; i++)
	{
		//обращение к элементам массива
		*(arr + i) = rand() % (maxRand - minRand) + minRand;
		arr[i] /= 100;
		//*(arr + i) = rand() % (maxRand  - minRand) + minRand;

	}
}

void FillRand(int** arr, const int rows, const int cols, int minRand, int maxRand)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % (maxRand  - minRand) + minRand;
		}
	}
}

void FillRand(double** arr, const int rows, const int cols, int minRand, int maxRand)
{
	if (minRand > maxRand)
	{
		int buffer = minRand;
		minRand = maxRand;
		maxRand = minRand;
	}
	minRand *= 100;
	maxRand *= 100;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % (maxRand - minRand) + minRand;
			arr[i][j] /= 100;
		}
	}
}

template<typename T>void Print(const T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//обращение к элементам массива
		cout<<*(arr + i) << "\t";
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
}

template<typename T>T* push_back(T arr[], int& n,  T value)
{
	//1) создаем массив нужного массива
	T* buffer = new T[n + 1];
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
	if(!NULL)arr[n] = value;
	//6)
	n++;
	return arr;
}

template<typename T>T* push_front(T arr[], int& n, const T value)
{
	//1) создаем массив нужного массива
	T* buffer = new T[n + 1];
	//2)копируем все значение из исходного массива в буффер
	for (int i = 0; i < n; i++)
	{
		buffer[i+1] = arr[i];
	}
	//3)удаляем старый массив
	delete[]arr;
	//4)добавляем элемент
	if(!NULL)buffer[0] = value;
	//6)
	n++;
	return buffer;
}

template<typename T>T*  pop_back(T arr[], int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[]arr;
	return buffer;
}

template<typename T>T* pop_front(T arr[], int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i+1];
	delete[]arr;
	return buffer;
}

template<typename T>T* erase(T arr[], int& n, const int index)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)
	{
		i < index ? buffer[i] = arr[i] : buffer[i] = arr[i + 1];
	}
	delete[]arr;
	arr = nullptr;
	return buffer;
}

template<typename T>T* insert(T arr[], int& n, const int index, const T value)
{
	T* buffer = new T[++n];
	for (int i = 0; i < n; i++)
	{
		i < index ? buffer[i] = arr[i] : buffer[i + 1] = arr[i];
	}
	if(!NULL)buffer[index] = value;
	delete[]arr;
	return buffer;
}

template<typename T>T** Allocate(const int rows,const int cols)
{
	///////////////////////////////////////////////////////////
	///////использование двухмерного динамического массива/////
	///////////////////////////////////////////////////////////
	// 
	//1) создаем массив указателей
	T ** array = new T* [rows];
	//2) выделяем память под строки
	for (int i = 0; i < rows; i++)
	{
		array[i] = new T[cols] {};
	}
	return array;
}

template<typename T>void Clear(T** arr, const int rows)
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

template<typename T>T** push_row_back(T** arr, int& rows, const int cols)
{
	T** buffer = push_back(arr, rows);
	buffer[rows-1] = new T [cols] {}; //creat last row
	return buffer;
}

template<typename T>T** push_row_front(T** arr, int& rows, const int cols)
{
	T** buffer = push_front(arr, rows);
	buffer[0] = new T[cols] {}; //creat last row
	//arr = buffer;
	return buffer;
}

template<typename T>T** insert_row(T** arr, int& rows, const int cols,  const int index)
{
	T** buffer = insert(arr, rows, index);
	buffer[index] = new T[cols] {}; //creat last ro
	//arr = buffer;
	return buffer;
}

template<typename T>T** pop_row_back(T** arr, int& rows)
{
	delete[]arr[rows-1];
	T** Buffer = pop_back(arr, rows);
	return Buffer;
}

template<typename T>T** pop_row_front(T** arr, int& rows)
{
	delete[]arr[0];
	T** buffer = pop_front(arr, rows);
	return buffer;
}

template<typename T>T** erase_row(T** arr, int& rows, const int rowIndex)
{
	delete[]arr[rowIndex];
	T** buffer = erase(arr, rows, rowIndex);
	arr = buffer;
	return buffer;
}

template<typename T>void push_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int colsBuffer = cols;
		arr[i] = push_back(arr[i], colsBuffer);
	}
}

template<typename T>void push_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int colsBuffer = cols;
		arr[i] = push_front(arr[i], colsBuffer);
	}
	cols++;
}

template<typename T>void insert_col(T** arr, const int rows, int& cols,  const int index)
{
	for (int i = 0; i < rows; i++)
	{
		int colsBuffer = cols;
		arr[i] = insert(arr[i], colsBuffer, index);
	}
	cols++;
}

template<typename T>void pop_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int colsBuffer = cols;
		arr[i] = pop_back(arr[i], colsBuffer);
	}
	cols--;
}

template<typename T>void pop_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int colsBuffer = cols;
		arr[i] = pop_front(arr[i], colsBuffer);
	}
	cols--;
}

template<typename T>void erase_col(T** arr, const int rows, int& cols, const int index)
{
	for (int i = 0; i < rows; i++)
	{
		int colsBuffer = cols;
		arr[i] = erase(arr[i], colsBuffer, index);
	}
	cols--;
}

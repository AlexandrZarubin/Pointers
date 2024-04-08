#include<iostream>
using std::cin;
using std::cout;
using std::endl;
#define tab "\t"

template<typename T>void FillRand(T arr[], const int n, int minRand = 0, int maxRand = 100);
template<typename T>void FillRand(T** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);


template<typename T>void Print(const T arr[], const int n);
template<typename T>void Print( T** arr, const int rows, const int cols);

template<typename T>T* push_back(T arr[], int& n,const T value);		//добавляющий значение в конец массива в функцию
template<typename T>T* push_front(T arr[], int& n,const T value); //добавляет значение в начало массива

template<typename T>T* pop_back(T arr[], int& n);					//удаляет последний элемент массива
template<typename T>T* pop_front(T arr[], int& n);					//удаляет нулевой элемент массива
template<typename T>T* erase(T arr[], int& n, const int index);		//удаляет элемент из массива по заданному индексу
template<typename T>T* insert(T arr[], int& n, const int index, const T value);//вставляет значение в массив по заданному индексу

template<typename T>T** Allocate(const int rows, const int cols);		//выделяет память под двумерный динамиеский массив
template<typename T>void Clear(T** arr,const int rows);				//удаляет двумерный динамиеский массив из памяти

template<typename T>T** push_row_back(T** arr,int&rows,const int cols, T* arr1=nullptr);					//добавляет строку в конец массива
template<typename T>T** push_row_front(T** arr, int& rows, const int cols, T* arr1=nullptr);				//добавляет строку в начало массива
template<typename T>T** insert_row(T** arr, int& rows, const int cols, const int index,T* arr1=nullptr);	//вставляет строку в массив по указанному индексу

template<typename T>T** pop_row_back(T** arr,int&rows);						//удаляет последнюю строку из массива
template<typename T>T** pop_row_front(T** arr, int& rows);					//удаляет нулевую строку из массива
template<typename T>T** erase_row(T** arr, int& rows, const int rowIndex);	//удаляет строку из массива по заданному индексу

template<typename T>void push_col_back(T** arr, const int rows, int& cols, T* arr1=nullptr);	//добавляет столбец в конец массива
template<typename T>void push_col_front(T** arr, const int rows, int& cols, T* arr1=nullptr);	//добавляет столбец в начало массива
template<typename T>void insert_col(T** arr, const int rows,  int& cols, const int index,T* arr1=nullptr); //вставляет столбец в массив по указанному индексу

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
	//int** TwoArray = Allocate<int>(rows, cols);//creation
	double** TwoArray = Allocate<double>(rows, cols);
	cout << endl << "dd" << endl;
	Print(TwoArray, rows, cols);//show
	//int* arr1x = new int[cols];//creat arr1x
	double* arr1x = new double[cols];
	FillRand(arr1x,cols,-100,-20);//filling
	FillRand(TwoArray,rows,cols);
	cout << endl<<"dddd\n";
	Print(arr1x, cols);
	cout << endl<<"ddddd";
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
	 pop_col_back(TwoArray, rows, cols);
	Print(TwoArray, rows, cols);//show

	cout << endl << "pop_col_front" << endl;
	 pop_col_front(TwoArray, rows, cols);
	Print(TwoArray, rows, cols);//show

	cout << endl << "erase_col" << endl;
	 erase_col(TwoArray, rows, cols,1);
	Print(TwoArray, rows, cols);//show

	Clear(TwoArray,rows);//delete
	if (arr1x)
	{
		delete[]arr1x;
		arr1x = nullptr;
	}

	

	
#endif // DYNAMIC_MEMORY2

}

template<typename T>void FillRand(T arr[], const int n, int minRand, int maxRand)
{
	if (minRand > maxRand)
	{
		int buffer = minRand;
		minRand = maxRand;
		maxRand = minRand;
	}
	if (typeid(arr) == typeid(double*)|| typeid(arr) == typeid(float*))
	{
		minRand *= 100;
		maxRand *= 100;
	}
	for (int i = 0; i < n; i++)
	{
		//обращение к элементам массива
		*(arr + i) = rand() % (maxRand  - minRand) + minRand;
		if (typeid(arr) == typeid(double*) || typeid(arr) == typeid(float*))arr[i] /= 100;
		

	}
}
template<typename T>void FillRand(T** arr, const int rows, const int cols, int minRand, int maxRand)
{
	if (minRand > maxRand)
	{
		int buffer = minRand;
		minRand = maxRand;
		maxRand = minRand;
	}
	if (typeid(arr) == typeid(double**) || typeid(arr) == typeid(float**))
	{
		minRand *= 100;
		maxRand *= 100;
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % (maxRand  - minRand) + minRand;
			if (typeid(arr) == typeid(double**) || typeid(arr) == typeid(float**))arr[i][j] /= 100;
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

template<typename T>T* push_back(T arr[], int& n, const T value)
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
	arr[n] = value;
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
	buffer[0] = value;
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
		//if-else
		//if (i < index)buffer[i] = arr[i];
		//else buffer[i] = arr[i+1];

		//ternary operator
		i < index ? buffer[i] = arr[i] : buffer[i] = arr[i + 1];
	}
	delete[]arr;
	return buffer;
}

template<typename T>T* insert(T arr[], int& n, const int index, const T value)
{
	T* buffer = new T[++n];
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

template<typename T>T** push_row_back(T** arr, int& rows, const int cols, T* arr1)
{
	
	
	T** buffer=new T*[rows+1]; //creat 2Darr address
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];        //copy address
	}
	delete[]arr;
	buffer[rows] = new T [cols] {}; //creat last row
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

template<typename T>T** push_row_front(T** arr, int& rows, const int cols, T* arr1)
{
	T** buffer = new T* [rows + 1]; //creat 2Darr address
	for (int i = 0; i < rows; i++)
	{
		buffer[i+1] = arr[i];        //copy address
	}
	delete[]arr;
	buffer[0] = new T[cols] {}; //creat last row
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

template<typename T>T** insert_row(T** arr, int& rows, const int cols,  const int index,T* arr1)
{
	T** buffer = new T* [rows + 1]; //creat 2Darr address
	for (int i = 0; i < rows; i++)
	{
		i < index ? buffer[i] = arr[i] : buffer[i + 1] = arr[i];//copy address
	}
	delete[]arr;
	buffer[index] = new T[cols] {}; //creat last row
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

template<typename T>T** pop_row_back(T** arr, int& rows)
{
	T** buffer = new T* [--rows]; //creat 2Darr address
	delete[]arr[rows];
	arr[rows] = nullptr;
	for (int i = 0; i < rows; i++) buffer[i] = arr[i];        //copy address
	delete[]arr;
	arr = buffer;
	return buffer;
}

template<typename T>T** pop_row_front(T** arr, int& rows)
{
	T** buffer = new T* [--rows]; //creat 2Darr address
	delete[]arr[0];
	arr[0] = nullptr;
	for (int i = 0; i < rows; i++) buffer[i] = arr[i+1];        //copy address
	delete[]arr;
	arr = buffer;
	return buffer;
}

template<typename T>T** erase_row(T** arr, int& rows, const int rowIndex)
{
	T** buffer = new T* [--rows]; //creat 2Darr address
	
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

template<typename T>void push_col_back(T** arr, const int rows, int& cols, T* arr1)
{
	for (int i = 0; i < rows; i++)
	{
		T* bufferRows = new T[cols + 1] {};
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

template<typename T>void push_col_front(T** arr, const int rows, int& cols, T* arr1)
{
	
	for (int i = 0; i < rows; i++)
	{
		T* bufferRows = new T[cols + 1] {};
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

template<typename T>void insert_col(T** arr, const int rows, int& cols,  const int index,T* arr1)
{
	
	for (int i = 0; i < rows; i++)
	{
		T* bufferRows = new T[cols + 1] {};
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

template<typename T>void pop_col_back(T** arr, const int rows, int& cols)
{
	
	cols--;
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols] {};
		for (int j = 0; j < cols; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[]arr[i];
		arr[i] = buffer;
	}
	
	
	/*int** buffer = Allocate(rows, --cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j] = arr[i][j];
		}
	}
	Clear(arr, rows);
	arr = buffer;
	return buffer;*/
}

template<typename T>void pop_col_front(T** arr, const int rows, int& cols)
{
	cols--;
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols] {};
		for (int j = 0; j < cols; j++)
		{
			buffer[j] = arr[i][j + 1];
		}
		delete[]arr[i];
		arr[i] = buffer;
	}


	/*
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
	*/
}

template<typename T>void erase_col(T** arr, const int rows, int& cols, const int index)
{
	
	cols--;
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols] {};
		for (int j = 0; j < cols; j++)
		{
			j < index ? buffer[j] = arr[i][j] : buffer[j] = arr[i][j + 1];
			
		}
		delete[]arr[i];
		arr[i] = buffer;
	}
	
	
	
	
	/*int** buffer = Allocate(rows, --cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			j < index ? buffer[i][j] = arr[i][j] : buffer[i][j] = arr[i][j+1];
		}
	}
	Clear(arr, rows);
	arr = buffer;
	return buffer;*/
}

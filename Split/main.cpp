#include<iostream>
#include<time.h>
using namespace std;


void FilldRand(int arr[],const int Size, int minRand=0, int maxRand=100); //заполнение массива
void Print(const int arr[], const int Size);							  //вывод
int NumberOfEvenElements(const int arr[], const int Size);                //поиск четных не четных
int* NumberEven(const int arr[], const int Size, int& ReSize, bool Even = true);//раскол массива
int* push_back(int* arr[], const int Number);

void main()
{
	srand(time(NULL));
	const int SIZE = 10;    //Размер Массива
	int Split[SIZE]{};		//Массив
	FilldRand(Split,SIZE);	//Заполение массива
	Print(Split,SIZE);		//Вывод массива
	int* Even = nullptr;	//указатель на динамический массив
	int EvenSize = 0;		//размер динамического массива
	int* Odd = nullptr;		//указатель на динамический массив
	int OddSize = 0;		// размер динамического массива
	Even = NumberEven(Split, SIZE,EvenSize, 1); //заполнение массива четные
	Odd = NumberEven(Split, SIZE,OddSize, 0);	//заполнение массива не четные
	cout << endl;
	cout  << "Even\t";
	Print(Even, EvenSize);
	cout  << "Odd\t";
	Print(Odd, OddSize);
	if (Even){delete[]Even;Even = nullptr;}   //отчистка памяти
	if (Odd){delete[]Odd;Odd = nullptr;}	  //отчистка памяти

}

void FilldRand(int arr[], const int Size, int minRand, int maxRand)
{
	for (int i = 0; i < Size; i++)
	{
		//обращение к элементам массива
		*(arr + i) = rand() % ((maxRand+1)-(-minRand)+minRand);
	}
	
}

void Print(const int arr[], const int Size)
{
	for (int i = 0; i < Size; i++)
	{
		//обращение к элементам массива
		cout << *(arr + i) << "\t";
	}
	cout << endl;
}

int NumberOfEvenElements(const int arr[], const int Size)
{
	int Max=0;
	for (int i = 0; i < Size; i++)
	{
		if (!(arr[i] % 2)) Max++;
	}
	return Max;
}

int* NumberEven(const int arr[], const int Size, int&ReSize, bool Even)
{
	int SizeEven= NumberOfEvenElements(arr, Size);
	int* arrDynamic = nullptr;
	if (Even)
	{
		ReSize = SizeEven;
		arrDynamic = new int[ReSize];
		if (!arrDynamic) 
		{
			exit(1);
			cout << "Не удалось выделить память, массив не будет изменен!" << endl;
		}
		for (int i = 0,j=0; i < Size; i++)
		{
			if (!(arr[i] % 2))
			{
				arrDynamic[j] = arr[i];
				j++;
			}
		}
	}
	else
	{
		ReSize = Size - SizeEven;
		arrDynamic = new int[ReSize];
		if (!arrDynamic)
		{
			exit(1);
			cout << "Не удалось выделить память, массив не будет изменен!" << endl;
		}
		for (int i = 0, j = 0; i < Size; i++)
		{
			if (arr[i] % 2)
			{
				arrDynamic[j] = arr[i];
				j++;
			}
		}

	}

	return arrDynamic;
}

int* push_back(int* arr[], const int Number)
{
	return nullptr;
}

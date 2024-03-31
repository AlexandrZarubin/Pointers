#include<iostream>
#include<time.h>
using namespace std;


void FilldRand(int arr[],const int Size, int minRand=0, int maxRand=100);
void Print(const int arr[], const int Size);
int NumberOfEvenElements(const int arr[], const int Size);
int* NumberEven(const int arr[], const int Size,const int SizeEven,int&ReSize,bool Even=true);

void main()
{
	srand(time(NULL));
	const int SIZE = 10;
	int Split[SIZE]{};
	FilldRand(Split,SIZE);
	Print(Split,SIZE);
	NumberOfEvenElements(Split, SIZE);
	int* Even = nullptr;
	int EvenSize = 0;
	int* Odd = nullptr;
	int OddSize = 0;

	Even = NumberEven(Split, SIZE, NumberOfEvenElements(Split, SIZE),EvenSize, 1);
	Odd = NumberEven(Split, SIZE, NumberOfEvenElements(Split, SIZE),OddSize, 0);
	cout << endl;
	cout  << "Even\t"<<EvenSize<<"\t";
	Print(Even, EvenSize);
	cout  << "Odd\t"<<OddSize<<"\t";
	Print(Odd, OddSize);

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

int* NumberEven(const int arr[], const int Size, const int SizeEven, int&ReSize, bool Even)
{
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

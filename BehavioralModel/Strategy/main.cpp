#include<iostream>
#include<stdio.h>
using namespace std;
#define total_num 10


class SortStrategy
{
public:
	virtual void sort(int arr[], int N) = 0;
};


//冒泡排序的实现
class bubbleSort :public SortStrategy
{
public:
	void sort(int arr[], int N)
	{
        for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N - i - 1; j++)
			{
				if (arr[j] > arr[j + 1]){
					int tmp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = tmp;
				}
			}
		}
	}
};


//希尔排序
class shellSort :public SortStrategy
{
public:
	void sort(int arr[], int N)
	{

	}
};


//插入排序
class insertSort :public SortStrategy
{
public:
	void sort(int arr[], int N)
	{

	}
};




class Context
{
public:
	Context()
	{
		this->arr = NULL;
		this->N = 0;
		this->strategy = NULL;
	}
	Context(int* array, int Num)
	{
		this->arr = array;
		this->N = Num;
		this->strategy = NULL;
	}
	void setSortStrategy(SortStrategy* istrategy)
	{
		this->strategy = istrategy;
	}
	void setInput(int iarr[], int iN)
	{
		this->arr = iarr;
		this->N = iN;
	}
	void print()
	{
		for (int i = 0; i < N; i++)
		{
			printf("%d  ", arr[i]);
		}
		printf("\n");
	}
	void sort()
	{
		if (this->strategy == NULL)
		{
			printf("请设置排序算法\n");
		}
		else
		{
			this->strategy->sort(arr, N);
			printf("输出的结果为：\n");
			this->print();
		}
	}
private:
	int* arr;
	int N;
	SortStrategy* strategy;
};


int main()
{
	int arr[total_num] = { -1, 3, 7, 9, 2, 0, 4, 56, -100, 23 };
	Context* con = new Context(arr, total_num);
	con->setSortStrategy((SortStrategy*)(new bubbleSort()));
	con->sort();
	return 0;
}
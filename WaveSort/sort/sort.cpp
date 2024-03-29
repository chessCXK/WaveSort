// sort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include<iostream>
#include <fstream>
#include<time.h>
#include <algorithm>
#include "FaserSort.h"
#include "WaveSort.h"
#include "BucketSort.h"

using namespace std;
#define size 100000
#define RandomCount 100000
#define isShow 0


void SortCompare()
{
	srand((int)time(0));
	int val = 0;int index = 0;
	int a[size];
	int b[size];
	int c[size];
	int d[size];
	
	for (int i = 0; i < size; i++)
	{
		a[i] = i;
		b[i] = i;
		c[i] = i;
		d[i] = i;
	}
	for (int i = 0; i < RandomCount; i++)
	{
		val = rand() % size;
		index = rand() % size;
		a[index] = val;
		b[index] = val;c[index] = val;
		d[index] = val;
	}
	cout << endl;
	sort(d, d + size);
	cout << endl;
	FaerSort::Sort(a,size);
	cout << endl;
	WaveSort::Sort(b, size,0);
	cout << endl;
	BucketSort::Sort(c, size);
	cout << endl;
	cout << "FaerSort\n比较次数：" << FaerSort::F_compareCount << " 赋值次数：" << FaerSort::F_setCount << " 变量使用计数：" << FaerSort::F_memoryCount << " 递归次数：" << FaerSort::F_recursionCount << endl;
	if (isShow)
		for (int i = 0; i < size; i++)
		{
			//cout << a[i] << " ";
		}
	cout << endl << endl;
	cout << "WaveSort\n比较次数：" << WaveSort::W_compareCount << " 赋值次数：" << WaveSort::W_setCount << " 变量使用计数：" << WaveSort::W_memoryCount << " 递归次数：" << WaveSort::W_recursionCount << endl;
	if (isShow)
		for (int i = 0; i < size; i++)
		{
			cout << b[i] << " ";
		}
	cout << endl << endl;
	cout << "BucketSort\n比较次数：" << BucketSort::B_compareCount << " 赋值次数：" << BucketSort::B_setCount << " 变量使用计数：" << BucketSort::B_memoryCount << " 递归次数：" << BucketSort::B_recursionCount << endl;
	if (isShow)
		for (int i = 0; i < size; i++)
		{
			cout << c[i] << " ";
		}
}
void SortCompares()
{
	srand((int)time(0));
	int val = 0;
	int index = 0;
	long int b[size];
	int j = 0;
	//for (int i = size - 1; i >= 0; i--)
	for (int i = 0; i < size; i++)
	{
		b[i] = i;
	}
	
	for (int i = 0; i < RandomCount; i++)
	{
		val = rand() % size;
		index = rand() % size;
		b[index] = val;
	}
	//random_shuffle(b,b + size);
	cout << endl;
	WaveSort::Sort(b, size,10000);
	cout << "WaveSort\n比较次数：" << WaveSort::W_compareCount << " 赋值次数：" << WaveSort::W_setCount << " 变量使用计数：" << WaveSort::W_memoryCount << " 递归次数：" << WaveSort::W_recursionCount << endl;
	if (isShow)
		for (long int i = 0; i < size; i++)
		{
			cout << b[i] << " ";
		}
	//PrintToFile(b);
}
void main()
{
	//SortCompare();
	SortCompares();
}
void PrintToFile(long int * arr)
{
	char data[100];

	// 以写模式打开文件
	ofstream outfile;
	outfile.open("print.dat");

	for (long int i = 0; i < size; i++)
	{
		//cout << arr[i] << ",";
		if (i > 99900000)
			outfile << arr[i] << ",";
	}
	//cin.getline(data, 100);


	//cout << "Enter your age: ";
	//cin >> data;
	//cin.ignore()

	// 关闭打开的文件
	outfile.close();

}

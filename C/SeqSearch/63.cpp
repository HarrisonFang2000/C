/* 
二分查找也属于顺序表查找范围，二分查找也称为折半查找。二分查找(有序)的时间复杂度为O(LogN)。

那么什么是二分查找呢？二分查找的基本思想是， 在有序表中，取中间记录作为比较对象，若给定值与中间记录的关键字相等，
则查找成功；若给定值小于中间记录的关键字，则在中间记录的左半区继续查找；若给定值大于中间记录的关键字，
则在中间记录的右半区继续查找。不断重复上述过程，直到找到为止。

从二分查找的定义我们可以看出，使用二分查找有两个前提条件：

1，待查找的列表必须有序，这里使用递归快排来使产生的随机无序数组有序。

2，必须使用线性表的顺序存储结构来存储数据。

下面是c++实现代码。
*/
//用递归快速排序对随机产生的一组无序数组进行排序，再查找给定的数字，并返回下标，2016.5.27
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#define  MAX 101
void input(int num[])//实参传入的数组的首地址，而不是整个数组
{
	int i;
	srand((unsigned)time(NULL));//产生随机函数的随机数种子
	for (i = 1; i < MAX; i++)
	{
		num[i]=rand() % 100;
	}
}
 
void  output(int num[])
{
	int i;
	for (i = 1; i <= MAX; i++)
	{
		printf("%5d", num[i]);
		if (i % 10 == 0)
			printf("\n");
	}
 
}
 
int Partition( int num[], int low, int high)
{
	//int pivotkey;//这个枢轴的选取很关键，改进版的可以用三数取中，就九数取中等
	int pivotkey=num[low];//在这里就取第一个元素
	num[0] = pivotkey;//备份到num【0】，
	while (low < high)
	{
		while (low < high&&num[high] >= pivotkey)
			high--;
		num[low] = num[high];//不满足循环条件就执行这个语句
		while (low < high&&num[low] <= pivotkey)
			low++;
		num[high] = num[low];
		//交换low，是因为low=pivotkey,比较了。
	}
	num[low] = num[0];
	return low;//最后high和low在某一个位置相遇，就是切分部的值。
}
 
 
void Qsort(int num[], int low, int high)//对随机产生的无序数组进行快速排序，这也是二分法的缺陷之一。
{
	//快排对很多数据更有优势，可以设置一个数据个数的阈值，才进行快排，这里也是一个优化的地方
	int pivot;//
	if (low < high)
	{
		pivot = Partition(num, low, high);
		Qsort(num, low, pivot - 1);//递归的深度决定了时间的复杂度。
		Qsort(num, pivot + 1, high);
	}
}
 
int binaryfind(int num[], int x, int low, int high)
{
	while (low <=high)
	{
		int mid=(low + high) / 2;
		if (x <=num[mid])
			high=mid - 1;
		else if (x >= num[mid])
			low=mid + 1;
		else
			return mid;
	}
}
 
int main()
{
	int x, pos, num[MAX];
	time_t start, end;
	time(&start);
	input(num);
	printf("排序前：\n");
	output(num);
	Qsort(num, 0, MAX - 1);
	printf("排序后：\n");
	output(num);
	printf("请输入我要查找的数字：");
	scanf("%d", &x);
	pos = binaryfind(num, x, 0, MAX - 1);
	if (pos)
		printf("OK!,%d is find in pos %d\n", x, pos);
	else
		printf("sorry!,%d is not find ......\n", x);
	time(&end);
	printf("已运行%d秒\n", end-start);
	system("pause");
}
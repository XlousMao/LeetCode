/*
题目描述
给定你一个长度为n的整数数列，请你使用下面的快速排序算法对这个数列按照从小到大进行排序，并将排好序的数列按顺序输出。

算法Quicksort(A，p，r)
输入：数组A[p..r]
输出：排好序的数组A
	  1. if  p<r
	  2. then q←Partition(A，p，r)
	  3.   A[p]↔A[q]
	  4.   Quicksort(A，p，q-1)
	  5.   Quicksort(A，q+1，r)
初始置p=1，r=n，然后调用上述算法。
算法Partition(A，p，r)
输入：数组A[p..r]
输出：j，A的首元素在排好序的数组中的位置
	1. x←A[p]
	2. i←p
	3. j←r+1
	4. while true do
	5.       repeat  j←j-1
	6.       until  A[ j ]≤x
	7.       repeat  i←i+1
	8.       until  A[ i ]>x
	9.       if  i<j
	10.     then  A[ i ]↔A[ j ]
	11.              if i=j-1 then return j
	12.     else  return j

输入
输入共两行，第一行包含整数n。第二行包含n个整数(所有整数均在1～109范围内)，表示整个数列。

输出
输出共一行，包含n个整数，表示排好序的数列。

样例输入 Copy
5
3 1 2 4 5
样例输出 Copy
1 2 3 4 5

*/


#include <iostream>
#include <vector>
using namespace std;

void swap(int& a, int& b)
{
	int num;
	num = a;
	a = b;
	b = num;
}

void quicksort(vector<int>& arr, int left, int right)
{
	if (left >= right)
		return;
	int i = left, j = right;
	int tag = arr[(left + right) / 2];
	while (i <= j)
	{
		while (arr[i] < tag)i++;
		while (arr[j] > tag)j--;

		if (i <= j)
		{
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}

	quicksort(arr, left, j);
	quicksort(arr, i, right);
}

int main()
{
	int n;
	while (cin >> n) {
		vector<int> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		quicksort(arr, 0, n - 1);
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}


	return 0;
}

/*
题目描述
设计一个实验，实现下述算法。
算法 BinarySearch(T， x)
输入：排好序数组T，数x
输出：j  //如果x在T中，j为下标；否则为0
1.  l←1; r←n
2.  while l≤r do
3.       m←⌊(l+r)/2⌋
4.       if T[m]=x  then return m //x恰好等于中位元素
5.       else if T[m]>x  then r←m-1
6.              else l←m+1
return 0

输入
n
排好序数组T
数x
输出
j  //如果x在T中，j为下标；否则为0
样例输入 Copy
7
1 2 3 4 5 6 7
4
样例输出 Copy
4

*/


#include <iostream>
using namespace std;
#include <vector>

int BinarySearch(vector<int>& T, int x, int left, int right)
{
	int mid=0;
	if (left < right)
	{
		mid = (left + right) / 2;
		if (mid == x)
			return mid;
	}
	else if (x > mid)
	{
		return BinarySearch(T, x, mid + 1, right);
	}
	else
	{
		return BinarySearch(T, x, left, mid - 1);
	}
	return 0;
}

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> T(n + 1);
		int x;
		for (int i = 1; i <= n; i++)
		{
			cin >> T[i];
		}
		cin >> x;
		cout << BinarySearch(T, x, 1, n) << endl;
	}
}
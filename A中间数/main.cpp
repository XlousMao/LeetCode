/*
题目描述
设A是n个不等的数的数组，n>2。以比较作为基本运算，试给出一个O(1)时间的算法，找出A中一个既不是最大也不是最小的数。
输入
n
数组A
输出
A中既不是最大也不是最小的最左边的一个数
样例输入 Copy
7
1 2 3 4 5 6 7
样例输出 Copy
2
*/


#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int n;
	while (std::cin >> n)
	{
		std::vector<int>A;
		for (int i = 0; i < n; i++)
		{
			int temp;
			std::cin >> temp;
			A.push_back(temp);
		}
		std::sort(A.begin(), A.end());
		std::cout << A[1]<<char(10);


	}
	return 0;
}
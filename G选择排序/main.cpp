/*
题目描述
设计一个实验，实现下述选择排序算法，要求算法的基本结构不变。
算法ModSelectSort
输入：n个不等的整数的数组A[1..n]
输出：按递增次序排序的A
1. for i←1 to n-1 do
2.  for j←i+1 to n do
3.    if A[j]<A[i] then A[j]↔A[i]

输入
n
n个不等的整数的数组A[1..n]
输出
按递增次序排序的A
样例输入 Copy
3
3 2 1
样例输出 Copy
1,2,3
*/


#include <iostream>
#include <vector>

using namespace std;

void ModSelectSort(vector<int>& A, int n) {
	for (int i = 1; i <= n - 1; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (A[j] < A[i]) {
				swap(A[i], A[j]);
			}
		}
	}
}

int main() {
	int n;
	while (cin >> n) {
		vector<int> A(n + 1);  // 使用1-based索引
		for (int i = 1; i <= n; ++i) {
			cin >> A[i];
		}
		ModSelectSort(A, n);

		// 格式化输出
		cout << A[1];
		for (int i = 2; i <= n; ++i) {
			cout << "," << A[i];
		}
		cout << endl;
	}
	return 0;
}
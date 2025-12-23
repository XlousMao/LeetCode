/*
题目描述
设A为n个不等的数的数组。给定x，若x在A中，输出x的下标k；若x不在A中，输出0。设计一个实验，实现下述算法：
算法Search(A，x)
  1. if n为奇数 then k←BinarySearch(A，x) //BinarySearch表示二分搜索，
  2. else k←LinearSearch(A，x) //LinearSearch表示顺序搜索，
输入
n
A
x
输出
k
样例输入 Copy
7
1 2 3 4 5 6 7
4
样例输出 Copy
4
*/

#include <iostream>
#include <vector>

using namespace std;

// 顺序查找实现
int LinearSearch(const vector<int>& A, int x) {
	for (int i = 0; i < A.size(); ++i) {
		if (A[i] == x) {
			return i + 1;  // 返回1-based下标
		}
	}
	return 0;
}

// 二分查找实现（要求数组有序）
int BinarySearch(const vector<int>& A, int x) {
	int left = 0, right = A.size() - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (A[mid] == x) {
			return mid + 1;  // 返回1-based下标
		}
		else if (A[mid] < x) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return 0;
}

int main() {
	int n;
	while (cin >> n) {
		vector<int> A(n);
		for (int i = 0; i < n; ++i) {
			cin >> A[i];
		}
		int x;
		cin >> x;

		int result = 0;
		if (n % 2 == 1) {
			result = BinarySearch(A, x);
		}
		else {
			result = LinearSearch(A, x);
		}
		cout << result << endl;
	}
	return 0;
}
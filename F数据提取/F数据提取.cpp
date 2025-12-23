/*
题目描述
设A是n个不同的数排好序的数组，给定数L和U，L<U，设计一个算法找到A中满足L<x<U的所有的数x。
输入
n,L,U
A
输出
输出A中满足L<x<U的所有的数x。
样例输入 Copy
10 2 8
1 2 3 4 5 6 7 8 9 10
样例输出 Copy
3,4,5,6,7

*/


#include <iostream>
#include <vector>
using namespace std;

int findFirstGreaterThan(vector<int>& arr, int target) {
	int left = 0, right = arr.size() - 1;
	int result = arr.size();

	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] > target) {
			result = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return result;
}

int findLastLessThan(vector<int>& arr, int target) {
	int left = 0, right = arr.size() - 1;
	int result = -1;

	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] < target) {
			result = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return result;
}

int main() {
	int n, L, U;
	while (cin >> n >> L >> U) {
		vector<int> A(n);

		for (int i = 0; i < n; i++) {
			cin >> A[i];
		}

		int leftIndex = findFirstGreaterThan(A, L);
		int rightIndex = findLastLessThan(A, U);
		if (leftIndex <= rightIndex) {
			for (int i = leftIndex; i <= rightIndex; i++) {
				if (i > leftIndex) {
					cout << ",";
				}
				cout << A[i];
			}
			cout << endl;
		}
		else {
			cout << endl;
		}
	}

	return 0;
}
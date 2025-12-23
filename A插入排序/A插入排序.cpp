/*
题目描述
设输入是n个数的数组A[1..n]，下述排序算法是插入排序。
算法 InsertSort(A)
1. for i←2 to n do
2.     x←A[i]
3.     j←i-1
4.     while j>0 and A[j]>x do
5.         A[j+1]←A[j]
6.         j←j-1
7.     A[j+1]←x
改进上述算法，在插入元素A[i]时用二分查找代替顺序查找，将这个算法记作ModInsertSort。
输入
n
数组A[1..n]
输出
排序的数组A[1..n]
样例输入 Copy
13
27 99 0 8 13 64 86 16 7 10 88 25 90
样例输出 Copy
0,7,8,10,13,16,25,27,64,86,88,90,99

*/



#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& A, int left, int right, int x) {
	int mid;
	if (left <= right) {
		mid = (left + right) / 2;
		if (A[mid] == x) return mid;
		if (A[mid] < x) {
			return binarySearch(A, mid + 1, right, x);
		}
		else {
			return binarySearch(A, left, mid - 1, x);
		}
	}
	return left;
}

void ModInsertSort(vector<int>& A) {
	int n = A.size();

	for (int i = 1; i < n; i++) {
		int x = A[i];

		int pos = binarySearch(A, 0, i - 1, x);

		for (int j = i; j > pos; j--) {
			A[j] = A[j - 1];
		}

		A[pos] = x;
	}
}

void InsertSort(vector<int>& A) {
	int n = A.size();

	for (int i = 1; i < n; i++) {
		int x = A[i];
		int j = i - 1;

		while (j >= 0 && A[j] > x) {
			A[j + 1] = A[j];
			j = j - 1;
		}
		A[j + 1] = x;
	}
}

void printArray(const vector<int>& A) {
	for (int i = 0; i < A.size(); i++) {
		cout << A[i];
		if (i < A.size() - 1) cout << ",";
	}
	cout << endl;
}

int main() {
	int n;
	while (cin >> n) {
		vector<int> A(n);
		for (int i = 0; i < n; i++) {
			cin >> A[i];
		}


		ModInsertSort(A);

		printArray(A);
	}


	return 0;
}

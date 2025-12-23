/*
题目描述
设A是n个非0实数构成的数组，设计一个算法重新排列数组中的数，使得负数都排在正数前面。要求算法使用O(n)的时间和O(1)的空间。

输入
n
A


输出
A
样例输入 Copy
7
1 -2 3 -4 5 -6 7
样例输出 Copy
-2 -4 -6 1 3 5 7

*/

#include <iostream>
#include <vector>
using namespace std;

void rearrangeNegativesPositives(vector<int>& arr) {
	int n = arr.size();
	int countNeg = 0;

	// 第一遍扫描：统计负数的个数
	for (int i = 0; i < n; i++) {
		if (arr[i] < 0) {
			countNeg++;
		}
	}

	// 使用两个指针，一个指向当前负数位置，一个指向当前正数位置
	int negIndex = 0;
	int posIndex = countNeg;

	// 创建临时数组（但题目要求O(1)空间，所以这个不符合要求）
	vector<int> temp(n);
	for (int i = 0; i < n; i++) {
		if (arr[i] < 0) {
			temp[negIndex++] = arr[i];
		}
		else {
			temp[posIndex++] = arr[i];
		}
	}

	// 复制回原数组
	arr = temp;
}

int main() {
	int n;

	while (cin >> n) {
		vector<int> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		rearrangeNegativesPositives(arr);

		for (int i = 0; i < n; i++) {
			cout << arr[i];
			if (i < n - 1) {
				cout << " ";
			}
		}
		cout << endl;
	}

	return 0;
}
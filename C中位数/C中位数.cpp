/*

题目描述
设A和B都是从小到大已经排好序的n个不等的整数构成的数组，如果把A与B合并后的数组记作C，设计一个算法找出C的中位数。
输入
n
A
B
输出
C的中位数。
样例输入 Copy
3
1 2 3
1 2 3
样例输出 Copy
2
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 使用二分查找的方法找到两个有序数组的中位数
int findMedian(vector<int>& A, vector<int>& B, int n) {
	int left = 0, right = n - 1;

	while (left <= right) {
		int i = (left + right) / 2;      // A数组的分割点
		int j = n - i - 1;               // B数组的分割点

		// 检查分割点是否有效
		if (i < n - 1 && B[j] > A[i + 1]) {
			// 需要向右移动A的分割点
			left = i + 1;
		}
		else if (i > 0 && A[i] > B[j + 1]) {
			// 需要向左移动A的分割点
			right = i - 1;
		}
		else {
			// 找到了正确的分割点
			// 中位数是 max(A[i], B[j])
			return max(A[i], B[j]);
		}
	}

	// 如果上面的循环没有返回，返回边界情况
	if (left == 0) {
		return B[n - 1];
	}
	else {
		return A[n - 1];
	}
}

int main() {
	int n;

	// 处理多轮输入
	while (cin >> n) {
		vector<int> A(n), B(n);

		// 读取数组A
		for (int i = 0; i < n; i++) {
			cin >> A[i];
		}

		// 读取数组B
		for (int i = 0; i < n; i++) {
			cin >> B[i];
		}

		// 找到中位数并输出
		int median = findMedian(A, B, n);
		cout << median << endl;
	}

	return 0;
}
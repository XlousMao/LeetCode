/*
题目描述
设A是含有n个元素的数组，如果元素x在A中出现的次数大于n/2，则称x是A的主元素。设计一个算法，判断A中是否存在主元素。
输入
n
A
输出
主元素
样例输入 Copy
10
2 3 1 2 2 2 5 4 2 2
样例输出 Copy
2

*/


#include <iostream>
#include <vector>
using namespace std;

// 计算元素x在数组nums的指定区间[front, rear]中出现的次数
int countInRange(vector<int>& nums, int x, int front, int rear) {
	int count = 0;
	for (int i = front; i <= rear; i++) {
		if (nums[i] == x) {
			count++;
		}
	}
	return count;
}

int findMajority(vector<int>& nums, int front, int rear) {
	if (front == rear) {
		return nums[front];
	}

	int mid = front + (rear - front) / 2;

	int leftMajority = findMajority(nums, front, mid);
	int rightMajority = findMajority(nums, mid + 1, rear);

	if (leftMajority == rightMajority) {
		return leftMajority;
	}
	int leftCount = countInRange(nums, leftMajority, front, rear);
	int rightCount = countInRange(nums, rightMajority, front, rear);

	int n = rear - front + 1;
	if (leftCount > n / 2) {
		return leftMajority;
	}
	else if (rightCount > n / 2) {
		return rightMajority;
	}
	else {
		return -1;
	}
}

int main() {
	int n;
	while (cin >> n) {
		vector<int> A(n);
		for (int i = 0; i < n; i++) {
			cin >> A[i];
		}

		int result = findMajority(A, 0, n - 1);

		if (result != -1 && countInRange(A, result, 0, n - 1) > n / 2) {
			cout << result << endl;
		}
		else {
			cout << "No majority element" << endl;
		}
	}

	return 0;
}
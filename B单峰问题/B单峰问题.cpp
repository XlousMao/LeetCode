/*
题目描述
给定含有n个不同的数的数组L=<x1，x2，…，xn>。如果L中存在xi，使得x1<x2<...<xi>xi+1>...>xn，则称L是单峰的，并称xi是L的“峰顶”。假设L是单峰的，设计一个算法找到L的峰顶。
输入
n
x1，x2，…，xn
输出
xi
样例输入 Copy
7
1 2 3 4 3 2 1
样例输出 Copy
4


*/


#include <iostream>
#include <vector>
using namespace std;

int findPeak(vector<int>& L) {
	int left = 0;
	int right = L.size() - 1;

	while (left < right) {
		int mid = left + (right - left) / 2;
		if (L[mid] > L[mid + 1]) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}
	return L[left];
}

int main() {
	int n;

	while (cin >> n) {
		vector<int> L(n);
		for (int i = 0; i < n; i++) {
			cin >> L[i];
		}

		int peak = findPeak(L);
		cout << peak << endl;
	}

	return 0;
}
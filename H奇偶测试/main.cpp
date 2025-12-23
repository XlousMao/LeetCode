/*
题目描述
给定正整数的数组A[1..n]，测试A的每个元素A[i]的奇偶性。如果A[i]是奇数，则将它2倍后输出；否则直接输出A[i]。
输入
n
正整数的数组A[1..n]
输出
如果A[i]是奇数，则将它2倍后输出；否则直接输出A[i]。
样例输入 Copy
2
1 2
样例输出 Copy
2,2
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	while (cin >> n) {
		vector<int> A(n);
		for (int i = 0; i < n; ++i) {
			cin >> A[i];
		}
		for (int i = 0; i < n; ++i) {
			if (A[i] % 2 == 1) {
				A[i] *= 2;
			}
		}
		cout << A[0];
		for (int i = 1; i < n; ++i) {
			cout << "," << A[i];
		}
		cout << endl;
	}
	return 0;
}
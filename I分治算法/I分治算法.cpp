/*
题目描述
设计一个实验，用下述分治算法的一般性描述实现二分检索。
Divide-and-Conquer(P)
	1.  if  |P|≤c  then  S(P)
	2.  divide P into P1， P2， …， Pk
	3.  for i←1 to k
	4.        yi←Divide-and-Conquer(Pi)
	5．Return Merge(y1， y2， …， yk)

输入
n
排好序数组T
数x

输出
输出：j  //如果x在T中，j为下标；否则为0

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

int BinarySearch(vector<int>& T, int left, int right, int x) {
	if (left > right) {
		return 0;
	}

	int mid = (left + right) / 2;

	if (T[mid] == x) {
		return mid + 1;
	}
	else if (x < T[mid]) {
		return BinarySearch(T, left, mid - 1, x);
	}
	else {
		return BinarySearch(T, mid + 1, right, x);
	}
}

int main() {
	int n, x;
	while (cin >> n) {
		vector<int> T(n);
		for (int i = 0; i < n; i++) {
			cin >> T[i];
		}

		cin >> x;

		int result = BinarySearch(T, 0, n - 1, x);

		cout << result << endl;
	}

	return 0;
}
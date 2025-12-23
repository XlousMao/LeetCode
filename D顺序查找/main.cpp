/*
题目描述
已知L是含有n个元素并且事先排好序的数组。设计一个实验，实现下述查找算法，要求算法的基本结构不变。
算法 顺序查找
1.j←1
2.while j≤n and x>L[j] do
3.    j←j+1
4.if x<L[j] or j>n
5.then j←0

输入
n，x
L
输出
j
样例输入 Copy
7 4
1 2 3 4 5 6 7
样例输出 Copy
4

*/


#include <iostream>
#include <vector>

using namespace std;

// 顺序查找实现（基于哨兵优化）
int Sequential_Search(const vector<int>& L, int x, int n) {
	int j = 1;  // 初始化下标为1-based
	while (j <= n && x > L[j - 1]) {  // 注意数组是0-based存储
		j++;
	}
	if (x < L[j - 1] || j > n) {  // 边界条件判断
		j = 0;
	}
	return j;
}

int main() {
	int n, x;
	while (cin >> n >> x) {
		vector<int> L(n);
		for (int i = 0; i < n; ++i) {
			cin >> L[i];
		}
		cout << Sequential_Search(L, x, n) << endl;
	}
	return 0;
}
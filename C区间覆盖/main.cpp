/*
题目描述
给定数轴X上n个不同点的集合{x1,x2,…,xn},其中x1<x2<…<xn。现在用若干个长度为1的闭区间来覆盖这些点。设计一个算法找到最少的闭区间个数和位置。
输入
n
x1,x2,…,xn
输出
最少的闭区间个数和位置
样例输入 Copy
6
1 3 4 8 12 15
样例输出 Copy
5
[1,2],[3,4],[8,9],[12,13],[15,16]

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	while (cin >> n) {
		vector<int> x(n);
		for (int i = 0; i < n; ++i) {
			cin >> x[i];
		}
		sort(x.begin(), x.end()); // 确保点是有序的

		vector<pair<int, int>> intervals;
		if (n > 0) {
			int i = 0;
			while (i < n) {
				int start = x[i];
				int end = start + 1;
				intervals.push_back({ start, end });
				// 跳过所有已经被当前区间覆盖的点
				while (i < n && x[i] <= end) {
					i++;
				}
			}
		}

		cout << intervals.size() << endl;
		for (int i = 0; i < intervals.size(); ++i) {
			if (i) cout << ",";
			cout << "[" << intervals[i].first << "," << intervals[i].second << "]";
		}
		cout << endl;
	}
	return 0;
}
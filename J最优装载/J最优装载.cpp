/*
题目描述
n个集装箱1,2,…,n装上轮船,集装箱i的重量wi ,轮船装载重量限制为C,无体积限制。问如何装使得上船的集装箱最多？不妨设wi≤C。

输入
集装箱个数n,集装箱限重C
集装箱集合N={1,2...,n}，集装箱i的重量wi,i=1,2..n。
输出
集装箱集合I包含于N，将装载的物品序列顺序输出。
上船的集装箱数
样例输入 Copy
5 11
4 6 2 8 5
样例输出 Copy
3,1,5
3

*/



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 结构体记录原始编号和重量
struct Container {
	int id;
	int weight;
};

// 贪心策略：按重量从小到大排序
bool compareWeight(const Container& a, const Container& b) {
	if (a.weight != b.weight) return a.weight < b.weight;
	return a.id < b.id; // 如果重量相同，按原始编号先后排队
}

int main() {
	int n, C;
	// 处理多组输入
	while (cin >> n >> C) {
		vector<Container> containers(n);
		for (int i = 0; i < n; ++i) {
			containers[i].id = i + 1; // 原始编号 1-n
			cin >> containers[i].weight;
		}

		// 核心贪心：按重量排序
		sort(containers.begin(), containers.end(), compareWeight);

		int currentWeight = 0;
		vector<int> resultOrder;

		// 依次选取最轻的物品
		for (int i = 0; i < n; ++i) {
			if (currentWeight + containers[i].weight <= C) {
				currentWeight += containers[i].weight;
				resultOrder.push_back(containers[i].id); // 记录选择顺序
			}
			else {
				break;
			}
		}

		// 1. 第一行：按贪心选择的顺序（3,1,5）输出编号
		for (int i = 0; i < resultOrder.size(); ++i) {
			cout << resultOrder[i] << (i == resultOrder.size() - 1 ? "" : ",");
		}
		cout << endl;

		// 2. 第二行：输出上船的总数
		cout << resultOrder.size() << endl;
	}
	return 0;
}
/*
题目描述
给定n种物品和一个背包。物品i的重量是Wi，其价值为Vi，背包的容量为C。应如何选择装入背包的物品，使得装入背包中物品的总价值最大?
在选择物品i装入背包时，可以选择物品i的一部分，而不一定要全部装入背包，1≤i≤n。
输入
n C
Vi
Wi
输出
装入背包中物品的最大总价值
选择装入背包的物品



样例输入 Copy
3 50
60 100 120
10 20 30
样例输出 Copy
240
<1,1,0.667>

*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// 物品结构体
struct Item {
	int id;         // 原始序号
	double v;       // 价值
	double w;       // 重量
	double unit;    // 单位价值
};

// 贪心策略：性价比从高到低排序
bool cmp(const Item& a, const Item& b) {
	if (a.unit != b.unit) return a.unit > b.unit;
	return a.id < b.id; // 性价比相同时按编号排序
}

int main() {
	int n;
	double C;
	// 多组数据录入风格
	while (cin >> n >> C) {
		vector<Item> items(n);
		// 第一行输入所有价值 Vi
		for (int i = 0; i < n; ++i) {
			items[i].id = i;
			cin >> items[i].v;
		}
		// 第二行输入所有重量 Wi
		for (int i = 0; i < n; ++i) {
			cin >> items[i].w;
			items[i].unit = items[i].v / items[i].w;
		}

		// 排序进行贪心选择
		vector<Item> sorted_items = items;
		sort(sorted_items.begin(), sorted_items.end(), cmp);

		vector<double> x(n, 0.0); // 存储每个物品装入的比例
		double totalV = 0.0;
		double currentC = C;

		for (int i = 0; i < n; ++i) {
			if (sorted_items[i].w <= currentC) {
				// 能够完全装入
				x[sorted_items[i].id] = 1.0;
				totalV += sorted_items[i].v;
				currentC -= sorted_items[i].w;
			}
			else {
				// 部分装入
				if (currentC > 0) {
					x[sorted_items[i].id] = currentC / sorted_items[i].w;
					totalV += sorted_items[i].unit * currentC;
					currentC = 0;
				}
				break;
			}
		}

		// 输出最大总价值（直接输出即可，cout会自动处理整数）
		cout << totalV << endl;

		// 输出装入方案 <x1,x2,x3...>
		cout << "<";
		for (int i = 0; i < n; ++i) {
			if (i > 0) cout << ",";
			if (x[i] == 1.0 || x[i] == 0.0) {
				cout << (int)x[i]; // 整数输出 1 或 0
			}
			else {
				// 小数保留三位
				cout << fixed << setprecision(3) << x[i];
			}
		}
		cout << ">" << endl;
	}
	return 0;
}
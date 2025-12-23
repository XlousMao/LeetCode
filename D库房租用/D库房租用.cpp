/*
题目描述
有n个底面为长方形的物品需要租用库房存放。如果每个物品都必须放在地面上，且所有物品的底面宽度都等于库房的宽度，那么第i个物品占用库房面积大小只需要用它的底面长度li来表示，i=1，2，…，n。设库房总长度是L，且。如果要求放入库房的物品个数最多，试设计一个算法。
输入
n，L
li，i=1，2，…，n。


输出
放入库房的物品个数n'
按存放顺序输出物品编号ij，j=1，2，…，n'。

样例输入 Copy
5 11
4 6 2 8 5
样例输出 Copy
3
3,1,5

*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 定义物品结构体
struct Item {
	int id;
	int length;
};

// 贪心策略：长度短的优先。若长度相同，编号小的优先（保证稳定性）
bool compareItems(const Item& a, const Item& b) {
	if (a.length != b.length) {
		return a.length < b.length;
	}
	return a.id < b.id;
}

int main() {
	int n, L;
	// 录入风格：处理多组数据
	while (cin >> n >> L) {
		vector<Item> items(n);
		for (int i = 0; i < n; ++i) {
			items[i].id = i + 1;
			cin >> items[i].length;
		}

		// 1. 按长度从小到大排序
		sort(items.begin(), items.end(), compareItems);

		vector<int> res;
		int sumL = 0;

		// 2. 贪心选择：依次放入最短的物品
		for (int i = 0; i < n; ++i) {
			if (sumL + items[i].length <= L) {
				sumL += items[i].length;
				res.push_back(items[i].id);
			}
			else {
				break;
			}
		}

		// 3. 输出数量
		cout << res.size() << endl;

		// 4. 按“长度从小到大”的顺序输出编号
		// 注意：不要再对 res 进行排序，直接按存入顺序输出
		for (int i = 0; i < res.size(); ++i) {
			if (i > 0) cout << ",";
			cout << res[i];
		}
		cout << endl;
	}
	return 0;
}
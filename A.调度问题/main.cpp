/*
题目描述
设有n个顾客同时等待一项服务，顾客i需要的服务时间为ti，i=1，2，…，n。从时刻0开始计时，若在时刻t开始对顾客i服务，那么i的等待时间就是t。应该怎样安排n个顾客的服务次序使得总的等待时间(每个顾客等待时间的总和)最少?
输入
n
ti，i=1，2，…，n


输出
总等待时间
ij，j=1，2，…，n
样例输入 Copy
7
1 3 2 15 10 6 12
样例输出 Copy
78
1,3,2,6,5,7,4


*/





#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 定义结构体来保存服务时间和原始序号
struct Customer {
	int id;
	int time;
};

// 按照服务时间升序排序，如果时间相同，按序号升序
bool compareCustomers(const Customer& a, const Customer& b) {
	if (a.time != b.time) {
		return a.time < b.time;
	}
	return a.id < b.id;
}

int main() {
	int n;
	// 保持 while(cin >> n) 风格以支持多组测试数据
	while (cin >> n) {
		vector<Customer> customers(n);
		for (int i = 0; i < n; ++i) {
			customers[i].id = i + 1; // 序号从 1 开始
			cin >> customers[i].time;
		}

		// 使用贪心策略排序：时间短的在前
		sort(customers.begin(), customers.end(), compareCustomers);

		long long totalWaitTime = 0;
		long long currentWaitTime = 0;

		// 计算总等待时间
		// 注意：第一个人的等待时间是 0
		for (int i = 0; i < n; ++i) {
			totalWaitTime += currentWaitTime;
			currentWaitTime += customers[i].time;
		}

		// 第一行输出总等待时间
		cout << totalWaitTime << endl;

		// 第二行输出服务次序（原始序号），逗号分隔，末尾无空格
		for (int i = 0; i < n; ++i) {
			if (i > 0) cout << ",";
			cout << customers[i].id;
		}
		cout << endl;
	}

	return 0;
}
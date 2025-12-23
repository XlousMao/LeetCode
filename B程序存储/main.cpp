/*
题目描述
设有n个程序1，2，…，n要存放在长度为L的磁带上，程序i存放在磁带上的长度是li，1≤i≤n。
程序存储问题要求确定这n个程序在磁带上的一个存储方案，使得能够在磁带上存储尽可能多的程序。
输入
第一行是2个正整数，分别表示程序个数n和磁带的长度L。
接下来的1行中，有n个正整数，表示程序存放在磁带上的长度。
输出
输出最多可以存储的程序数
存储方案

样例输入 Copy
6 50
2 3 13 8 80 20
样例输出 Copy
5
1,2,4,3,6


*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 定义结构体记录程序长度和原始编号
struct Program {
	int id;
	int length;
};

// 按照程序长度升序排序
bool comparePrograms(const Program& a, const Program& b) {
	if (a.length != b.length) {
		return a.length < b.length;
	}
	return a.id < b.id; // 长度相同时按编号排序
}

int main() {
	int n, L;
	// 使用 while(cin >> n >> L) 适应学校平台的读取风格
	while (cin >> n >> L) {
		vector<Program> progs(n);
		for (int i = 0; i < n; ++i) {
			progs[i].id = i + 1; // 编号从 1 开始
			cin >> progs[i].length;
		}

		// 贪心策略：排序，先存短的
		sort(progs.begin(), progs.end(), comparePrograms);

		vector<int> selectedIds;
		int currentTotalLength = 0;
		int count = 0;

		// 顺序选取程序直到磁带满
		for (int i = 0; i < n; ++i) {
			if (currentTotalLength + progs[i].length <= L) {
				currentTotalLength += progs[i].length;
				selectedIds.push_back(progs[i].id);
				count++;
			}
			else {
				// 磁带放不下了
				break;
			}
		}

		// 第一行输出：最多可以存储的程序数
		cout << count << endl;

		// 第二行输出：存储方案（原始编号），逗号分隔
		for (int i = 0; i < selectedIds.size(); ++i) {
			if (i > 0) cout << ",";
			cout << selectedIds[i];
		}
		cout << endl;
	}

	return 0;
}
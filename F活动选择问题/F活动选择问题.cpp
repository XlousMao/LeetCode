/*
题目描述
sdut大学生艺术中心每天都有n个活动申请举办，但是为了举办更多的活动，必须要放弃一些活动，求出每天最多能举办多少活动。

输入
输入包括多组输入，每组输入第一行为申请的活动数n，从第2行到n+1行，每行两个数，是每个活动的开始时间b，结束时间e。
输出
输出每天最多能举办的活动数。
样例输入 Copy
12
15 20
15 19
8 18
10 15
4 14
6 12
5 10
2 9
3 8
0 7
3 4
1 3
样例输出 Copy
5

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 定义活动结构体
struct Activity {
	int start;
	int end;
};

// 贪心策略：按结束时间从早到晚排序
bool compareActivities(const Activity& a, const Activity& b) {
	if (a.end != b.end) {
		return a.end < b.end;
	}
	return a.start < b.start; // 如果结束时间相同，按开始时间排序
}

int main() {
	int n;
	// 录入风格：处理多组数据，每组第一行为活动数 n
	while (cin >> n) {
		vector<Activity> acts(n);
		// 读取每个活动的开始时间 b 和结束时间 e
		for (int i = 0; i < n; ++i) {
			cin >> acts[i].start >> acts[i].end;
		}

		// 1. 核心步骤：排序
		sort(acts.begin(), acts.end(), compareActivities);

		int count = 0;
		int last_end_time = -1; // 记录上一个选中活动的结束时间

		// 2. 核心步骤：贪心选择
		for (int i = 0; i < n; ++i) {
			// 如果当前活动的开始时间不早于上个活动的结束时间
			if (acts[i].start >= last_end_time) {
				count++;
				last_end_time = acts[i].end; // 更新结束时间边界
			}
		}

		// 输出每天最多能举办的活动数
		cout << count << endl;
	}
	return 0;
}
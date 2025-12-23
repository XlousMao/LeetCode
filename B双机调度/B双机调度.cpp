/*
题目描述
设有n项任务，加工时间分别表示为正整数t1，t2，…，tn。现有2台同样的机器，从0时刻开始安排对这些任务的加工。规定只要有待加工的任务，任何机器就不得闲置。如果直到时刻T所有任务都完成了，总的加工时间就等于T。设计一个算法找到使得总加工时间T达到最小的调度方案。
输入
n
t1，t2，…，tn
输出
总加工时间T
调度方案

样例输入 Copy
5
1 5 2 10 3
样例输出 Copy
11
2,3,5

*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	while (cin >> n) {
		vector<int> t(n);
		int total = 0;
		for (int i = 0; i < n; ++i) {
			cin >> t[i];
			total += t[i];
		}

		int target = total / 2;
		vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
		dp[0][0] = true;

		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j <= target; ++j) {
				dp[i][j] = dp[i - 1][j];
				if (j >= t[i - 1]) {
					dp[i][j] = dp[i][j] || dp[i - 1][j - t[i - 1]];
				}
			}
		}

		int best = 0;
		for (int j = target; j >= 0; --j) {
			if (dp[n][j]) {
				best = j;
				break;
			}
		}

		int T = max(best, total - best);
		cout << T << endl;

		vector<int> selected;
		int i = n, j = best;
		while (i > 0 && j > 0) {
			if (dp[i - 1][j]) {
				if (j >= t[i - 1] && dp[i - 1][j - t[i - 1]]) {
					if (!dp[i - 1][j]) {
						selected.push_back(i);
						j -= t[i - 1];
					}
					else {
					}
				}
				i--;
			}
			else {
				selected.push_back(i);
				j -= t[i - 1];
				i--;
			}
		}

		selected.clear();
		i = n;
		j = best;
		while (i > 0) {
			if (j >= t[i - 1] && dp[i - 1][j - t[i - 1]]) {
				selected.push_back(i);
				j -= t[i - 1];
				i--;
			}
			else {
				i--;
			}
		}

		sort(selected.begin(), selected.end());

		for (int idx = 0; idx < selected.size(); ++idx) {
			if (idx > 0) cout << ",";
			cout << selected[idx];
		}
		cout << endl;

	}
	return 0;
}
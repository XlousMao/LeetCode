/*
题目描述
设有n种硬币，其价值分别为v1=1，v2，... ，vn，v1<v2<…<vn，现在需要用这些硬币付款的总钱数是Y，币值和钱数都为正整数。问：如何选择这些硬币而使得付钱的硬币总张数最少?
输入
n,Y
v1=1,v2,... ,vn
输出
付钱的硬币总张数
样例输入 Copy
4 28
1 5 14 18
样例输出 Copy
2

*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, Y;
	// 录入风格：处理多组数据
	while (cin >> n >> Y) {
		vector<int> v(n);
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
		}

		// 初始化 dp 数组，size 为 Y+1
		// 设为 Y+1 是因为硬币最小面值是 1，最坏情况张数不会超过 Y
		vector<int> dp(Y + 1, Y + 1);
		dp[0] = 0; // 凑齐 0 元需要 0 张硬币

		// 动态规划填表过程
		for (int i = 0; i < n; ++i) { // 遍历每种硬币面值
			for (int j = v[i]; j <= Y; ++j) { // 更新所有大于该面值的 dp 值
				if (dp[j - v[i]] != Y + 1) {
					dp[j] = min(dp[j], dp[j - v[i]] + 1);
				}
			}
		}

		// 输出凑齐 Y 元的最少硬币总张数
		cout << dp[Y] << endl;
	}
	return 0;
}
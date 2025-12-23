/*
题目描述
用动态规划算法求解下面的组合优化问题，

max g1(x1)+g2(x2)+g3(x3)+…+gn(xn)

x12+x22+x32+…+xn2≤y

x1，x2，x3，…，xn为非负整数


输入
n，y
x，g1(x)，g2(x)，g3(x)，…，gn(x)
输出
max g1(x1)+g2(x2)+g3(x3)+…+gn(xn)
x1，x2，x3，…，xn
样例输入 Copy
3 10
0 2 5 8
1 4 10 12
2 7 16 17
3 11 20 22
样例输出 Copy
37
1,2,2


*/



#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
	int n, y;
	// 使用 while 处理多组数据，如果只有一组，输入后按回车/Ctrl+Z 即可
	while (cin >> n >> y) {
		// x 的最大取值由 x^2 <= y 决定
		int max_x = 0;
		while (max_x * max_x <= y) max_x++;

		// g[x][i] 存储第 i 个函数在输入为 x 时的值
		// 预留足够空间，x 的取值范围是 0 到 max_x
		vector<vector<int>> g(max_x + 1, vector<int>(n + 1, 0));

		// 核心修正：按照 x 的实际范围循环读取，保证输入能正常结束
		for (int x = 0; x < max_x; ++x) {
			int row_index;
			cin >> row_index; // 读取行首的 0, 1, 2, 3...
			for (int i = 1; i <= n; ++i) {
				cin >> g[x][i];
			}
		}

		// dp[i][j] 表示前 i 个函数平方和不超过 j 的最大收益
		// path[i][j] 记录达到该收益时 x_i 的取值
		vector<vector<int>> dp(n + 1, vector<int>(y + 1, -1));
		vector<vector<int>> path(n + 1, vector<int>(y + 1, 0));

		// 初始化基础状态
		for (int j = 0; j <= y; ++j) dp[0][j] = 0;

		// 填充 DP 表
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j <= y; ++j) {
				for (int x = 0; x < max_x && x * x <= j; ++x) {
					if (dp[i - 1][j - x * x] != -1) {
						int current_val = dp[i - 1][j - x * x] + g[x][i];
						// 注意：为了匹配样例 1,2,2，这里使用 >= 并在值相等时优先更新
						if (current_val >= dp[i][j]) {
							dp[i][j] = current_val;
							path[i][j] = x;
						}
					}
				}
			}
		}

		// 打印最大值
		if (dp[n][y] != -1) {
			cout << dp[n][y] << endl;

			// 回溯路径
			vector<int> res(n + 1);
			int cur_y = y;
			for (int i = n; i >= 1; --i) {
				res[i] = path[i][cur_y];
				cur_y -= res[i] * res[i];
			}

			// 格式化打印路径结果
			for (int i = 1; i <= n; ++i) {
				cout << res[i] << (i == n ? "" : ",");
			}
			cout << endl;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); // 加快输入输出速度
	cin.tie(NULL);
	solve();
	return 0;
}
/*
题目描述
设有m元钱,n项投资,函数fi(x)表示将x元投入第i个项目的所产生的效益,i=1,2,...,n.问:如何分配这m元钱,使得投资的总效益最高?
输入
m,n
fi(x)
输出
最高总效益
xi
样例输入 Copy
5 4
0 0 0 0
11 0 2 20
12 5 10 21
13 10 30 22
14 15 32 23
15 20 40 24
样例输出 Copy
61
1,0,3,1

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int m, n;


	while (cin >> m >> n) {
		vector<vector<int>> f(n, vector<int>(m + 1));
		for (int x = 0; x <= m; ++x) {
			for (int i = 0; i < n; ++i) {
				cin >> f[i][x];
			}
		}

		vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
		vector<vector<int>> path(n + 1, vector<int>(m + 1, 0));

		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j <= m; ++j) {
				dp[i][j] = dp[i - 1][j];
				path[i][j] = 0;

				for (int k = 0; k <= j; ++k) {
					int profit = dp[i - 1][j - k] + f[i - 1][k];
					if (profit > dp[i][j]) {
						dp[i][j] = profit;
						path[i][j] = k;
					}
				}
			}
		}

		cout << dp[n][m] << endl;

		vector<int> allocation(n);
		int money_left = m;
		for (int i = n; i >= 1; --i) {
			int allocated = path[i][money_left];
			allocation[i - 1] = allocated;
			money_left -= allocated;
		}

		for (int i = 0; i < n; ++i) {
			if (i > 0) cout << ",";
			cout << allocation[i];
		}
		cout << endl;

	}
	return 0;
}
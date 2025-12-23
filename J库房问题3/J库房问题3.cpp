/*
题目描述
有n个底面为长方形的货柜需要租用库房存放。如果每个货柜都必须放在地面上，且所有货柜的底面宽度都等于库房的宽度，那么第i个货柜占用库房面积大小只需要用它的底面长度li来表示，i=1，2，…，n。设库房总长度是D(li≤D且)。设第i号货柜的仓储收益是vi，若要求库房出租的收益达到最大，问如何选择放入库房的货柜?若l1，l2，…ln，D都是正整数，设计一个算法求解这个问题。
输入
n
D
l1 v1
l2 v2
…
ln vn
输出
最大收益
选择放入库房的货柜


样例输入 Copy
4 10
2 1
3 3
4 5
7 9
样例输出 Copy
12
0,1,0,1

*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, D;


	while (cin >> n >> D) {
		vector<int> l(n), v(n);
		for (int i = 0; i < n; ++i) {
			cin >> l[i] >> v[i];
		}

		vector<vector<int>> dp(n + 1, vector<int>(D + 1, 0));
		vector<vector<bool>> choice(n + 1, vector<bool>(D + 1, false));

		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j <= D; ++j) {
				dp[i][j] = dp[i - 1][j];

				if (j >= l[i - 1]) {
					int select = dp[i - 1][j - l[i - 1]] + v[i - 1];
					if (select > dp[i][j]) {
						dp[i][j] = select;
						choice[i][j] = true;
					}
				}
			}
		}

		cout << dp[n][D] << endl;

		vector<bool> selected(n, false);
		int i = n, j = D;
		while (i > 0 && j > 0) {
			if (choice[i][j]) {
				selected[i - 1] = true;
				j -= l[i - 1];
			}
			i--;
		}

		for (int idx = 0; idx < n; ++idx) {
			if (idx > 0) cout << ",";
			cout << (selected[idx] ? 1 : 0);
		}
		cout << endl;
	}

	return 0;
}
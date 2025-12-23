/*
题目描述
设M是一个n行n列的0-1矩阵，每行的1都排在0的前面。设计一个算法找到M中含有1最多的行。
输入
n
M
输出
M中含有1最多的行
样例输入 Copy
6
1 1 1 0 0 0
0 0 0 0 0 0
1 1 1 1 0 0
1 1 0 0 0 0
1 1 1 1 1 0
1 1 1 1 0 0
样例输出 Copy
5


*/


#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		vector<vector<int>> M(n, vector<int>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> M[i][j];
			}
		}

		int maxRow = 0;
		int maxCount = 0;

		for (int i = 0; i < n; i++) {
			int count = 0;
			for (int j = 0; j < n; j++) {
				if (M[i][j] == 1) {
					count++;
				}
				else {
					break;
				}
			}

			if (count > maxCount) {
				maxCount = count;
				maxRow = i;
			}
		}


		cout << maxRow + 1 << endl;

	}

	return 0;
}
/*
题目描述
以下算法是用动态规划法编写的最长公共子序列问题：给定2个序列X={x1,x2,…,xm}和Y={y1,y2,…,yn}，找出X和Y的最长公共子序的长度。设计一个实验实现它，要求保持算法的基本结构不变。
void LCSLength(int m，int n，char *x，char *y，int **c，int **b)
{
	   int i，j;
	   for (i = 1; i <= m; i++) c[i][0] = 0;
	   for (i = 1; i <= n; i++) c[0][i] = 0;
	   for (i = 1; i <= m; i++)
		  for (j = 1; j <= n; j++) {
			 if (x[i]==y[j]) {
				  c[i][j]=c[i-1][j-1]+1; b[i][j]=1;}
else if (c[i-1][j]>=c[i][j-1]) {
				  c[i][j]=c[i-1][j]; b[i][j]=2;}
			 else { c[i][j]=c[i][j-1]; b[i][j]=3; }
			 }
}
输入
m,n
X,Y
输出
X和Y的最长公共子序的长度
最长公共子序列



样例输入 Copy
7 6
ABCBDAB
BDCABA
样例输出 Copy
4
<B,C,B,A>
*/


#include <iostream>
#include <vector>
using namespace std;

void LCSLength(int m, int n, char* x, char* y, int** c, int** b) {
	for (int i = 1; i <= m; i++) c[i][0] = 0;
	for (int i = 1; i <= n; i++) c[0][i] = 0;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++) {
			if (x[i] == y[j]) {
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 1; // 左上
			}
			else if (c[i - 1][j] >= c[i][j - 1]) {
				c[i][j] = c[i - 1][j];
				b[i][j] = 2; // 上
			}
			else {
				c[i][j] = c[i][j - 1];
				b[i][j] = 3; // 左
			}
		}
}

void LCS(int** b, char* x, int i, int j, vector<char>& result) {
	if (i == 0 || j == 0) return;
	if (b[i][j] == 1) {
		LCS(b, x, i - 1, j - 1, result);
		result.push_back(x[i]);
	}
	else if (b[i][j] == 2) {
		LCS(b, x, i - 1, j, result);
	}
	else {
		LCS(b, x, i, j - 1, result);
	}
}

int main() {
	int m, n;
	while (cin >> m >> n) {
		string X_str, Y_str;
		cin >> X_str >> Y_str;

		char* x = new char[m + 1];
		char* y = new char[n + 1];
		for (int i = 0; i < m; ++i) x[i + 1] = X_str[i];
		for (int i = 0; i < n; ++i) y[i + 1] = Y_str[i];

		int** c = new int* [m + 1];
		int** b = new int* [m + 1];
		for (int i = 0; i <= m; ++i) {
			c[i] = new int[n + 1];
			b[i] = new int[n + 1];
		}

		LCSLength(m, n, x, y, c, b);

		cout << c[m][n] << endl;

		vector<char> lcs;
		LCS(b, x, m, n, lcs);

		cout << "<";
		for (int i = 0; i < lcs.size(); ++i) {
			if (i > 0) cout << ",";
			cout << lcs[i];
		}
		cout << ">" << endl;

		delete[] x;
		delete[] y;
		for (int i = 0; i <= m; ++i) {
			delete[] c[i];
			delete[] b[i];
		}
		delete[] c;
		delete[] b;

	}
	return 0;
}

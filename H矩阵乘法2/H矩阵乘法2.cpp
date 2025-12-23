/*
题目描述
以下是矩阵乘法的动态规划算法的迭代实现，设计一个实验实现它，要求算法的基本结构不变。
算法3.2 MatrixChain(P,n)
 1．令所有的m[i,i]初值为0，1≤i≤n
 2．for  r←2  to  n  do //r为计算的矩阵链长度
 3．   for  i ←1  to  n-r+1  do  //n-r+1为最后r链的始位置
 4．       j←i+r-1 //计算链i..j
 5．       m[i,j]←m[i+1,j]+Pi-1*Pi*Pj   //Ai(Ai+1..Aj )
 6.          s[i, j]←i //记录分割位置
 7.          for  k←i+1 to  j-1 do
 8.              t←m[i,k]+m[k+1,j]+Pi-1*Pk*Pj    //(Ai .. Ak)(Ak+1 .. Aj)
 9.              if  t<m[i,j]
 10.            then  m[i,j]←t
 11.                      s[i,j]←k
输入
矩阵数n
n个矩阵的行数、列数P
输出
n个矩阵相乘元素相乘的最少的总次数。
样例输入 Copy
3
10 100 5 50
样例输出 Copy
7500


*/


#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
	int n;

	while (cin >> n) {
		vector<int> P(n + 1);
		for (int i = 0; i <= n; ++i) {
			cin >> P[i];
		}

		vector<vector<long long>> m(n + 1, vector<long long>(n + 1, 0));
		vector<vector<int>> s(n + 1, vector<int>(n + 1, 0));
		for (int r = 2; r <= n; ++r) {
			for (int i = 1; i <= n - r + 1; ++i) {
				int j = i + r - 1;

				m[i][j] = m[i + 1][j] + (long long)P[i - 1] * P[i] * P[j];
				s[i][j] = i;

				for (int k = i + 1; k <= j - 1; ++k) {
					long long t = m[i][k] + m[k + 1][j] + (long long)P[i - 1] * P[k] * P[j];
					if (t < m[i][j]) {
						m[i][j] = t;

						s[i][j] = k;
					}
				}
			}
		}

		cout << m[1][n] << endl;

	}
	return 0;
}
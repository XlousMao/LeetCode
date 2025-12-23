/*
题目描述
以下是矩阵乘法的动态规划算法的递归实现，设计一个实验实现它，要求算法的基本结构不变。
算法  RecurMatrixChain(P,i,j)
  1.  m[i, j]←∞
  2.  s[i, j]←i
  3.  for  k←i  to  j-1  do
  4.      q←RecurMatrixChain(P,i,k)
				+RecurMatrixChain(P,k+1,j)+Pi-1*Pk*Pj
  5.      if  q<m[i,j]
  6.          then  m[i,j]←q
  7.                    s[i,j]←k
  8.  return  m[i,j]

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

vector<vector<long long>> m;
vector<vector<int>> s;
vector<int> P;

long long RecurMatrixChain(int i, int j) {
	if (m[i][j] != -1) {
		return m[i][j];
	}
	if (i == j) {
		m[i][j] = 0;
		s[i][j] = i;
		return 0;
	}

	m[i][j] = LLONG_MAX;
	s[i][j] = i;

	for (int k = i; k < j; ++k) {
		long long q = RecurMatrixChain(i, k)
			+ RecurMatrixChain(k + 1, j)
			+ (long long)P[i - 1] * P[k] * P[j];
		if (q < m[i][j]) {
			m[i][j] = q;
			s[i][j] = k;
		}
	}
	return m[i][j];
}

int main() {
	int n;

	while (cin >> n) {
		P.resize(n + 1);
		for (int i = 0; i <= n; ++i) {
			cin >> P[i];
		}

		m.assign(n + 1, vector<long long>(n + 1, -1));
		s.assign(n + 1, vector<int>(n + 1, 0));

		long long result = RecurMatrixChain(1, n);
		cout << result << endl;
	}

	return 0;
}
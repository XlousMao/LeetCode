/*
题目描述
计数算法C所执行的加法次数。
算法C
输入：n为正整数
输出：k
1.k←0
2.for i←1 to n do
3.  m←n/i
4.  for j←1 to m do
5.    k←k+1
6.return k
输入
n为正整数
输出
k
样例输入 Copy
5
样例输出 Copy
10

*/

#include <iostream>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		long long k = 0;
		for (int i = 1, j; i <= n; i = j + 1) {
			j = n / (n / i);
			k += 1LL * (n / i) * (j - i + 1);
		}
		cout << k << endl;
	}
	return 0;
}
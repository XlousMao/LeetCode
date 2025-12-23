/*
题目描述
阅读关于下述算法A的伪码，设计一个实验，实现该算法。
算法A
输入：数组P[0..n]，实数x
输出：y
1.y←P[0]；power←1
2.for i←1 to n do
3.    power←power*x
4.    y←y+P[i]*power
5.return y
输入
n
数组P[0..n]
实数x
输出
y
样例输入 Copy
2
1 2 3
4
样例输出 Copy
57

*/


#include <iostream>
#include <vector>

using namespace std;

double Compute_Polynomial(const vector<double>& P, double x) {
	double y = P[0];  // 初始化y为最高次项系数
	double power = 1; // 初始化幂次因子

	for (size_t i = 1; i < P.size(); ++i) {
		power *= x;          // 逐步计算x的幂次
		y += P[i] * power;   // 累加当前项的值
	}                                                     
	return y;    
}	

int main() {
	int n;
	while (cin >> n) {
		vector<double> P(n + 1); // P[0..n]共n+1个系数
		for (int i = 0; i <= n; ++i) {
			cin >> P[i];
		}
		double x;
		cin >> x;

		cout << Compute_Polynomial(P, x) << endl;
	}
	return 0;
}


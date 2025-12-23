/*
题目描述
输入两个正整数，求其最大公约数。
输入
测试数据有多组，每组输入两个正整数。
输出
对于每组输入,请输出其最大公约数。
样例输入 Copy
49 14
样例输出 Copy
7
*/
#include <iostream>
using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int main() {
	int a, b;
	while (cin >> a >> b) {
		if (a == 0 && b == 0) break;
		cout << gcd(a, b) << endl;
	}
	return 0;
}
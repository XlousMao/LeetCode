/*
题目描述
下述Find-Second-Min算法是找第二小算法。输入是n个不等的数构成的数组S，输出是第二小的数SecondMin。设计一个实验，实现下述Find-Second-Min算法。
算法Find-Second-Min(S，n)
1.if S[1]<S[2]
2.then min←S[1]；SecondMin←S[2]
3.else min←S[2]；SecondMin←S[1]
4.for i←3 to n do
5.    if S[i]<SecondMin
6.    then if S[i]<min
7.        then SecondMin←min；min←S[i]
8.        else SecondMin←S[i]
输入
n
n个不等的数构成的数组S
输出
第二小的数SecondMin
样例输入 Copy
7
1 2 3 4 5 6 7
样例输出 Copy
2

*/

#include <iostream>
#include <vector>

using namespace std;

int Find_Second_Min(const vector<int>& S) {
	int min, secondMin;
	if (S[0] < S[1]) {
		min = S[0];
		secondMin = S[1];
	}
	else {
		min = S[1];
		secondMin = S[0];
	}

	for (size_t i = 2; i < S.size(); ++i) {
		if (S[i] < secondMin) {
			if (S[i] < min) {
				secondMin = min;
				min = S[i];
			}
			else {
				secondMin = S[i];
			}
		}
	}
	return secondMin;
}

int main() {
	int n;
	while (cin >> n) {
		vector<int> S(n);
		for (int i = 0; i < n; ++i) {
			cin >> S[i];
		}
		cout << Find_Second_Min(S) << endl;
	}
	return 0;
}



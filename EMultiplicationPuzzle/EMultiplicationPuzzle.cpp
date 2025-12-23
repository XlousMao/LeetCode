/*
题目描述
The multiplication puzzle is played with a row of cards, each containing a single positive integer. During the move player takes one card out of the row and scores the number of points equal to the product of the number on the card taken and the numbers on the cards on the left and on the right of it. It is not allowed to take out the first and the last card in the row. After the final move, only two cards are left in the row.
The goal is to take cards in such order as to minimize the total number of scored points.
For example, if cards in the row contain numbers 10 1 50 20 5, player might take a card with 1, then 20 and 50, scoring
10*1*50 + 50*20*5 + 10*50*5 = 500+5000+2500 = 8000
If he would take the cards in the opposite order, i.e. 50, then 20, then 1, the score would be
1*50*20 + 1*20*5 + 10*1*5 = 1000+100+50 = 1150.
输入
The first line of the input contains the number of cards N (3 <= N <= 100). The second line contains N integers in the range from 1 to 100, separated by spaces.
输出
Output must contain a single integer - the minimal score.
样例输入 Copy
4
10 100 5 50
样例输出 Copy
7500
*/


#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		vector<vector<int>> dp(n, vector<int>(n, 0));

		for (int len = 2; len < n; ++len) { // len = j - i
			for (int i = 0; i + len < n; ++i) {
				int j = i + len;
				dp[i][j] = INT_MAX;
				for (int k = i + 1; k < j; ++k) {
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + a[i] * a[k] * a[j]);
				}
			}
		}

		cout << dp[0][n - 1] << endl;
	}
	return 0;
}
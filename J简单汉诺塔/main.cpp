/*
题目描述
古代有一个梵塔,塔内有3个座A、B、C,开始时A座上有n个盘子,盘子大小不等,大的在下,小的在上。有一个老和尚想把这n个盘子从A座移到C座,但规定每次只允许移动一个盘,且在移动过程中在3个座上都始终保持大盘在下,小盘在上。在移动过程中可以利用B座。假设1,2,…,n为盘子从小到大的序号,请输出把全部n个盘子从塔A搬到塔C的具体步骤。
输入
输入整数n(1≤n≤4）,这样的测试用例可能有多个。
输出
对每个n,输出把n个盘从塔A搬到塔C的全过程（全过程可能有多行,每行对应一个三元组i,X,Y,表示把第i个盘子从塔X搬到塔Y,这里1≤i≤n,X,Y取A,B,C其中一个),不同用例之间需要用空行隔开。
样例输入 Copy
3
样例输出 Copy
1,A,C
2,A,B
1,C,B
3,A,C
1,B,A
2,B,C
1,A,C

*/



#include <iostream>
#include <vector>
#include <string>
using namespace std;

void hanoi(int n, char from, char to, char aux, vector<string>& steps) {
	if (n == 1) {
		steps.push_back(to_string(n) + "," + from + "," + to);
		return;
	}
	hanoi(n - 1, from, aux, to, steps);
	steps.push_back(to_string(n) + "," + from + "," + to);
	hanoi(n - 1, aux, to, from, steps);
}

int main() {
	int n;
	while (cin >> n) {
		vector<string> steps;
		hanoi(n, 'A', 'C', 'B', steps);
		for (size_t i = 0; i < steps.size(); ++i) {
			cout << steps[i] << endl;
		}
	}
	return 0;
}
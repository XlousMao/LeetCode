/*
题目描述
有n(n≤100)个整数，已经按照从小到大顺序排列好，现在另外给一个整数x，请将该数插入到序列中，并使新的序列仍然有序。
输入
输入数据包含多个测试实例，每组数据由两行组成，第一行是n和x，第二行是已经有序的n个数的数列。n和x同时为0标示输入数据的结束，本行不做处理。
输出
对于每个测试实例，输出插入新的元素后的数列。
样例输入 Copy
3 3
1 2 4
0 0
样例输出 Copy
1,2,3,4

*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, x;
	while (cin >> n >> x) {
		if (n == 0 && x == 0) break;
		vector<int> arr(n);
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}

		int pos = 0;
		while (pos < n && arr[pos] < x) {
			++pos;
		}
		arr.insert(arr.begin() + pos, x);

		for (int i = 0; i < arr.size(); ++i) {
			if (i > 0) cout << ",";
			cout << arr[i];
		}
		cout << endl;
	}
	return 0;
}
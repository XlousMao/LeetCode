/*
题目描述
设A=<x1，x2，…，xn>是n个不等的整数构成的序列，A的一个单调递增子序列是序列<xi1，xi2，…，xik>，使得i1<i2<…<ik，且xi1<xi2<…<xik，子序列<xi1，xi2，…，xik>的长度是含有的整数个数k。例如A=<1，5，3，8，10，6，4，9>，它的长为4的递增子序列是<1，5，8，10>，<1，5，8，9>，…，设计一个算法求A的一个最长的单调递增子序列。
输入
n个不等的整数构成的序列。


输出
一个最长的单调递增子序列
样例输入 Copy
7
2 8 4 -4 5 9 11
样例输出 Copy
2,4,5,9,11
5

*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	while (cin >> n) {  // 多轮输入处理
		vector<int> nums(n);
		for (int i = 0; i < n; ++i) {
			cin >> nums[i];
		}

		if (n == 0) {  // 空序列处理
			cout << endl << 0 << endl;
			continue;
		}

		// tails[i]：长度为i+1的LIS的末尾元素最小值
		vector<int> tails;
		// prev[i]：记录nums[i]在LIS中的前驱元素索引
		vector<int> prev(n, -1);
		// len[i]：以nums[i]结尾的LIS长度
		vector<int> len(n, 0);

		for (int i = 0; i < n; ++i) {
			int x = nums[i];
			// 找到tails中第一个 >= x的位置（二分查找）
			auto it = lower_bound(tails.begin(), tails.end(), x);
			int idx = it - tails.begin();

			// 更新tails数组
			if (it == tails.end()) {
				tails.push_back(x);
			}
			else {
				*it = x;
			}

			// 记录当前元素的LIS长度
			len[i] = idx + 1;

			// 寻找前驱元素（长度为idx的LIS中最后一个小于x的元素）
			if (idx > 0) {
				for (int j = i - 1; j >= 0; --j) {
					if (len[j] == idx && nums[j] < x) {
						prev[i] = j;
						break;
					}
				}
			}
		}

		// 找到最长LIS的末尾索引
		int max_len = 0;
		int last_idx = 0;
		for (int i = 0; i < n; ++i) {
			if (len[i] > max_len) {
				max_len = len[i];
				last_idx = i;
			}
		}

		// 回溯重建最长LIS
		vector<int> lis;
		while (last_idx != -1) {
			lis.push_back(nums[last_idx]);
			last_idx = prev[last_idx];
		}
		reverse(lis.begin(), lis.end());  // 反转得到递增顺序

		// 输出结果
		for (int i = 0; i < lis.size(); ++i) {
			if (i > 0) cout << ",";
			cout << lis[i];
		}
		cout << endl;
		cout << max_len << endl;
	}
	return 0;
}
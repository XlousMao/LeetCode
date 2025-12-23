/*
题目描述
设有一条边远山区的道路AB，沿着道路AB分布着n所房子，这些房子到A的距离分别是d1，d2，…，dn(d1<d2<…<dn)。为了给所有房子的用户提供移动电话服务，需要在这条道路上设置一些基站。为了保证通信质量，每所房子应该位于距离某个基站的4km范围之内。设计一个算法找到基站的位置，并且使得基站总数达到最少。
输入
n
距离d1，d2，…，dn的数组d[1..n]
输出
基站位置
样例输入 Copy
6
1 3 4 8 12 15
样例输出 Copy
5,16

*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	// 录入风格：读取房子数量 n
	while (cin >> n) {
		vector<int> d(n);
		// 读取 n 个房子到 A 的距离
		for (int i = 0; i < n; ++i) {
			cin >> d[i];
		}

		// 确保距离是有序的（题目给出 d1 < d2 < ... < dn）
		sort(d.begin(), d.end());

		vector<int> stations;
		int i = 0;
		while (i < n) {
			// 找到当前第一个未覆盖的房子，基站放在其右侧 4km 处
			int station_pos = d[i] + 4;
			stations.push_back(station_pos);

			// 该基站覆盖半径为 4km，即覆盖 [station_pos - 4, station_pos + 4]
			// 也就是覆盖 [d[i], d[i] + 8] 范围内的所有房子
			int coverage_limit = station_pos + 4;

			// 跳过所有已被此基站覆盖的房子
			while (i < n && d[i] <= coverage_limit) {
				i++;
			}
		}

		// 输出基站位置，格式匹配样例：5,16
		for (int j = 0; j < stations.size(); ++j) {
			cout << stations[j] << (j == stations.size() - 1 ? "" : ",");
		}
		cout << endl;
	}
	return 0;
}
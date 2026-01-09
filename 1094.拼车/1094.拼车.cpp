/*
车上最初有 capacity 个空座位。车 只能 向一个方向行驶（也就是说，不允许掉头或改变方向）
给定整数 capacity 和一个数组 trips ,  trips[i] = [numPassengersi, fromi, toi] 表示第 i 次旅行有 numPassengersi 乘客，
接他们和放他们的位置分别是 fromi 和 toi 。这些位置是从汽车的初始位置向东的公里数。
当且仅当你可以在所有给定的行程中接送所有乘客时，返回 true，否则请返回 false。

示例 1：
输入：trips = [[2,1,5],[3,3,7]], capacity = 4
输出：false

示例 2：
输入：trips = [[2,1,5],[3,3,7]], capacity = 5
输出：true
*/

#include <iostream>
#include <vector>
#include <algorithm>
class Solution {
public:
	bool carPooling(std::vector<std::vector<int>>& trips, int capacity) {
		chaifen.resize(1001, 0);
		int now=0;
		for (int i=0;i<trips.size();++i)
		{
			chaifen[trips[i][1]] += trips[i][0];//上车
			chaifen[trips[i][2]] -= trips[i][0];//下车
		}
		for (int i = 0; i < chaifen.size(); ++i)
		{
			now += chaifen[i];
			if (now > capacity )
			{
				return false;
			}
		}
		return true;

	}
private:
	std::vector<int> chaifen;
};


int main()
{
	std::cout << "Hello World!\n";
}


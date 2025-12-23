/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

示例 1：
输入：n = 2
输出：2
解释：有两种方法可以爬到楼顶。
1. 1 阶 + 1 阶
2. 2 阶
示例 2：

输入：n = 3
输出：3
解释：有三种方法可以爬到楼顶。
1. 1 阶 + 1 阶 + 1 阶
2. 1 阶 + 2 阶
3. 2 阶 + 1 阶
*/

#include <iostream>
#include <vector>



class Solution {
public:
	int climbStairs(int n) {
		//爬第n阶，有两种可能，爬到n-1阶后再爬一阶，或者爬到n-2阶后再爬两阶
		//所以，f(n) = f(n-1) + f(n-2)
		std::vector<int>dp(n+1,0);
		if (n <= 2)
		{
			return n;
		}
		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 2;
		for (int i = 3; i <= n; ++i)
		{
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[n];
	}
};


int main()
{
	std::cout << "Hello, World!" << std::endl;
	return 0;
}
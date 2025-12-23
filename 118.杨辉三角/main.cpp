/*
给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
在「杨辉三角」中，每个数是它左上方和右上方的数的和。
示例 1:
输入: numRows = 5
输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
示例 2:
输入: numRows = 1
输出: [[1]]
*/



#include<iostream>
#include <vector>

class Solution {
public:
	std::vector<std::vector<int>> generate(int numRows) {
		if (numRows == 0)return {};
		std::vector<std::vector<int>>res;
		res.emplace_back(std::vector<int>{1});
		for (int i = 1; i < numRows; ++i)
		{
			std::vector<int>row(i + 1, 1);
			for (int j = 1; j < i; ++j)
			{
				row[j] = res[i - 1][j - 1] + res[i - 1][j];
			}
			res.emplace_back(row);
		}
		return res;
	}
};
int main()
{

}
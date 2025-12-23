/*
给你一个满足下述两条属性的 m x n 整数矩阵：
每行中的整数从左到右按非严格递增顺序排列。
每行的第一个整数大于前一行的最后一个整数。
给你一个整数 target ，如果 target 在矩阵中，返回 true ；否则，返回 false 。
示例 1：
输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
输出：true
示例 2：
输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
输出：false
*/


#include <iostream>
#include <vector>

class Solution {
public:
	bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
		//m*n
		int m = matrix.size();
		int n = matrix[0].size();
		int left = 0;
		int right = m;
		while (left < right)
		{
			int mid = (left + right - 1) / 2;
			if (matrix[mid][0] == target)
				return true;
			else if (matrix[mid][0] < target)
				left = mid + 1;
			else
				right = mid;
			
		}
		int row = left - 1;
		if (row >= 0) {
			for (int i = 0; i < n; ++i) {
				if (matrix[row][i] == target) {
					return true;
				}
			}
		}
		return false;
	}
};

int main()
{
	std::cout << "Hello, World!" << std::endl;
	return 0;
}


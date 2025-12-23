/*
给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
如果数组中不存在目标值 target，返回 [-1, -1]。
你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。
示例 1：
输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]
示例 2：
输入：nums = [5,7,7,8,8,10], target = 6
输出：[-1,-1]
示例 3：
输入：nums = [], target = 0
输出：[-1,-1]
*/


#include <iostream>
#include <vector>

class Solution {
public:
	std::vector<int> searchRange(std::vector<int>& nums, int target) {
		int left;
		int right;
		int n = nums.size();
		left = 0;
		right = n;
		std::vector<int> res = { -1,-1 };
		if (nums.size() == 0)
			return res;
// 		int leftborder = -1;
// 		int rightborder = -1;
		while (left < right)//左边界
		{
			int mid = left + (right - left) / 2;//防止溢出
			if (nums[mid] < target)
				left = mid + 1;
			else if (nums[mid] > target)
				right = mid;
			else
			{
				res[0] = mid;
				right = mid;
			}
		}
		left = 0;
		right = n;
		while (left < right)//右边界
		{
			int mid = left + (right - left) / 2;//防止溢出
			if (nums[mid] < target)
				left = mid + 1;
			else if (nums[mid] > target)
				right = mid;
			else
			{
				res[1] = mid;
				left = mid + 1;
			}
		}
		return res;
	}
};


int main()
{

}

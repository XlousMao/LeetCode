/*
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
请必须使用时间复杂度为 O(log n) 的算法。
示例 1:
输入: nums = [1,3,5,6], target = 5
输出: 2
示例 2:
输入: nums = [1,3,5,6], target = 2
输出: 1
示例 3:
输入: nums = [1,3,5,6], target = 7
输出: 4
*/

#include <iostream>
#include <vector>

class Solution {
public:
	int searchInsert(std::vector<int>& nums, int target) {
		int n = (int)nums.size();
		int left = 0;
		int right = n ;
		while (left < right)
		{
			int mid = (left + right-1) / 2;
			
			if (nums[mid] == target)
			{
				return mid;
			}
			else if (nums[mid]>target)
			{
				right = mid;
			}
			else
			{
				left = mid + 1;
			}
			
		}
		return left;
	}
};


int main()
{

}
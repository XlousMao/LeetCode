/*
给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。
示例 1:
输入: s = "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。注意 "bca" 和 "cab" 也是正确答案。
示例 2:
输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:
输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
	 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*/

#include <iostream>
#include <string.h>

class Solution {
public:
	int lengthOfLongestSubstring(std::string s) {
		int n = (int)s.length();
		if (n == 0)return 0;
		int last[128];
		memset(last, -1, sizeof(last));
		int maxLength = 0;
		int left = 0;
		int right = 0;
		for (; right < n; ++right)
		{
			int thechar = (int)s[right];
			if (last[thechar] != -1)
			{
				left = std::max(left, last[thechar] + 1);
				
			}
			last[thechar] = right;
			maxLength = std::max(maxLength,right - left + 1);
		}
		return maxLength;

	}
};


int main()
{
}



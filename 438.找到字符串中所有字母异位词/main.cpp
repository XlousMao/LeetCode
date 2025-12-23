/*
给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
示例 1:
输入: s = "cbaebabacd", p = "abc"
输出: [0,6]
解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
 示例 2:
输入: s = "abab", p = "ab"
输出: [0,1,2]
解释:
起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
*/

#include<iostream>
#include <string.h>
#include <vector>

class Solution {
public:
	std::vector<int> findAnagrams(std::string s, std::string p) {
		int n = (int)s.length();
		int m = (int)p.length();
		{
			if (m > n)return { };
		}
		std::vector<int>pnumber(26, 0);
		std::vector<int>nownumber(26, 0);
		
		for (auto c : p)
		{
			pnumber[c - 'a']++;
		}
		for (int i = 0; i < m; ++i)
		{
			nownumber[s[i] - 'a']++;
		}

		std::vector<int>res;
		if (pnumber == nownumber)
		{
			res.emplace_back(0);
		}

		for (int right = m; right < n; ++right)
		{
			int left = right - m;
			nownumber[s[left] - 'a']--;

			nownumber[s[right] - 'a']++;

			if (nownumber == pnumber)
			{
				res.emplace_back(left + 1);
			}
		}
		return res;
	}
};


int main()
{

}






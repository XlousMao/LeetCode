/*
给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
示例 1:
输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
解释：
在 strs 中没有字符串可以通过重新排列来形成 "bat"。
字符串 "nat" 和 "tan" 是字母异位词，因为它们可以重新排列以形成彼此。
字符串 "ate" ，"eat" 和 "tea" 是字母异位词，因为它们可以重新排列以形成彼此。
示例 2:
输入: strs = [""]
输出: [[""]]
示例 3:
输入: strs = ["a"]
输出: [["a"]]
提示：
1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] 仅包含小写字母
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
	std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
		std::vector<std::vector<std::string>> result;
		std::unordered_map<std::string, std::vector<std::string>>theMap;
		for (auto& s : strs)
		{
			int charCount[26] = { 0 };
			for (auto& c : s)//统计字母
			{
				charCount[c - 'a']++;
			}
			std::string key;
			for (int i = 0; i < 26; ++i)
			{
				//axbxcxdx
				key += (char)('a'+i);
				key += std::to_string(charCount[i]);
			}
			theMap[key].push_back(s);
		}
		for (auto& pair : theMap)
		{
			result.push_back(pair.second);
		}
		return result;
	}
};

int main()
{

}



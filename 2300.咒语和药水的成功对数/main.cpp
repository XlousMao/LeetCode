/*
给你两个正整数数组 spells 和 potions ，长度分别为 n 和 m ，其中 spells[i] 表示第 i 个咒语的能量强度，potions[j] 表示第 j 瓶药水的能量强度。
同时给你一个整数 success 。一个咒语和药水的能量强度 相乘 如果 大于等于 success ，那么它们视为一对 成功 的组合。
请你返回一个长度为 n 的整数数组 pairs，其中 pairs[i] 是能跟第 i 个咒语成功组合的 药水 数目。

示例 1：
输入：spells = [5,1,3], potions = [1,2,3,4,5], success = 7
输出：[4,0,3]
解释：
- 第 0 个咒语：5 * [1,2,3,4,5] = [5,10,15,20,25] 。总共 4 个成功组合。
- 第 1 个咒语：1 * [1,2,3,4,5] = [1,2,3,4,5] 。总共 0 个成功组合。
- 第 2 个咒语：3 * [1,2,3,4,5] = [3,6,9,12,15] 。总共 3 个成功组合。
所以返回 [4,0,3] 。

示例 2：
输入：spells = [3,1,2], potions = [8,5,8], success = 16
输出：[2,0,2]
解释：
- 第 0 个咒语：3 * [8,5,8] = [24,15,24] 。总共 2 个成功组合。
- 第 1 个咒语：1 * [8,5,8] = [8,5,8] 。总共 0 个成功组合。
- 第 2 个咒语：2 * [8,5,8] = [16,10,16] 。总共 2 个成功组合。
所以返回 [2,0,2] 。
*/
#include <iostream>
#include <vector>
#include <algorithm>


class Solution {
public:
	std::vector<int> successfulPairs(std::vector<int>& spells, std::vector<int>& potions, long long success) {
		sort(potions.begin(), potions.end());
		int spells_size = (int)spells.size();
		long long min_potion = -1;//wdf，用例给的数据太大，int溢出了
		//std::vector<int>min_potions;
		std::vector<int>res;
		for (int i = 0; i < spells_size; ++i)
		{
			if (success % spells.at(i) == 0)
			{
				min_potion = (long long)(success / spells.at(i));
			}
			else
			{
				min_potion = (long long)(success / spells.at(i)) + 1;
			}
			//min_potions.emplace_back(min_potion);
			auto it = std::lower_bound(potions.begin(), potions.end(), min_potion);
			if (it != potions.end())
			{
				res.emplace_back(potions.end() - it);
			}
			else
			{
				res.emplace_back(0);
			}
		}
		return res;
	}

	//尝试使用前缀和进行解决。。。。比直接二分还慢。。。
	std::vector<int> successfulPairs_2(std::vector<int>& spells, std::vector<int>& potions, long long success)
	{
		std::vector<int>count;
		count.resize((const unsigned __int64)1e5 + 2, 0);
		for (int i = 0; i < potions.size(); ++i)
		{  //[1 2 3 4 5]
		   //[0 1 1 1 1 1]
			count[potions[i]]++;
		}//on
		std::vector<int>qianzhuihe;
		qianzhuihe.resize((const unsigned __int64)(1e5 + 2), 0);
		for (long long i = (__int64)1e5; i >= 1; i--)
		{
			qianzhuihe[i] = qianzhuihe[i + 1] + count[i];
		}//on

		long long  min_potion = -1;
		std::vector<int >result;
		for (int i = 0; i < spells.size(); ++i)
		{
			if (success % spells[i] == 0)
			{
				min_potion = success / spells[i];
			}
			else
			{
				min_potion = success / spells[i] + 1;
			}
			if (min_potion > 1e5)
			{
				result.emplace_back(0);
				continue;
			}
			else
			{
				result.emplace_back(qianzhuihe[min_potion]);
			}
		}
		return result;
	}
	//ai优化过后直接干到4ms，击败99.89
	/*
	关键优化点解析
1. 动态确定max_p，减少无效循环
先遍历 potions 找max_p（O (m)），后续计数数组和后缀和循环仅需覆盖1~max_p范围；
例：若max_p=1e3，后缀和循环仅执行 1e3 次，而非原代码的 1e5 次，效率提升 100 倍。
2. 内存优化：合并计数与后缀和数组
原代码用了count和qianzhuihe两个数组，优化后直接在count数组上覆盖计算后缀和，减少一半内存开销（从 2*(1e5+2) 个 int 变为 (max_p+2) 个 int）。
3. 代码简洁化：向上取整公式
原代码用if (success%s==0)判断整除，优化后用(success + s - 1) / s实现整数除法的向上取整：
例：success=7，s=5 → (7+5-1)/5=11/5=2（正确，需≥2 的药水）；
例：success=10，s=5 → (10+5-1)/5=14/5=2（正确，需≥2 的药水）。
4. 性能优化：提前 reserve 结果数组
结果数组result的长度固定为spells.size()，提前reserve可避免 vector 动态扩容的开销（减少内存重新分配和数据拷贝）。
	*/
	std::vector<int> successfulPairs_2_ai(std::vector<int>& spells, std::vector<int>& potions, long long success) {
		// 步骤1：遍历potions，找实际最大值max_p（避免固定1e5的无效循环）
		int max_p = 0;
		for (int p : potions) {
			if (p > max_p) max_p = p;
		}

		// 步骤2：动态大小的计数数组（仅需max_p+2大小，节省内存）
		std::vector<int> count(max_p + 2, 0); // count[0] unused，count[max_p+1]用于后缀和边界
		for (int p : potions) {
			count[p]++;
		}

		// 步骤3：在count数组上直接计算后缀和（节省一个后缀和数组的内存）
		// suffix_sum[i] = 大于等于i的药水数量（即count[i] + count[i+1] + ... + count[max_p]）
		for (int i = max_p; i >= 1; --i) {
			count[i] += count[i + 1]; // 覆盖原count[i]，此时count[i]就是后缀和
		}

		// 步骤4：处理每个spell，计算结果（提前reserve避免扩容开销）
		std::vector<int> result;
		result.reserve(spells.size()); // 已知结果长度，提前分配内存
		for (int s : spells) {
			// 计算最小需要的药水强度：向上取整（success / s），用公式避免if-else
			long long min_potion = (success + s - 1) / s; // 等价于ceil(success / s)

			// 若最小需要的药水强度超过max_p，无匹配；否则取后缀和
			if (min_potion > max_p) {
				result.push_back(0);
			}
			else {
				result.push_back(count[min_potion]); // count[min_potion]即后缀和
			}
		}

		return result;
	}
};





int main() {
	//Solution s;
	return 0;
}
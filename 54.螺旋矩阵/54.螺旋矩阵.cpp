/*
给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
示例 1：
1->2->3
	  |
	  v
4->5  6
^	  |
|	  v
7<-8<-9
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]

示例 2：
1->2->3->  4
		   |
		   v
5->6->7	   8
^		   |
|		   v
9<-10<-11<-12



输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]


提示：

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
*/

#include <iostream>
#include <vector>



class Solution {
public:
	std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
		int n = matrix.size();//行数
		int m = matrix[0].size();//列数

		int  top = 0
			, bottom = n - 1
			, left = 0
			, right = m - 1;

		std::vector<int>res;
		while (top <= bottom && left <= right) {
			//上行
			for (int i = left; i <= right; ++i) {
				res.push_back(matrix[top][i]);
			}
			++top;
			//右列
			for (int i = top; i <= bottom; ++i) {
				res.push_back(matrix[i][right]);
			}
			--right;
			if (top <= bottom) {
				//下行
				for (int i = right; i >= left; --i) {
					res.push_back(matrix[bottom][i]);
				}
				--bottom;
			}
			if (left <= right) {
				//左列
				for (int i = bottom; i >= top; --i) {
					res.push_back(matrix[i][left]);
				}
				++left;
			}
		}
		return res;
	}
};

int main()
{
	return 0;
}
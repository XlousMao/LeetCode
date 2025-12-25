/*
给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。

你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。



示例 1：
123      741
456  ->  852
789      963
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[[7,4,1],[8,5,2],[9,6,3]]

示例 2：
5  1  9  11      15 13 2  5
2  4  8  10  ->  14 3  4  1
13 3  6  7       12 6  8  9
15 14 12 16      16 7  10 11
输入：matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
输出：[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

*/

#include <iostream>
#include <vector>


class Solution {
public:
	void rotate(std::vector<std::vector<int>>& matrix) {
		int n = matrix.size();//行数
		int m = matrix[0].size();//列数

		int  top = 0
			, bottom = n - 1
			, left = 0
			, right = m - 1;

		while (top<=bottom&&left<=right)
		{
			for (int i = 0; i < bottom - top; ++i)//i可以理解为偏移量，而不是绝对位置
			{
				//每次循环处理四个元素
				int temp = matrix[top][left+i];
				matrix[top][left+i] = matrix[bottom-i][left];
				matrix[bottom-i][left] = matrix[bottom][right-i];
				matrix[bottom][right-i] = matrix[top+i][right];
				matrix[top+i][right] = temp;
			}
			++top;
			--bottom;
			++left;
			--right;

		}
	}
};

int main()
{
	return 0;
}
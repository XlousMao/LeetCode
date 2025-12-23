/*
题目描述
利用如下二分归并排序算法将读入的n个数从小到大排序后输出。
算法1.5  MergeSort(A，p，r) //归并排序数组A[p..r]，1≤p≤r≤n
1. if p<r
2.  then q←⌊(p+r)/2⌋
3.         MergeSort(A，p，q)
4.         MergeSort(A，q+1，r)
5.         Merge(A，p，q，r)

算法1.6  Merge(A，p，q，r) //将排序数组A[p..q]与A[q+1，r]合并
1.  x←q-p+1，y←r-q //x，y分别为两个子数组的元素数
2. 将A[p..q]复制到B[1..x]，将A[q+1..r]复制到C[1..y]
3.  i←1，j←1，k←p
4.  while i≤x and j≤y do
5.      if B[i]≤C[j]//B的首元素不大于C的首元素
6.      then  A[k]←B[i]//将B的首元素放到A中
7.               i←i+1
8.      else
9.              A[k]←C[j]
10.            j←j+1
11.     k←k+1
12. if i>x then 将C[j..y]复制到A[k..r] //B已经是空数组
13. else 将B[i..x]复制到A[k..r] //C已经是空数组
输入
输入的第一行包含1个正整数n，表示共有n个整数需要参与排序。其中n不超过100000。
第二行包含n个用空格隔开的正整数，表示n个需要排序的整数。

输出
只有1行，包含n个整数，表示从小到大排序完毕的所有整数。
请在每个整数后输出一个英文逗号，并请注意行尾输出换行。
样例输入 Copy
10
2 8 4 6 1 10 7 3 5 9
样例输出 Copy
1,2,3,4,5,6,7,8,9,10



*/

#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int>& A, int p, int q, int r) {
	int x = q - p + 1;
	int y = r - q;
	vector<int> B(x), C(y);

	// 修正索引计算
	for (int i = 0; i < x; ++i) B[i] = A[p + i];
	for (int j = 0; j < y; ++j) C[j] = A[q + 1 + j];  // 关键修正

	int i = 0, j = 0, k = p;
	while (i < x && j < y) {
		if (B[i] <= C[j]) {
			A[k++] = B[i++];
		}
		else {
			A[k++] = C[j++];
		}
	}
	while (i < x) A[k++] = B[i++];
	while (j < y) A[k++] = C[j++];
}

void MergeSort(vector<int>& A, int p, int r) {
	if (p < r) {
		int q = p + (r - p) / 2;  // 修正中间点计算
		MergeSort(A, p, q);
		MergeSort(A, q + 1, r);
		Merge(A, p, q, r);
	}
}

int main() {
	int n;
	while (cin >> n) {
		vector<int> A(n);
		for (int i = 0; i < n; ++i) {
			cin >> A[i];
		}
		MergeSort(A, 0, n - 1);
		for (int i = 0; i < n; ++i) {
			if (i) cout << ",";
			cout << A[i];
		}
		cout << endl;
	}
	return 0;
}
/*
题目描述
以下算法是用分治法求最大元、最小元。设计一个实验实现它（按照C++语法、书写规范和功能修改完善它），要求保持基本结构不变。
template <class Type>
void SortableList<Type>::MaxMin(int i ,int j ,Type& max,Type& min)const
{
Type min1,max1;
if(i==j)  max=min=l[i];
else if(i==j-1)
  if(l[i]<l[j]){
	max=l[i];min=l[j];
}
else {
	 max=l[i];min=l[j];
}
else{
  int m=(i+j)/2;
  MaxMin(i,m,max,min);
  MaxMin(m+1,j,max1,min1);
  if(max<max1)  max=max1;
  if(min>min1)   min=min1;
}
}
输入
元素个数n
n个元l
输出
最大元
最小元
样例输入 Copy
7
1 2 3 4 5 6 7
样例输出 Copy
7
1

*/


#include <iostream>
#include <vector>
using namespace std;

template <class Type>
class SortableList {
private:
	vector<Type> l;

public:
	SortableList(int n) {
		l.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> l[i];
		}
	}

	void MaxMin(int i, int j, Type& max, Type& min) const {
		Type min1, max1;

		if (i == j) {
			max = min = l[i];
			return;
		}
		else if (i == j - 1) {
			if (l[i] < l[j]) {
				max = l[j];
				min = l[i];
			}
			else {
				max = l[i];
				min = l[j];
			}
			return;
		}
		else {
			int m = (i + j) / 2;
			MaxMin(i, m, max, min);
			MaxMin(m + 1, j, max1, min1);

			if (max < max1) max = max1;
			if (min > min1) min = min1;
		}
	}

	void FindMaxMin(Type& max, Type& min) {
		if (l.empty()) {
			cerr << "错误：列表为空！" << endl;
			return;
		}
		MaxMin(0, l.size() - 1, max, min);
	}

	int size() const { return l.size(); }
};

int main() {
	int n;
	while (cin >> n) {
		if (n <= 0) {
			cout << "错误：元素个数必须大于0！" << endl;
			return 1;
		}

		SortableList<int> list(n);

		int max, min;
		list.FindMaxMin(max, min);

		cout << max << endl;
		cout << min << endl;

	}
	return 0;
}
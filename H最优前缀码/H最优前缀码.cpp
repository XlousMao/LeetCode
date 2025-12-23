/*
题目描述
给定字符集C={x1,x2,… ,xn}和每个字符的频率f(xi),i=1,2,…,n,求关于C的一个最优前缀码。
输入
a:45,
b:13,
c:12,
d:16,
e:9,
f:5

输出
f--0000,
e--0001,
d--001,
c--010,
b--011,
a--1

样例输入 Copy
6
a 45
b 13
c 12
d 16
e 9
f 5
样例输出 Copy
a--0
c--100
b--101
f--1100
e--1101
d--111

*/



#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
	char ch;
	int freq;
	Node* left;
	Node* right;

	Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
	Node(int f) : ch(0), freq(f), left(nullptr), right(nullptr) {}
};

struct Compare {
	bool operator()(Node* a, Node* b) {
		return a->freq > b->freq;
	}
};

void generateCodes(Node* root, string code, unordered_map<char, string>& huffmanCode) {
	if (!root) return;
	if (root->ch != 0) {
		huffmanCode[root->ch] = code.empty() ? "0" : code;
		return;
	}
	generateCodes(root->left, code + "0", huffmanCode);
	generateCodes(root->right, code + "1", huffmanCode);
}

void deleteTree(Node* root) {
	if (!root) return;
	deleteTree(root->left);
	deleteTree(root->right);
	delete root;
}

int main() {
	int n;
	cin >> n;

	priority_queue<Node*, vector<Node*>, Compare> pq;

	for (int i = 0; i < n; ++i) {
		char ch;
		int freq;
		cin >> ch >> freq;
		pq.push(new Node(ch, freq));
	}

	while (pq.size() > 1) {
		Node* left = pq.top(); pq.pop();
		Node* right = pq.top(); pq.pop();

		Node* merged = new Node(left->freq + right->freq);
		merged->left = left;
		merged->right = right;

		pq.push(merged);
	}

	Node* root = pq.top();
	unordered_map<char, string> huffmanCode;
	generateCodes(root, "", huffmanCode);

	// 收集所有 (char, code) 对
	vector<pair<char, string>> codes;
	for (auto& kv : huffmanCode) {
		codes.push_back({ kv.first, kv.second });
	}

	// 按编码的字典序排序
	sort(codes.begin(), codes.end(), [](const pair<char, string>& a, const pair<char, string>& b) {
		return a.second < b.second;
		});

	for (auto& p : codes) {
		cout << p.first << "--" << p.second << endl;
	}

	deleteTree(root);
	return 0;
}
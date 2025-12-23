/*
题目描述
虽然草儿是个路痴（就是在杭电待了一年多，居然还会在校园里迷路的人，汗~),但是草儿仍然很喜欢旅行，因为在旅途中 会遇见很多人（白马王子，^0^），很多事，还能丰富自己的阅历，还可以看美丽的风景……草儿想去很多地方，她想要去东京铁塔看夜景，去威尼斯看电影，去阳明山上看海芋，去纽约纯粹看雪景，去巴黎喝咖啡写信，去北京探望孟姜女……眼看寒假就快到了，这么一大段时间，可不能浪费啊，一定要给自己好好的放个假，可是也不能荒废了训练啊，所以草儿决定在要在最短的时间去一个自己想去的地方！因为草儿的家在一个小镇上，没有火车经过，所以她只能去邻近的城市坐火车（好可怜啊~）。
输入
输入数据有多组，每组的第一行是三个整数T，S和D，表示有T条路，和草儿家相邻的城市的有S个，草儿想去的地方有D个；
接着有T行，每行有三个整数a，b，time,表示a,b城市之间的车程是time小时；(1=<(a,b)<=1000;a,b 之间可能有多条路)
接着的第T+1行有S个数，表示和草儿家相连的城市；
接着的第T+2行有D个数，表示草儿想去地方。
输出
输出草儿能去某个喜欢的城市的最短时间。
样例输入 Copy
6 2 3
1 3 5
1 4 7
2 8 12
3 8 4
4 9 12
9 10 2
1 2
8 9 10
样例输出 Copy
9

*/


#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <cctype>
using namespace std;

const int MAXN = 1005;
const int INF = INT_MAX;

struct Edge {
	int to, time;
	Edge(int t, int tm) : to(t), time(tm) {}
	bool operator<(const Edge& other) const {
		return time > other.time;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, S, D;
	while (cin >> T >> S >> D) {
		vector<vector<Edge>> graph(MAXN);

		for (int i = 0; i < T; ++i) {
			int a, b, time;
			cin >> a >> b >> time;
			graph[a].push_back(Edge(b, time));
			graph[b].push_back(Edge(a, time));
		}

		vector<int> starts(S);
		for (int i = 0; i < S; ++i) {
			cin >> starts[i];
		}

		vector<int> destinations(D);
		for (int i = 0; i < D; ++i) {
			cin >> destinations[i];
		}

		for (int city : starts) {
			graph[0].push_back(Edge(city, 0));
		}

		vector<int> dist(MAXN, INF);
		priority_queue<Edge> pq;
		dist[0] = 0;
		pq.push(Edge(0, 0));

		while (!pq.empty()) {
			Edge cur = pq.top();
			pq.pop();
			int u = cur.to;
			int d = cur.time;

			if (d != dist[u]) continue;

			for (const Edge& e : graph[u]) {
				int v = e.to;
				int w = e.time;
				if (dist[u] + w < dist[v]) {
					dist[v] = dist[u] + w;
					pq.push(Edge(v, dist[v]));
				}
			}
		}

		int ans = INF;
		for (int city : destinations) {
			if (dist[city] < ans) {
				ans = dist[city];
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
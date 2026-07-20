#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 333;
const int inf = 1e9;
const ll infll = 1e18;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
vector<vector<int>> graph;
vector<bool>visited;  
int n,m;
int startNode;
void dfs(int x) {
	visited[x] = true;
	cout << x << " ";
	for (int cai : graph[x]) {
		if (!visited[cai]) {
			dfs(cai);
		}
	}
}

void bfs(int x) {
	queue<int> que;
	que.push(x);
	visited[x] = true;
	while (!que.empty()) {
		int cur = que.front();
		que.pop();
		cout << cur << " ";
		for (int cai : graph[cur]) {
			if (!visited[cai]) {
				visited[cai] = true;
				que.push(cai);
			}
		}
	}
}

int main() {
	//普通图的邻接表和bfs，dfs遍历
	/*给定一个包含 n 个顶点、m 条边的无向图，顶点编号为 1∼n。
	请从顶点 s 出发
	输出深度优先搜索 DFS 的访问顺序
	输出广度优先搜索 BFS 的访问顺序
	当一个顶点有多个尚未访问的相邻顶点时，优先访问编号较小的顶点。*/
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	cin >> startNode;
	graph.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	visited.assign(n + 1, false);//n个elem方法赋值
	dfs(startNode);
	visited.assign(n + 1, false);//n个elem方法赋值
	bfs(startNode);

	return 0;
}
//-------------------------------
//#include <bits/stdc++.h>
using namespace std;
int n, a, b;
int result;
vector<int> grid;
vector<bool> visited;
vector<int> dist;
int sb_bfs(int x) {
	int step = 0;
	queue<int> que;
	que.push(x);
	dist[x] = 0;
	visited[x] = true;
	while (!que.empty()) {
		int cur = que.front();
		que.pop();
		if (cur == b)return dist[cur];
		for (int sign = -1; sign <= 1; sign+=2) {
			int nx = cur + sign * grid[cur];
			if (nx >=1 && nx <= n && dist[nx] == -1)
			{
				dist[nx] = dist[cur] + 1;
				visited[nx] = true;
				que.push(nx);
			}
		}
	}
	return -1;
}

int main() {
	cin >> n >> a >> b;
	grid.resize(n + 1);
	dist.assign(n + 1, -1);
	visited.assign(n + 1, false);
	for (int i = 1; i <= n; i++) {
		cin >> grid[i];
	}
	cout << sb_bfs(a);
	return 0;
}

//p2895-------------------------
int m;
vector<vector<int>> grid;
vector<int> 
int xun_bfs() {
	queue<int> que;
	que.push({ 0,0 });
	return -1;
}
int main() {
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x, y, m;
		cin >> x >> y >> m;

	}
	cout << xun_bfs() < '\n';
	return 0;
}
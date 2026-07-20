#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 333;
const int inf = 1e9;
const ll infll = 1e18;
//锐意当鸣 - 2026 SFA - Day2

/*复习内容：
DFS的核心过程：
1 进入当前状态；
2 判断是否越界或已访问；
3 标记当前状态；
4 枚举下一状态；
5 递归进入下一状态；
6 回溯题中恢复状态。
ans6-哪些场景需要恢复现场
不需要恢复--求连通块数量（岛屿问题）
需要恢复--路径问题，N皇后，排列
先手动模拟一个3×3网格，画出递归访问顺序。*/

/*验收标准
不看模板写出四方向数组；
知道越界判断写在哪里；
知道什么时候标记visited；
能解释哪些题需要恢复现场，哪些不需要。*/

//void muban_dfs() {
//	if (终止条件) {
//		res;
//		return;
//	}
//	for (本节点连接的其他节点) {
//		处理节点
//			dfs();
//		回溯
//	}
//}

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };//四方向数组
vector<vector<int>> result;
vector<int> path;
//网格dfs模板

int n, m;
int g[100][100];
bool visited[100][100];
void net_dfs(int x, int y) {
	//1 limited
	if (x < 0 || y < 0 || x >= n || y >= m) {
		return;
	}
	//2 if is visited
	if (visited[x][y]) {
		return;
	}
	//3 remark一定要进入后马上标记 
	visited[x][y] = true;
	//process on now circumstance
	cout << x << " " << y << '\n';
	//4 directions
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		//5 next circumstance
		net_dfs(nx, ny);
	}
	//6 turning back
	//visited[x][y] = false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	return 0;
}

//---------------------------------
int n, m;
bool visited[100][100];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
char g[100][100];

void dfs(int x,int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) {
		return;
	}
	if (visited[x][y]) {
		return;
	}
	if (g[x][y] == '0') {
		return;
	}
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		dfs(nx, ny);
	}
	//visited[x][y] = false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> g[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (g[i][j] != '0' && !visited[i][j]) {
				ans++;
				dfs(i, j);
			}
		}
	}
	cout << ans;
	return 0;
}
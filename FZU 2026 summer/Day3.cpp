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

void bfs(vector<vector<int>>&grid,vector<vector<bool>>&visited,int x,int y) {
	queue<pii> que;
	que.push({ x,y });
	visited[x][y] = true;
	while (!que.empty()) {
		pii cur = que.front();
		que.pop();
		int curx = cur.first;
		int cury = cur.second;
		for (int i = 0; i < 4; i++) {
			int nextx = curx + dx[i];
			int nexty = cury + dy[i];
			if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) {
				continue;
			}
			if (!visited[nextx][nexty] && grid[nextx][nexty] == 1) {
				visited[nextx][nexty] = true;
				que.push({ nextx,nexty });
			}
		}
	}
}

int main() {
	//岛屿计数--广度优先搜索
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && grid[i][j] == 1) {
				result++;
				bfs(grid,visited,i, j);
			}
		}
	}
	cout << result << '\n';
	return 0;
}

//#include <bits/stdc++.h>
//最大岛屿面积
using namespace std;
typedef pair<int, int> pii;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int cnt;

void bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
    queue<pii> que;
    que.push({ x,y });
    visited[x][y] = true;
    cnt++;
    while (!que.empty()) {
        pii cur = que.front();
        que.pop();
        int curx = cur.first;
        int cury = cur.second;
        for (int i = 0; i < 4; i++) {
            int nextx = curx + dx[i];
            int nexty = cury + dy[i];
            if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) {
                continue;
            }
            if (!visited[nextx][nexty]
                && grid[nextx][nexty] == 1) {
                cnt++;
                visited[nextx][nexty] = true;
                que.push({ nextx,nexty });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && grid[i][j] == 1) {
                cnt = 0;
                bfs(grid, visited, i, j);
                result = max(cnt, result);
            }
        }
    }
    cout << result;
    return 0;
}

//解答最短路问题
//only BFS can do
//马走日
//#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int dx[8] = {
    -2,-2,-1,-1,
     1, 1,2, 2
};

int dy[8] = {
    -1, 1,-2, 2,
    -2, 2,-1, 1
};

int n, m;
void bfs(vector<vector<int>> &dist,int x, int y) {
    queue<pii> que;
    que.push({ x,y });
    dist[x][y] = 0;
    while (!que.empty()) {
        pii cur = que.front();
        que.pop();
        int curx = cur.first;
        int cury = cur.second;
        for (int i = 0; i < 8; i++) {
            int nextx = curx + dx[i];
            int nexty = cury + dy[i];
            if (nextx < 1 || nexty < 1 || nextx > n || nexty > m) {
                continue;
            }
            if (dist[nextx][nexty] != -1) {
                continue;
            }
            dist[nextx][nexty] = dist[curx][cury] + 1;
            que.push({ nextx,nexty });
        }
    }
}

int main() {
    int x, y;
    cin >> n >> m >> x >> y;
    vector<vector<int>> dist(n+1, vector<int>(m+1, -1));
    //-1代表没来过，0代表起点，数字代表距离
    bfs(dist, x, y);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << dist[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}

//luoguP1746--伟航计划例题
#include <queue>
#include <numeric>
#include <iomanip>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n;
int x1, y1, x2, y2;
char grid[1005][1005];
int dist[1005][1005] ;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool found = false;
int bfs() {
	queue<pii> q;
	q.push({ x1,y1 });
    dist[x1][y1] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n)continue;
			if (grid[nx][ny] == '1')continue;
            if (dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({ nx,ny });
            }
		}
	}
    return dist[x2][y2];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
    memset(dist, -1, sizeof(dist));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}
	cin >> x1 >> y1 >> x2 >> y2;
	x1--;
	x2--;
	y1--;
	y2--;
	cout << bfs() << '\n';
	return 0;
}
//-------------------------------------------
//1238
//#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };
vector<pii>path;
bool found = false;
int m, n;
int grid[15][15];
bool visited[15][15];
int x1, y1, x2, y2;
void dfs(int x,int y) {
    visited[x][y] = true;
    path.push_back({ x,y });
    if (x == x2 && y == y2) {
        found = true;
        for (int i = 0; i < path.size(); i++) {
            cout << '(' << path[i].first +1 << ',' << path[i].second+1 << ')';
            if (i+1 < path.size()) {
                cout << "->";
            }
        }
        cout << '\n';
    }

    else {
        for (int i = 0; i < 4; i++) {
            int curx = x + dx[i];
            int cury = y + dy[i];
            if (curx < 0 || cury < 0 || curx >= m || cury >= n) {
                continue;
            }
            if (grid[curx][cury] == 0) {
                continue;
            }
            if (!visited[curx][cury] && grid[curx][cury] == 1) {
                visited[curx][cury] = true;
                dfs(curx, cury);
            }
        }
    }
    path.pop_back();
    visited[x][y] = false;
}

int main() {
    cin >> m >> n;
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    cin >> x1 >> y1 >> x2 >> y2;
    x1--; y1--; x2--; y2--;
    dfs(x1, y1);
    if (!found) {
        cout << -1;
    }
    return 0;
}
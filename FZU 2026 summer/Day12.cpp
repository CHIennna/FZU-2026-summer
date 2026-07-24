//1238
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int m, n;
int startx, starty;
int endx, endy;
bool found = false;
int grid[16][16];
bool visited[16][16];
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
vector<pii> path;
void dfs(int x, int y) {
	path.push_back({ x,y });
	visited[x][y] = true;
	if (x == endx && y == endy) {
		found = true;
		for (int i = 0; i < path.size(); i++) {
			cout << "(" << path[i].first + 1 << "," << path[i].second + 1 << ")";
			if (i < path.size() - 1) {
				cout << "->";
			}
		}
		cout << '\n';
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
			continue;
		}
		if (!visited[nx][ny] && grid[nx][ny] == 1) {
			visited[nx][ny] = true;
			dfs(nx, ny);
		}
	}
	path.pop_back();
	visited[x][y] = false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> m >> n;
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}
	cin >> startx >> starty >> endx >> endy;
	startx--; starty--; endx--; endy--;
	dfs(startx, starty);
	if (!found) {
		cout << -1;
	}
	return 0;
}

//1177
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n;
vector<int> a;
void quicksort(vector<int>& a, int left, int right) {
	int i = left;
	int j = right;
	int mid = a[(left + right) / 2];
	while (i <= j) {
		while (a[i] < mid)i++;
		while (a[j] > mid)j--;
		if (i <= j) {
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (i < right) {
		quicksort(a, i, right);
	}
	if (j > left) {
		quicksort(a, left, j);
	}
}

int main() {
	cin >> n;
	a.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	quicksort(a, 1, n);
	for (int i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}
	cout << '\n';
	return 0;
}

#include <iostream>
using namespace std;

int cnt[1001];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cnt[x]++;
	}

	int total = 0;

	for (int i = 1; i <= 1000; i++) {
		if (cnt[i] > 0) {
			total++;
		}
	}

	cout << total << '\n';

	for (int i = 1; i <= 1000; i++) {
		if (cnt[i] > 0) {
			cout << i << ' ';
		}
	}

	return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;
/ ① 059
int a[1010];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int cnt = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] != a[i - 1]) {
			cnt++;
		}
	}
	cout << cnt << '\n';

	cout << a[0] << ' ';

	for (int i = 1; i < n; i++) {
		if (a[i] != a[i - 1]) {
			cout << a[i] << ' ';
		}
	}
	return 0;
}

#include <iostream>
using namespace std;
int n, a, b, p[205], q[205], x, y;
int k[5][5] = { {0, 0, 1, 1, 0},
				{1, 0, 0, 1, 0},
				{0, 1, 0, 0, 1},
				{0, 0, 1, 0, 1},
				{1, 1, 0, 0, 0} };
int main() {
	cin >> n >> a >> b;
	for (int i = 0; i < a; i++)
		cin >> p[i];
	for (int i = 0; i < b; i++)
		cin >> q[i];
	for (int i = 0; i < n; i++) {
		x += k[p[i % a]][q[i % b]];
		y += k[q[i % b]][p[i % a]];
	}
	cout << x << ' ' << y;
	return 0;
}

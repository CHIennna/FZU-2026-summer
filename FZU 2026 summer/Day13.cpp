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

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n, m;
	cin >> n >> m;
	ll squ = 0;
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == j)squ += 1ll * (n - i + 1) * (m - j + 1);
		}
	}
	ll sb = 1ll * n * (n + 1) * m * (m + 1) / 4;
	cout << squ << " " << sb - squ << endl;
}

//2089
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n;
vector<int>path;
vector<vector<int>> ans;
void dfs(int pos, int sum) {
	if (pos == 10) {
		if (sum == n) {
			ans.push_back(path);
		}
		return;
	}

	for (int i = 1; i <= 3; i++) {
		path.push_back(i);
		dfs(pos + 1, sum + i);
		path.pop_back();
	}
}

int main() {
	cin >> n;
	if (n < 10 || n > 30) {
		cout << 0 << endl;
		return 0;
	}
	dfs(0, 0);
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		for (int x : ans[i]) {
			cout << x << ' ';
		}
		cout << '\n';
	}
	return 0;
}

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
		path.pop_back();
		visited[x][y] = false;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
			continue;
		}
		if (!visited[nx][ny] && grid[nx][ny] == 1) {
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

//1618
int b[10];
void go(int x) {
	while (x > 0) {
		int digit = x % 10;
		x /= 10;
		b[digit]++;
	}
}
bool check(int x, int y, int z) {
	memset(b, 0, sizeof(b));
	if (x < 100 || x > 999 ||
		y < 100 || y > 999 ||
		z < 100 || z > 999) {
		return false;//tip
	}//就得是三数，排除别的方式 
	go(x);
	go(y);
	go(z);
	if (b[0]) return false;
	for (int i = 1; i <= 9; i++) {

		if (b[i] != 1) {//tip
			return false;
		}
	}
	return true;
}
bool found = false;
//RE?
int main() {
	int A, B, C, x, y, z;
	cin >> A >> B >> C;
	if (A == 0) {
		cout << "No!!!\n";
		return 0;
	}//tip:RE?
	for (int x = 123; x <= 987; x++) {
		if (x * B % A != 0 || x * C % A != 0)continue;//tip
		y = x * B / A;
		z = x * C / A;
		if (check(x, y, z)) {
			found = true;
			cout << x << " " << y << " " << z << '\n';
		}
	}
	if (!found) {
		cout << "No!!!\n";
		return 0;
	}
}

//2241
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int n, m;
	cin >> n >> m;
	ll squ = 0;
	ll sum = 1ll * n * (n + 1) * m * (m + 1) / 4;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == j)squ += 1ll * (n - i + 1) * (m - j + 1);
		}
	}
	cout << squ << " " << sum - squ << '\n';
	return 0;
}

//2089
int n;
int ans;
vector<int> path;
vector<vector<int>> gaga;
void dfs(int selected_cnt, int sum) {
	if (selected_cnt == 10) {
		if (sum == n) {
			ans++;
			gaga.push_back(path);
		}
		return;
	}
	for (int x = 1; x <= 3; x++) {
		path.push_back(x);
		dfs(selected_cnt + 1, sum + x);
		path.pop_back();
	}
}

int main() {
	cin >> n;
	if (n < 10 || n>30) {
		cout << 0;
		return 0;
	}
	dfs(0, 0);
	cout << ans << '\n';
	for (int i = 0; i < gaga.size(); i++) {
		for (int j = 0; j < gaga[i].size(); j++) {
			cout << gaga[i][j] << " ";
		}
		cout << '\n';
	}
}

int b[10];
void go(int x) {
	b[x / 100]++;
	b[x % 10]++;
	b[(x / 10) % 10]++;
}
bool check(int x, int y, int z) {
	memset(b, 0, sizeof(b));
	go(x);
	go(y);
	go(z);
	if (b[0])return false;
	for (int i = 1; i <= 9; i++) {
		if (b[i] != 1) {
			return false;
		}
	}
	return true;
}
int main() {
	int A, B, C, x, y, z;
	cin >> A >> B >> C;
	if (A == 0) {
		cout << "No!!!";
		return 0;
	}
	bool found = false;
	for (int x = 123; x <= 987; x++) {
		if (x * B % A || x * C % A)continue;
		y = x * B / A;
		z = x * C / A;
		if (check(x, y, z)) {
			cout << x << " " << y << " " << z << '\n';
			found = true;
		}
	}
	if (!found) {
		cout << "No!!!";
	}
}

//1255
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 5010;

int f[maxn][maxn];
//对于每个f[i]对应的答案拆分到第二位按位存储 
int main() {
	int n;
	cin >> n;
	f[1][1] = 1;
	f[2][1] = 2;
	for (int i = 3; i <= n; i++) {
		for (int j = 1; j <= maxn; j++) {
			f[i][j] = f[i - 1][j] + f[i - 2][j];
		}
		for (int j = 1; j < maxn; j++) {
			f[i][j + 1] += f[i][j] / 10;
			f[i][j] %= 10;
		}
	}

	int len = maxn;
	while (len > 1 && f[n][len] == 0)len--;
	for (int i = len; i >= 1; i--)cout << f[n][i];
	return 0;
}

//1002
//错两个测试点 缺乏ll 
int ctrl[25][25];
ll f[25][25];
int n, m;
int hx, hy;
int dx[10] = { 0,1,1,-1,-1,2,2,-2,-2 };
int dy[10] = { 0,2,-2,2,-2,1,-1,1,-1 };
int main() {
	cin >> n >> m;
	cin >> hx >> hy;
	for (int i = 0; i < 9; i++) {
		int nx = hx + dx[i];
		int ny = hy + dy[i];
		if (nx >= 0 && nx <= n && ny >= 0 && ny <= m) {
			ctrl[nx][ny] = 1;
		}
	}
	f[0][0] = 1;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (ctrl[i][j])continue;
			if (i != 0)f[i][j] += f[i - 1][j];
			if (j != 0)f[i][j] += f[i][j - 1];
		}
	}
	cout << f[n][m];
	return 0;
}

//1044
#include <cstdio>
#include <iostream>
using namespace std;
int h[25];
int main() {
	//h[n] = h[0] * h[n-1]+ 
	//       h[1] * h[n-2]+ ...+ h[n-1] * h[0]
	int n;
	cin >> n;
	h[0] = 1;
	h[1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			h[i] += h[j] * h[i - j - 1];
			//h[j]前半部分方案数， h[i-j-1]后半部分方案数 
		}
	}
	cout << h[n];
}

#include<bits/stdc++.h>
using namespace std;
int n;
int f[1005];//记忆化 
int sol(int x) {
	int ans = 1;
	if (f[x] != -1)return f[x];
	for (int i = 1; i <= x / 2; i++)ans += sol(i);
	f[x] = ans;
	return f[x];
}
int main() {
	cin >> n;
	memset(f, -1, sizeof(f));
	f[1] = 1;
	cout << sol(n);
	return 0;
}
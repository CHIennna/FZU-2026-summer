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
int a[17];
int b1[17][5], b2[17][5], b3[17][5];
int ans;
int n = 16;
void dfs1(int x) {
	if (x > 16) {
		ans++;
		for (int i = 1; i <= n; i++) {
			cout << a[i] << " ";
			if (i % 4 == 0) {
				cout << '\n';
			}
		}
		cout << '\n';
		return;
	}
	int hang = (x-1) / 4 +1;
	int lie = (x-1) % 4+1;
	int block = (hang-1) /2 * 2 +(lie-1)/2+1;
		for (int i = 1; i <= 4; i++) {
			if (b1[hang][i] == 0 && b2[lie][i] == 0 && b3[block][i] == 0) {
				a[x] = i;
				b1[hang][i] = 1; b2[lie][i] = 1; b3[block][i] = 1;
				dfs1(x + 1);
				b1[hang][i] = 0; b2[lie][i] = 0; b3[block][i] = 0;
			}
	}
}

int main1() {
	dfs1(1);
	cout << ans;
	return 0;
}
//八皇后
int grid[14];
int n;
int ans;
int b1[14], b2[28], b3[200];//储存列 上对角线 下对角线
void dfs2(int x) {
	if (x > n) {
		ans++;
		if (ans <= 3) {
			for (int i = 1; i <= n; i++) {
				cout << grid[i] << ' ';
			}
			cout << '\n';
		}
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (b1[i] == 0 && b2[x + i] == 0 && b3[x - i + n] == 0) {
			grid[x] = i;
			b1[i] = 1; b2[x + i] = 1; b3[x - i + n] = 1;
			dfs2(x + 1);
			b1[i] = 0; b2[x + i] = 0; b3[x - i + n] = 0;
		}
	}
}

int main2() {
	cin >> n;
	dfs2(1);
	cout << ans;
	return 0;
}

//=======================================
#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
//2392
using namespace std;
typedef long long ll;
int ans;
int s[5];
int consume[5][62];
int sum;
int floor_cnt;
int left_nao;
int right_nao;
int cur_ans;
int sb;
void dfs(int index) {
	if (index > floor_cnt) {
		right_nao = sum - left_nao;
		cur_ans = min(cur_ans,max(left_nao, right_nao));
		return;
	}
	//goal:lim infinity- right_nao == left_nao
	if (left_nao + consume[sb][index] <= sum / 2) {
		left_nao += consume[sb][index];
		dfs(index + 1);
		left_nao -= consume[sb][index];
	}
	dfs(index + 1);
}

int main() {
	cin >> s[1] >> s[2] >> s[3] >> s[4];
	for (int i = 1; i <= 4; i++) {
		sum = 0;
		floor_cnt = s[i];
		sb = i;
		left_nao = 0;
		right_nao = 0;
		cur_ans = 0x3f3f3f3f;
		for (int j = 1; j <= s[i]; j++) {
			cin >> consume[i][j];
			sum += consume[i][j];
		}
		dfs(1);
		ans += cur_ans;
	}
	cout << ans;
	return 0;
}


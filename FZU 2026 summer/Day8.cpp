#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
//2392 repeat
using namespace std;
typedef long long ll;
int s[5];
int a[5][65];
int left_nao;
int maxstep;
int cur_ans;
int ans;
int sum;
void dfs(int x) {
	if (x > maxstep) {
		cur_ans = min(cur_ans, max(left_nao, sum - left_nao));
		return;
	}
	if (left_nao + a[x] <= sum / 2) {
		left_nao += a[x];
		dfs(x + 1);
		left_nao -= a[x];//huisu
	}
	else {
		dfs(x + 1);
	}
}

int main() {
	cin >> s[1] >> s[2] >> s[3] >> s[4];
	for (int i = 1; i <= 4; i++) {
		maxstep = s[i];
		left_nao = 0;
		cur_ans = 0x3f3f3f3f;
		sum = 0;
		for (int j = 1; j <= s[i]; j++) {
			cin >> a[i][j];
			sum += a[i][j];
		}
		dfs(1);
		ans += cur_ans;
	}
	cout << ans;
	return 0;
}


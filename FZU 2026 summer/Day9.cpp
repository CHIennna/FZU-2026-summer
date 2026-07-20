#include <bits/stdc++.h>
using namespace std;
int maxstep;
int cur_ans;
int sum;
int ans;
int left_nao;
int sb;
int s[5];
int arr[6][66];
void dfs(int x) {
	if (x > maxstep) {
		cur_ans = min(cur_ans, max(left_nao, sum - left_nao));
		return;
	}
	if (arr[sb][x] + left_nao <= sum / 2) {
		left_nao += arr[sb][x];
		dfs(x + 1);
		left_nao -= arr[sb][x];
	}
	dfs(x + 1);

}

int main() {
	cin >> s[1] >> s[2] >> s[3] >> s[4];
	for (int i = 1; i <= 4; i++) {
		left_nao = 0;
		sum = 0;
		sb = i;
		cur_ans = 0x3f3f3f3f;
		maxstep = s[i];
		for (int j = 1; j <= s[i]; j++) {
			cin >> arr[i][j];
			sum += arr[i][j];
		}
		dfs(1);
		ans += cur_ans;
	}
	cout << ans;
	return 0;
}


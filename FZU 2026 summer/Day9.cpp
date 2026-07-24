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

1303
#include <bits/stdc++.h>
using namespace std;
#define maxn 5050
int a[maxn], b[maxn], c[2 * maxn + 5];
int main() {
	string  A, B;
	cin >> A >> B;
	int lena = A.length();
	int lenb = B.length();
	int len = lena + lenb;
	for (int i = lena - 1, j = 1; i >= 0; i--, j++) {
		a[j] = A[i] - '0';
	}
	for (int i = lenb - 1, j = 1; i >= 0; i--, j++) {
		b[j] = B[i] - '0';
	}
	for (int i = 1; i <= lena; i++) {
		for (int j = 1; j <= lenb; j++) {
			c[i + j - 1] += a[i] * b[j];//+=, not=
		}
	}
	for (int i = 1; i <= len; i++) {
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
	}
	while (len > 1 && c[len] == 0) {
		len--;
	}
	for (int i = len; i >= 1; i--) {
		cout << c[i];
	}
}


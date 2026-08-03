#include <bits/stdc++.h>
using namespace std;

int m;
int n;
int a[1000010];
int main() {
	cin >> m >> n;
	long long ans = 0;
	for (int i = 1; i <= m; i++)cin >> a[i];
	sort(a + 1, a + m + 1);
	for (int i = 1; i <= n; i++) {
		int score;
		cin >> score;//>=
		int pos = lower_bound(a + 1, a + m + 1, score) - a;
		if (pos == 1)ans += abs(a[1] - score);
		else if (pos == m + 1)ans += abs(a[m] - score);
		else {
			long long diff1 = abs(a[pos] - score);
			long long diff2 = abs(a[pos - 1] - score);
			long long diff = min(diff1, diff2);
			ans += diff;
		}
	}
	cout << ans;
}


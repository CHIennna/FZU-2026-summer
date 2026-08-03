#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
string expand() {
	string res = "";
	string x = "";
	char c;
	int d;
	while (cin >> c) {
		if (c == '[') {
			cin >> d;
			x = expand();
			while (d--)res += x;
		}
		else if (c == ']') {
			return res;
		}
		else {
			res += c;
		}
	}
	return res;
}
int main() {
	cout << expand();
}

#include<bits/stdc++.h>
using namespace std;
struct node {
	int weight;
	int value;
}coin[110];
bool cmp(node& a, node& b) {
	return a.value * b.weight > b.value * a.weight;
}
int main() {
	int n, t;
	cin >> n >> t;
	double ans = 0.0;
	int left = t;
	for (int i = 0; i < n; i++)cin >> coin[i].weight >> coin[i].value;
	sort(coin, coin + n, cmp);
	//int sb=0;
	for (int i = 0; i < n; i++) {
		//		if(coin[i].weight > left){
		//			sb=i;//如果提前拿完而且背包还没放满呢，re！ 
		//			break;
		//		}
		if (left >= coin[i].weight) {
			left -= coin[i].weight;
			ans += coin[i].value;
		}
		else {
			ans += 1.0 * left / coin[i].weight * coin[i].value;
			break;
		}
	}
	cout << fixed << setprecision(2) << ans << '\n';
	return 0;
}


struct person {
	int time;
	int id;
}per[1005];

bool cmp(const person& a, const person& b) {
	if (a.time != b.time)return a.time < b.time;
	return a.id < b.id;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> per[i].time;
		per[i].id = i;
	}
	sort(per + 1, per + n + 1, cmp);
	long long wait = 0;
	for (int i = 1; i <= n; i++) {
		cout << per[i].id;
		if (i != n) cout << " ";
	}
	cout << "\n";
	for (int i = 1; i <= n; i++) {
		wait += 1ll * (n - i) * per[i].time;
	}
	cout << fixed << setprecision(2) << 1.0 * wait / n << '\n';
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1000010;
int a[maxn];
int m, n, q;

int find(int x) {
	int l = 1, r = n;
	int ans = -1;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		if (a[mid] >= x) {
			if (a[mid] == x)ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> q;
		cout << find(q) << " ";
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;        int c;
	ll ans = 0;   ll a[200010];
	cin >> n >> c;
	for (int j = 0; j < n; j++) {
		cin >> a[j];
	}
	sort(a, a + n);
	//法一 
	for (int i = 0; i < n; i++) {
		ans += upper_bound(a, a + n, a[i] + c) - lower_bound(a, a + n, a[i] + c);
	}
	cout << ans << '\n';
	//法二 
	for (int i = 0, L = 0, R = 0; i < n; i++) {
		while (L < n && a[L] < a[i] + c)L++;
		while (R < n && a[R] <= a[i] + c)R++;
		ans += R - L;
	}
	cout << ans << '\n';
	return 0;
}

#include <set>
#include <map>
#include <queue>
#include <stack>
#include <ctime>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <random>
#include <numeric>
#include <utility>
#include <iomanip>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;
typedef long long ll;
int main() {
	int n, x;
	cin >> n >> x;
	vector<ll> candy(n);
	for (int i = 0; i < n; i++) {
		cin >> candy[i];
	}
	ll ans = 0;
	for (int i = 1; i < n; i++) {
		ll sum = candy[i - 1] + candy[i];
		if (sum > x) {
			ll need = sum - x;
			// 右边能吃多少
			ll eat_right = min(candy[i], need);
			candy[i] -= eat_right;
			need -= eat_right;
			ans += eat_right;
			// 右边不够 再从左边吃
			if (need > 0) {
				candy[i - 1] -= need;
				ans += need;
			}
		}
	}
	cout << ans << endl;
	return 0;
}

#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
constexpr int maxn = 1000011;
ll a[maxn];
ll n, m;
bool isValid(int h) {
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] > h) {
			sum += a[i] - h;
		}
	}
	return sum >= m;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int l = 0, r = 2e9;
	int mid, ans;
	while (l <= r) {
		mid = l + (r - l) / 2;
		if (isValid(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	cout << ans << endl;
	return 0;
}


#include <bits/stdc++.h>
using namespace std;
vector<int>a;
int ans;
void kth_element(vector<int>& a, int k, int left, int right) {
	if (left == right) {
		ans = a[left];
		return;
	}
	int i = left;
	int j = right;
	int goal = a[(left + right) / 2];
	while (i <= j) {
		while (a[i] < goal)i++;
		while (a[j] > goal)j--;
		if (i <= j) {
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (k <= j) {
		kth_element(a, k, left, j);
	}
	else if (k >= i) {
		kth_element(a, k, i, right);
	}
	else {//bug
		ans = a[k];
		return;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	a.resize(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	kth_element(a, k, 0, n - 1);
	cout << ans << '\n';
}


////1093
//struct Student{
//	int sum;
//	int cn;
//	int id;
//}student[350];
//bool cmp(Student&a,Student&b){
//	if(a.sum!=b.sum)return a.sum > b.sum;
//	if(a.cn != b.cn)return a.cn > b.cn;
//	return a.id < b.id;
//}
//
//int main(){
//	int n;cin>> n;
//	for(int i  = 1;i<=n;i++){
//		int math,eng;
//		cin >> student[i].cn >> math>>eng;
//		student[i].sum = student[i].cn+math+eng;
//		student[i].id=i;
//	}
//	sort(student+1,student+1+n,cmp);
//	for(int i = 1; i<=5;i++){
//		cout << student[i].id << " " << student[i].sum << '\n';
//	}
//}

//1036
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 30;
int n, k;
int ans;
int arr[maxn];
bool isPrime(int x) {
	if (x <= 1)return false;
	if (x == 2)return true;
	if (x % 2 == 0)return false;
	for (int i = 3; i * i <= x; i += 2) {
		if (x % i == 0)return false;
	}
	return true;
}

void dfs(int arr[], int cnt, int selected_cnt, int sum) {
	if (selected_cnt == k) {
		if (isPrime(sum)) {
			ans++;
		}
		return;
	}
	for (int i = cnt; i < n; i++) {
		dfs(arr, i + 1, selected_cnt + 1, sum + arr[i]);
	}
}

int main() {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dfs(arr, 0, 0, 0);
	cout << ans << endl;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 30;
int n, k;
int ans;
int a[maxn];

int main() {
	int n, k, ans = 0;
	cin >> n >> k;
	int U = 1 << n;
	for (int i = 0; i < n; i++)cin >> a[i];
	for (ll S = 0; S < U; S++) {
		if (__builtin_popcount(S) == k) {
			int sum = 0;
			for (int i = 0; i < n; i++) {
				if (S & (1 << i))sum += a[i];
			}
			if (isPrime(sum))ans++;
		}
	}
	cout << ans;
	return 0;
}

//1157
int n, r;
vector<int>num;
vector<vector<int>> ans;
vector<int> path;
void dfs(vector<int>& num, int pos, int selected_cnt) {
	if (selected_cnt == r) {
		for (int x : path) {
			cout << setw(3) << x;
		}
		cout << '\n';
		return;
	}
	for (int i = pos; i <= n; i++) {
		path.push_back(i);
		dfs(num, i + 1, selected_cnt + 1);
		path.pop_back();
	}
}
int main() {
	cin >> n >> r;
	for (int i = 1; i <= n; i++) {
		num.push_back(i);
	}
	dfs(num, 1, 0);
	return 0;
}

int a[30];
int main() {
	int n, r;
	cin >> n >> r;
	for (int S = (1 << n) - 1; S >= 0; S--) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (S & (1 << i)) {
				a[cnt] = i;
				cnt++:
			}
		}
		if (cnt == r) {
			for (int i = r - 1; i >= 0; i--) {
				cout << setw(3) << n - a[i];
			}cout << '\n';
		}
	}
	return 0;
}


#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int a[10];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		a[i] = i;
	}
	do {
		for (int i = 1; i <= n; i++) {
			cout << setw(5) << a[i];
		}
		cout << " " << endl;
	} while (next_permutation(a + 1, a + 1 + n));
	return 0;
}

//1618法2
int a[10];
int main() {
	int A, B, C, x, y, z;
	int ans = 0;
	cin >> A >> B >> C;
	bool found = false;
	for (int i = 1; i <= 9; i++) {
		a[i] = i;
	}
	do {
		x = a[1] * 100 + a[2] * 10 + a[3];
		y = a[4] * 100 + a[5] * 10 + a[6];
		z = a[7] * 100 + a[8] * 10 + a[9];
		if (x * B == y * A && y * C == z * B) {
			cout << x << " " << y << " " << z << '\n';
			found = true;
		}
	} while (next_permutation(a + 1, a + 10));
	if (!found)cout << "No!!!";
}


//1135
#include <bits/stdc++.h>
using namespace std;
int n, a, b;
int grid[205];
int dist[205];//dist == cnt == step
int bfs(int x) {
	queue<int> que;
	que.push(x);
	dist[x] = 0;
	while (!que.empty()) {
		int curx = que.front();
		que.pop();
		if (curx == b)return dist[curx];
		for (int i = -1; i <= 1; i += 2) {
			int nx = curx + grid[curx] * i;
			if (nx <1 || nx>n || dist[nx] != -1) {
				continue;
			}
			que.push(nx);
			dist[nx] = dist[curx] + 1;
		}
	}
	return -1;
}

int main() {
	cin >> n >> a >> b;
	memset(dist, -1, sizeof(dist));
	for (int i = 1; i <= n; i++) {
		cin >> grid[i];
	}
	cout << bfs(a) << '\n';
	return 0;
}
//=================================
#include <bits/stdc++.h>
using namespace std;
//1009
int fact[101];
int sum[101];
int main() {
	int n;
	cin >> n;
	fact[1] = 1;
	sum[1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= 100; j++) {
			fact[j] *= i;
		}
		for (int j = 1; j <= 99; j++) {
			fact[j + 1] += fact[j] / 10;
			fact[j] %= 10;
		}
		for (int j = 1; j <= 100; j++) {
			sum[j] += fact[j];
		}
		for (int j = 1; j <= 99; j++) {
			sum[j + 1] += sum[j] / 10;
			sum[j] %= 10;
		}
	}
	int len = 100;
	while (len > 1 && sum[len] == 0) {
		len--;
	}
	for (int i = len; i >= 1; i--) {
		cout << sum[i];
	}
}



	//=================================
#include <bits/stdc++.h>
	using namespace std;

	const int MAXN = 1010;

	int a[MAXN];    // 当前阶乘
	int res[MAXN];  // 阶乘和

	int main() {
		int n;
		cin >> n;

		// a = 1!，res = 1!
		a[0] = 1;
		res[0] = 1;

		for (int i = 2; i <= n; i++) {
			// 第一步：a *= i
			int carry = 0;

			for (int j = 0; j < MAXN; j++) {
				int temp = a[j] * i + carry;

				a[j] = temp % 10;
				carry = temp / 10;
			}

			// 第二步：res += a
			for (int j = 0; j < MAXN - 1; j++) {
				res[j] += a[j];
				res[j + 1] += res[j] / 10;
				res[j] %= 10;
			}
		}

		// 找最高非零位
		int len = MAXN - 1;

		while (len > 0 && res[len] == 0) {
			len--;
		}

		// 从最高位输出到个位
		for (int i = len; i >= 0; i--) {
			cout << res[i];
		}

		return 0;
	}
}

//1271
#include <iostream>
using namespace std;
int a[1005];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x;
		cin >> x;
		a[x]++;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < a[i]; j++) {
			cout << i << " ";
		}
	}
}

//1303
int a[3000], b[3000], c[3000];
int main() {
	string A, B;
	cin >> A >> B;
	int lena = A.length();
	int lenb = B.length();
	for (int i = lena - 1, j = 1; i >= 0; i--, j++) {
		a[j] = A[i] - '0';
	}
	for (int i = lenb - 1, j = 1; i >= 0; i--, j++) {
		b[j] = B[i] - '0';
	}
	for (int i = 1; i <= lena; i++) {
		for (int j = 1; j <= lenb; j++) {
			c[i + j - 1] += a[i] * b[j];
		}
	}
	for (int i = 1; i < 2999; i++) {
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
	}
	int len = 2999;
	while (len > 1 && c[len] == 0) {
		len--;
	}
	for (int i = len; i >= 1; i--) {
		cout << c[i];
	}
}

//三大排序
//选择 冒泡 插入

void selectsort() {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[i]) {
				swap(a[i], a[j]);
			}
		}
	}
}

void bubblesort() {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
			}
		}
	}
}

void insertsort() {
	for (int i = 1; i < n; i++) {
		int now = a[i];
		int j;
		for (j = i - 1; j >= 0; j--) {
			if (a[j] > now)
				a[j + 1] = a[j];
			else
				break;
		}
		a[j + 1] = now;
	}
}
#include <iostream>
#include <utility>
using namespace std;
void quickSort(int a[], int left, int right) {
	int i = left;       int j = right;
	int pivot = a[(left + right) / 2];
	while (i <= j) {
		while (a[i] < pivot) {
			i++;
		}
		while (a[j] > pivot) {
			j--;
		}

		if (i <= j) {// 两个指针还没有交错
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	// 排序左半部分
	if (left < j) {
		quickSort(a, left, j);
	}
	// 排序右半部分
	if (i < right) {
		quickSort(a, i, right);
	}
}

int main() {
	int a[] = { 3, 8, 4, 10, 6, 7, 2, 5, 9, 1 };
	int n = sizeof(a) / sizeof(a[0]);
	quickSort(a, 0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	return 0;
}
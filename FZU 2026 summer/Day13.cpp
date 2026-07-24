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


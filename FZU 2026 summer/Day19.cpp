//1824 #include <bits/stdc++.h>
using namespace std;
int a[1000010];
int n, c;
bool check(int dist) {
	int last = -1e9;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] - last >= dist) {
			last = a[i];
			cnt++;
		}
	}
	return cnt >= c;
}
int main() {
	cin >> n >> c;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int left = 0;
	int right = 1e9;
	int ans = 0;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (check(mid)) {
			ans = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << ans << '\n';
}

#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
double a, b, c, d;
double calculate(double x) {
	return a * x * x * x + b * x * x + c * x + d;
}
int main() {
	cin >> a >> b >> c >> d;
	for (int i = -100; i <= 100; i++) {
		double left = i;
		double right = i + 1;
		//左闭右开 
		if (abs(calculate(left)) < eps)cout << fixed << setprecision(2) << left << " ";
		else if (abs(calculate(right)) < eps)continue;
		else if (calculate(left) * calculate(right) < 0) {
			while (right - left > eps) {
				double mid = (left + right) / 2;
				if (calculate(mid) * calculate(right) > 0) {
					right = mid;
					//正负性判断在哪侧 
				}
				else {
					left = mid;
				}
			}
			cout << fixed << setprecision(2) << left << " ";
		}
	}
}

#include <bits/stdc++.h>
using namespace std;
struct test{
	int start;
	int end;
}tes[1000010];
bool cmp(const test&a, const test&b){
	return a.end <= b.end;
}
int main(){
	int n;
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>> tes[i].start>>tes[i].end;
	}
	int ans = 0;
	sort(tes+1,tes+n+1,cmp);
	int flag = 0;
	for(int i = 1; i <= n; i++){
		if(flag <= tes[i].start){
			ans++;
			flag = tes[i].end;
		}
	}
	cout << ans;
}

#include <bits/stdc++.h>
using namespace std;
int n;
//int main(){
//	cin >> n;
//	priority_queue<int,vector<int>,greater<int>> que;
//	int x;
//	while(cin >> x){
//		que.push(x);
//	}
//	int ans = 0;
//	while(que.size()>1){
//		int a = que.top();
//		que.pop();
//		int b = que.top();
//		que.pop();
//		int sum = a + b;
//		que.push(a+b);
//		ans += sum;
//	}
//	cout << ans;
//}
int a1[20010];
int a2[20010];
int n2;
int flag1;
int flag2;
int main() {
	cin >> n;
	memset(a2, 0x3f, sizeof(a2));
	for (int i = 0; i < n; i++) {
		cin >> a1[i];
	}
	sort(a1, a1 + n);
	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		int first = 0, second = 0;
		if (flag1 < n && a1[flag1] < a2[flag2]) {
			first = a1[flag1];
			flag1++;
		}
		else {
			first = a2[flag2];
			flag2++;
		}
		if (flag1 < n && a1[flag1] < a2[flag2]) {
			second = a1[flag1];
			flag1++;
		}
		else {
			second = a2[flag2];
			flag2++;
		}
		int sum = first + second;
		ans += sum;
		a2[n2] = sum;
		n2++;
	}
	cout << ans;
}

//1164
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[105][10005];//n份花掉m元 
int n, m;
ll a[105];
ll ans;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	f[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			f[i][j] += f[i - 1][j];
			if (j >= a[i])f[i][j] += f[i - 1][j - a[i]];
		}
	}
	cout << f[n][m];
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1000010;
int m, n;
int a[maxn], b[maxn];

int main() {
	cin >> m >> n;
	for (int i = 1; i <= m; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	sort(a + 1, a + 1 + m);
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		int tes = 1e9;
		int l = 1, r = m;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (a[mid] <= b[i]) {
				tes = min(tes, abs(a[mid] - b[i]));
				l = mid + 1;
			}
			else {
				tes = min(tes, abs(a[mid] - b[i]));
				r = mid - 1;
			}
		}
		ans += tes;
		//===========================================================
		//		int score;cin >> score;
		//        int pos = lower_bound(a + 1, a + m+1, score) - a;
		//        if (pos == 1) {//score小于等于所有学校分数
		//            ans += abs(a[1] - score);
		//        } else if (pos == m+1) {//score大于所有学校分数
		//            ans += abs(a[m] - score);
		//        } else {//比较左右两个候选
		//            ll right_diff = abs(a[pos] - score);
		//            ll left_diff = abs(a[pos - 1] - score);
		//            ans += min(left_diff, right_diff);
		//        }
	}
	cout << ans << endl;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
//1093
struct Student {
	int sum;
	int cn;
	int id;
}student[350];
bool cmp(Student& a, Student& b) {
	if (a.sum != b.sum)return a.sum > b.sum;
	if (a.cn != b.cn)return a.cn > b.cn;
	return a.id < b.id;
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int math, eng;
		cin >> student[i].cn >> math >> eng;
		student[i].sum = student[i].cn + math + eng;
		student[i].id = i;
	}
	sort(student + 1, student + 1 + n, cmp);
	for (int i = 1; i <= 5; i++) {
		cout << student[i].id << " " << student[i].sum << '\n';
	}
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
vector<int>a;
void kth_element(int l, int r) {
	if (l == r) {
		cout << a[l];
		return;
	}
	int i = l, j = r;
	int tarzan = a[l + (r - l) / 2];
	while (i <= j) {
		while (a[i] < tarzan)i++;
		while (a[j] > tarzan)j--;
		if (i <= j) {
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (k <= j) {
		kth_element(l, j);
	}
	else if (k >= i) {
		kth_element(i, r);
	}
	else {
		kth_element(j + 1, i - 1);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> k;
	a.resize(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	kth_element(0, n - 1);
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int n;
	cin >> n;
	for (int i = n; i >= 0; i--) {
		int tes;
		cin >> tes;
		if (tes == 0)continue;
		if (tes > 0 && i != n)cout << '+';
		if (tes < 0)cout << '-';
		if (i == 0 || abs(tes) != 1)cout << abs(tes);
		if (i > 1)cout << "x^" << i;
		if (i == 1)cout << "x";
	}
	return 0;
}

//1177
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n;
vector<int> a;
void quicksort(int left, int right) {
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
		quicksort(i, right);
	}
	if (j > left) {
		quicksort(left, j);
	}
}

int main() {
	cin >> n;
	a.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	quicksort(1, n);
	for (int i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}
	cout << '\n';
	return 0;
}
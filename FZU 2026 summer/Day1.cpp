#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 333;
const int inf = 1e9;
const ll infll = 1e18;
//锐意当鸣 - 2026 fzu summer - Day1

bool comparerr(int a, int b) {
	return a < b;
}

struct Person {
	string name;
	int score;
};

struct Student {
	string name;
	string number;
	int score;
}Stu[maxn];

int main() {
	//Part1-1，输入输出加速
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	//Part1-2，vector
	vector<int> a(n);
	for (int& x : a) {//引用法修改元素
		cin >> x;
	}
	//for (int i = 0; i < a.size(); i++) {
	//	cin >> a[i];
	//}

	a.push_back(10);//尾插法
	a.pop_back();//尾删法
	a.size();//元素数量
	a.empty();//判断是否为空
	a.clear();//晴空
	a[0];//下标遍历法
	a.front();//第一个元素
	a.back();//最后一个元素

	for (int x : a) {
		cout << x << ' ';
	}

	//Part1-3，pair
	vector<pii> p;
	p.push_back({ 1,2 });
	p.push_back({ 2,7 });
	//bonus-lambda函数  []是 Lambda 捕获列表
	//[]       // 不捕获外部变量
	//[&]      // 按引用捕获外部变量
	//[=]      // 按值捕获外部变量
	//[x]      // 按值捕获 x
	//[&x]     // 按引用捕获 x
	auto cmp = [](const pii& a, const pii& b) {
		if (a.second != b.second) {
			return a.second < b.second;
		}
		return a.first < b.first;
	};

	sort(p.begin(), p.end(), cmp);

	for (auto&x : p) {
		cout << x.first << " " << x.second << '\n';
	}

	//Part1-4,结构体
	Person per;
	per = { "Bin",95 };
	vector<Person> persons(n);
	for (int i = 0; i < n; i++) {
		cin >> persons[i].name >> persons[i].score;
	}

	//Part1-5，sort
	sort(a.begin(), a.end());
	sort(a.begin(), a.end(), greater<int>());

	

	sort(a.begin(), a.end(), comparerr);

	//Part1-6,map and unordered_map
	map<int, int> mp1;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		mp1[x]++;
	}
	for (auto [x, cnt] : mp1) {
		cout << x << " " << cnt << '\n';
	}
	//map的键会自动从小到大排列
	//cin  n = 5,3 1 3 2 1
	//cout 1 2/2 1/3 2
	unordered_map<int, int> mp2;//元素没有规定顺序，用于快速查找统计
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		mp2[x]++;
	}
	//Part1-7
	vector<ll> b(n);
	for (ll& x : b) {
		cin >> x;
	}
	ll minimum = b[0];
	ll maximum = b[0];
	ll sum = 0;
	for (ll x : b) {
		maximum = max(maximum, x);
		minimum = min(minimum, x);
		sum += x;
	}
	double average = (double)sum / n;
	cout << fixed << setprecision(2) << average << '\n';//iomanip
	cout << '\n';
	return 0;
}

int pat1003() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int count_p = 0;
		int count_t = 0;
		int count_a = 0;
		int p_index = -1;
		int t_index = -1;
		bool ispassed = true;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == 'P') {
				count_p++;
				p_index = j;
			}
			else if (s[j] == 'T') {
				count_t++;
				t_index = j;
			}
			else if (s[j] != 'A') {
				ispassed = false;
				break;
			}
		}

		if (count_p != 1 || count_t != 1 ||  p_index + 1 >= t_index) {
			ispassed = false;
		}
		int a = p_index;
		int b = t_index - p_index - 1;
		int c = s.length() - t_index - 1;
		if (a * b != c) {
			ispassed = false;
		}
		if (ispassed) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
	}
	return 0;
}


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<double, double> pdd;
洛谷3743 浮点数二分要注意不用while，直接100次for循环
int n;
ll p;
vector<pdd> device;

bool check(double x) {
	double need = 0.0;
	for (int i = 1; i <= n; i++) {
		if (device[i].first * x - device[i].second > 0) {
			need += device[i].first * x - device[i].second;
		}
	}
	return need <= p * x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> p;
	device.resize(n + 1);
	ll totalConsume = 0;
	for (int i = 1; i <= n; i++) {
		cin >> device[i].first >> device[i].second;
		totalConsume += device[i].first;
	}

	if (totalConsume <= p) {
		cout << -1 << '\n';
		return 0;
	}

	double left = 0.0;
	double right = 1e10;
	double ans = 0.0;

	for (int i = 0; i < 100; i++) {
		//while (right - left > 1e-9) {
		double mid = left + (right - left) / 2.0;
		if (check(mid)) {
			ans = mid;
			left = mid;
		}
		else {
			right = mid;
		}
		//}
	}
	cout << fixed << setprecision(6) << ans << '\n';
	return 0;
}

int pat1004() {
	
	{
		int n;
		cin >> n;
		cin >> Stu[0].name >> Stu[0].number >> Stu[0].score;
		int max_score = Stu[0].score;
		int min_score = Stu[0].score;
		int max_index = 0;
		int min_index = 0;
		for (int i = 1; i < n; i++) {
			cin >> Stu[i].name >> Stu[i].number >> Stu[i].score;

			if (Stu[i].score > max_score) {
				max_score = Stu[i].score;
				max_index = i;
			}
			if (Stu[i].score < min_score) {
				min_score = Stu[i].score;
				min_index = i;
			}
		}
		cout << Stu[max_index].name << " " << Stu[max_index].number << endl;
		cout << Stu[min_index].name << " " << Stu[min_index].number << endl;
		return 0;
	}
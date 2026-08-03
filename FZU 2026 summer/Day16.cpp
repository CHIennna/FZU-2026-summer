#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[25][25][25];

ll w(ll a, ll b, ll c) {//当心数组越界 
	if (a <= 0 || b <= 0 || c <= 0)return 1;
	else if (a > 20 || b > 20 || c > 20)return w(20, 20, 20);
	else if (f[a][b][c] != 0)return f[a][b][c];
	else if (a < b && b < c)f[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	else { f[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1); }
	return f[a][b][c];
}

int main() {
	ll a, b, c;//not ll a,ll b,ll c
	while (cin >> a >> b >> c) {
		if (a == -1 && b == -1 && c == -1) {
			break;
		}
		cout << "w(" << a << ", " << b << ", " << c << ") = ";
		cout << w(a, b, c) << '\n';
	}
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	for(int i=n; i>=0; i--){
		int a;//系数 
		cin >> a;//-100 ~ 100
		if(a==0)continue;
		//处理系数 
		if(a>0 && i!=n) cout << '+';
		if(a<0) cout << '-';
		if(abs(a)!=1 || i==0) cout << abs(a);
		//处理字母 
		if(i>=1) cout << 'x';
		if(i>=2) cout << '^' << i;
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string expand() {
	char c;
	string res;
	int d;
	string x;
	//AC[3FUN[2GA]]
	while(cin >> c) {
		if (c == '[') {
			cin >> d;
			x = expand();
			while (d--) res += x;
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
int main(){
	cout << expand();
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	for (int i = n; i >= 0; i--) {
		int a;//系数 
		cin >> a;//-100 ~ 100
		if (a == 0)continue;
		//处理系数 
		if (a > 0 && i != n) cout << '+';
		if (a < 0) cout << '-';
		if (abs(a) != 1 || i == 0) cout << abs(a);
		//处理字母 
		if (i >= 1) cout << 'x';
		if (i >= 2) cout << '^' << i;
	}
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Person {
	int time, id;
};

bool cmp(const Person& x, const Person& y)
{
	if (x.time != y.time)
		return x.time < y.time;
	return x.id < y.id;
}

int main()
{
	int n;
	cin >> n;
	vector<Person> p(n + 1); // p[1]~p[n]使用
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i].time;
		p[i].id = i;
	}
	// 只排序有效区间！跳过p[0]
	sort(p.begin() + 1, p.end(), cmp);

	// 只输出1~n
	for (int i = 1; i <= n; i++)
		cout << p[i].id << " ";
	cout << endl;

	long long sum = 0;
	for (int i = 1; i <= n - 1; i++)
	{
		sum += 1LL * p[i].time * (n - i);
	}
	double avg = 1.0 * sum / n;
	cout << fixed << setprecision(2) << avg;
	return 0;
}

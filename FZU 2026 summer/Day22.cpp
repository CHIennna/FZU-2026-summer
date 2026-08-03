//#include <bits/stdc++.h>
//using namespace std;
//typedef long long ll;
////int m,n;
////int a[1000010];
////int main(){
////	cin>>m>>n;
////	ll sum = 0;
////	for(int i = 0;i<m;i++)cin>>a[i];
////	sort(a,a+m);
////	for(int i =0;i<n;i++){
////		int b;
////		cin>>b;
////		int pos = lower_bound(a,a+m,b)-a;
////		if(pos==0)sum+=abs(a[0]-b);
////		else if(pos==m)sum+=abs(a[m-1]-b);
////		else{
////			int diff1=abs(a[pos]-b);
////			int diff2=abs(a[pos-1]-b);
////			int diff = min(diff1,diff2);
////			sum+=diff;	
////		}
////	}
////	cout<<sum;
////}
//
//
//#include <bits/stdc++.h>
//using namespace std;
//typedef long long ll;
////int m, n;
////int a[1000010];
////int main() {
////	cin >> m >> n;
////	for (int i = 1; i <= m; i++) cin >> a[i];
////	sort(a+1, a + 1 + m);
////	ll ans = 0;
////	for (int i = 1; i <= n; i++){
////		int score;
////		cin>>score;
////		int left = 1;
////		int right = m;
////		int sum = 1e9;
////		while(left <= right){
////			int mid = left+(right-left)/2;
////			if(a[mid]<=score){
////				left = mid+1;
////				sum = min(sum,abs(a[mid]-score));
////			}else{
////				right = mid-1;
////				sum = min(sum,abs(a[mid]-score));
////			}
////		}
////		ans+=sum;
////	}
////	cout<<ans;
////}
//
////const int maxn = 1000010;
////int a[maxn];
////int n,m;
//////first time to exist
////int find(int x){
////	int pos = lower_bound(a+1,a+n+1,x)-a;
////	if(a[pos]==x && pos<=n)return pos;
////	else return -1;
////}
////int main(){
////	ios::sync_with_stdio(false);
////	//cin.tie(nullptr);
////	cin>>n>>m;
////	for(int i = 1; i <=n; i++){
////		cin>>a[i];
////	}//a[i-1]<=a[i]
////	for(int i = 1; i <= m; i++){
////		int x;
////		cin>>x;
////		cout<<find(x);
////		if(i!=m)cout<<" ";
////	}
////	cout<< '\n';
////	return 0;
////}
//
//#include <bits/stdc++.h>
//using namespace std;
//constexpr int maxn = 1000010;
//int a[maxn];
//int m, n, q;
//
//int find(int x) {
//	int left = 1;
//	int right = n;
//	int mid;
//	int ans = -1;
//	while(left<=right){
//		mid = left + (right - left)/2;
//		if(a[mid] >= x){
//			if(a[mid]==x)ans=mid;
//			right = mid - 1;
//		}else{
//			left =  mid + 1;
//		}
//	}
//	return ans;
//}
//
//int main() {
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 1; i <= m; i++) {
//		cin >> q;
//		cout << find(q) << " ";
//	}
//	return 0;
//}
//
//#include <bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//int n,x;
//vector<ll> a; 
//int main(){
//	cin>>n>>x;
//	a.resize(n+1);
//	for(int i= 0; i < n; i++)cin>>a[i];
//	ll sum = 0;
//	for(int i = 1;i < n; i++){
//		ll cur_sum = a[i-1]+a[i];
//		ll diff_right=0;
//		if(cur_sum > x){
//			ll need = cur_sum-x;
//			diff_right = min(a[i],need);
//			a[i]-=diff_right;
//			sum+=diff_right;
//			need -= diff_right;
//			if(need){
//				a[i-1]-=need;
//				sum+=need;
//			}
//		}
//	}
//	cout<<sum<<'\n';
//}
//
//#include <bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int n,c;
//	cin>>n>>c;
//	vector<ll> a(n);
//	for(int i =0;i<n;i++)cin>>a[i];
//	ll ans =0;
//	sort(a.begin(),a.end());
//	for(int i =0;i<n;i++){
//		ans += upper_bound(a.begin(),a.end(),a[i]+c)-lower_bound(a.begin(),a.end(),a[i]+c);
//	}
//	cout<<ans;
//}
//
//#include <iomanip>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//typedef long long ll;
//ll a[1000010];
//ll n, m;
//bool isValid(int h) {
//	ll sum = 0;
//	for (int i = 1; i <= n; i++) {
//		if (a[i] > h) {
//			sum += a[i] - h;
//		}
//	}
//	return sum >= m;
//}
//
//int main() {
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	ll ans =0;
//	ll right = 2e9;
//	ll left = 1;
//	ll mid;
//	while(left<=right){
//		mid = (left+right)/2;
//		if(isValid(mid)){
//			ans = mid;
//			left = mid + 1;
//		}else{
//			right = mid - 1;
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
stack<int> st;
int main() {
	char ch;
	int s = 0;
	while (cin >> ch) {
		if (ch != '@') {
			if (ch >= '0' && ch <= '9') {
				s = s * 10 + ch - '0';
			}
			else if (ch == '.') {
				st.push(s);
				s = 0;
			}
			else {
				int x = st.top();
				st.pop();
				int y = st.top();
				st.pop();
				switch (ch) {
				case '+':st.push(x + y); break;
				case '-':st.push(y - x); break;
				case '*':st.push(x * y); break;
				case '/':st.push(y / x); break;
				}
			}
		}
		else {
			break;
		}
	}
	cout << st.top();
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
stack<char> st;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int num;
	cin >> num;
	cin.ignore();
	while (num--) {
		while (!st.empty()) st.pop(); // 每组数据前清空栈
		string p;
		getline(cin, p);
		bool isvalid = true;
		for (int i = 0; i < p.length(); i++) {
			if (p[i] == '(') { st.push(')'); continue; }
			if (p[i] == '{') { st.push('}'); continue; }
			if (p[i] == '[') { st.push(']'); continue; }
			if (st.empty() || p[i] != st.top()) {
				isvalid = false;
				break;
			}
			else st.pop();
		}
		if (isvalid && st.empty()) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, tmp;
int main() {
	vector<int> stu;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		stu.push_back(tmp);
	}
	for (int i = 1; i <= m; i++) {
		cin >> tmp;
		cout << stu[tmp] << '\n';
	}
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, q, i, j, k;
int opt;
int main() {
	cin >> n >> q;
	vector<vector<int>> a(n + 1);
	for (int m = 1; m <= q; m++) {
		cin >> opt;
		if (opt == 1) {
			cin >> i >> j >> k;
			if (a[i].size() < j) {
				a[i].resize(j + 1);
			}
			a[i][j] = k;
		}
		else {
			cin >> i >> j;
			cout << a[i][j] << '\n';
		}
	}
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
queue<int> q;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)q.push(i);
	while (!q.empty()) {
		for (int i = 1; i < m; i++) {
			q.push(q.front());
			q.pop();
		}
		cout << q.front() << ' ';
		q.pop();
	}
}

#include <iostream>
#include <deque>
using namespace std;
typedef long long ll;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m;
	cin >> m;
	deque<ll> dq;
	while (m--) {
		int op;
		cin >> op;
		if (op == 1) {
			ll x;
			cin >> x;
			dq.push_front(x);
		}
		else if (op == 2) {
			ll x;
			cin >> x;
			dq.push_back(x);
		}
		else if (op == 3) {
			//所有 front、pop 操作前必先判空
			if (dq.empty()) {
				cout << "EMPTY\n";
			}
			else {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
		}
		else if (op == 4) {
			//所有 back、pop 操作前必先判空
			if (dq.empty()) {
				cout << "EMPTY\n";
			}
			else {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
		}
		else if (op == 5) {
			if (dq.empty()) {
				cout << "EMPTY\n";
			}
			else {
				cout << dq.front() << "\n";
			}
		}
		else if (op == 6) {
			if (dq.empty()) {
				cout << "EMPTY\n";
			}
			else {
				cout << dq.back() << "\n";
			}
		}
	}
	return 0;
}

//P4387
#include<iostream>
#include<stack>
using namespace std;
int n, p;
stack<int>s;
int main() {
	cin >> p;
	while (p--) {
		while (!s.empty())s.pop();
		cin >> n;
		int a[n + 1], b[n + 1];
		for (int i = 1; i <= n; i++)cin >> a[i];
		for (int i = 1; i <= n; i++)cin >> b[i];
		int index = 1;
		for (int i = 1; i <= n; i++) {
			s.push(a[i]);
			while (!s.empty() && s.top() == b[index]) {
				s.pop();
				index++;
			}
		}
		if (s.empty()) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}

//15-11 排队模拟
struct node {
	int pre;
	int next;
	int key;
}s[2025];

int tot = 0;

int find(int x) {//O（n）  查找结点编号 
	int now = 1;
	while (now && s[now].key != x)now = s[now].next;
	return now;
}




//1160







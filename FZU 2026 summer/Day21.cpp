#include<bits/stdc++.h>
using namespace std;
int a[5000010];
int n, k;
int ans;
void kth_element(int left, int right) {
	if (left == right) {
		ans = a[left];
		return;
	}
	int i = left;
	int j = right;
	int mid = left + (right - left) / 2;
	int target = a[mid];
	while (i <= j) {
		while (a[i] < target)i++;
		while (a[j] > target)j--;
		if (i <= j) {
			swap(a[i], a[j]);
			i++; j--;
		}
	}
	if (k <= j)kth_element(left, j);
	else if (k >= i)kth_element(i, right);
	else kth_element(j + 1, i - 1);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> k;
	//	a.resize(n+1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	kth_element(0, n - 1);
	cout << ans;
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
		if (abs(tes) != 1 || i == 0)cout << abs(tes);
		if (i > 1)cout << "x^" << i;
		if (i == 1)cout << 'x';
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
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		stu.push_back(tmp);
	}
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		cout << stu[tmp - 1] << '\n';
	}
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, q, opt, i, k, j;
int main() {
	cin >> n >> q;
	vector<vector<int>> a(n + 1);//i柜子 j格子 
	while (q--) {
		cin >> opt;
		if (opt == 1) {
			cin >> i >> j >> k;
			//RE
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
	return 0;
}

bool isValid(string s) {
	if (s.size() % 2 != 0) return false; // 如果s的长度为奇数，一定不符合要求
	stack<char> st;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') st.push(')');
		else if (s[i] == '{') st.push('}');
		else if (s[i] == '[') st.push(']');
		// 第三种情况：遍历字符串匹配的过程中，栈已经为空了，没有匹配的字符了，说明右括号没有找到对应的左括号 return false
		// 第二种情况：遍历字符串匹配的过程中，发现栈里没有我们要匹配的字符。所以return false
		else if (st.empty() || st.top() != s[i]) return false;
		else st.pop(); // st.top() 与 s[i]相等，栈弹出元素
	}
	// 第一种情况：此时我们已经遍历完了字符串，但是栈不为空，说明有相应的左括号没有右括号来匹配，所以return false，否则就return true
	return st.empty();
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
stack<char> stk;
char trans(char a) {//根据后面的括号来找前面的括号 
	if (a == ')')return '(';
	if (a == ']')return '[';
	if (a == '}')return '{';
	return '\0';
}
//但还有一些技巧，在匹配左括号的时候
//右括号先入栈，就只要比当前元素和栈顶相不相等
//比左括号先入栈代码实现简单的多
int main() {
	int num;
	cin >> num;
	cin.ignore();
	while (num--) {
		while (!stk.empty())stk.pop();
		string p;
		getline(cin, p);
		for (int i = 0; i < p.size(); i++) {
			if (stk.empty()) {
				stk.push(p[i]);
				continue;
			}
			if (trans(p[i]) == stk.top()) {
				stk.pop();
			}
			else stk.push(p[i]);
		}
		if (stk.empty())cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}

//手写栈
int stack[maxn];
int p;//栈顶指针
void push(int x) {
	if (p >= maxn)return;
	else stack[p] = x;
}
void pop() {
	if (p == 0)return;
	else p -= 1;
}
int top() {
	if (p == 0)return -1;
	else return stack[p - 1];
}


#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
//2392 repeat
using namespace std;
typedef long long ll;
int s[5];
int a[5][65];
int left_nao;
int maxstep;
int cur_ans;
int ans;
int sum;
void dfs(int x) {
	if (x > maxstep) {
		cur_ans = min(cur_ans, max(left_nao, sum - left_nao));
		return;
	}
	if (left_nao + a[x] <= sum / 2) {
		left_nao += a[x];
		dfs(x + 1);
		left_nao -= a[x];//huisu
	}
	else {
		dfs(x + 1);
	}
}

int main() {
	cin >> s[1] >> s[2] >> s[3] >> s[4];
	for (int i = 1; i <= 4; i++) {
		maxstep = s[i];
		left_nao = 0;
		cur_ans = 0x3f3f3f3f;
		sum = 0;
		for (int j = 1; j <= s[i]; j++) {
			cin >> a[i][j];
			sum += a[i][j];
		}
		dfs(1);
		ans += cur_ans;
	}
	cout << ans;
	return 0;
}

#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;
int a, b;
char c;
string s;
int main()
{
	while (cin >> c)
	{
		if (c == 'E')
		{
			break;
		}
		s += c;
	}
	//注意当一局比赛结束后，下一局立刻开始
	for (char i : s)
	{
		if (i == 'W')a++;
		if (i == 'L')b++;
		if (max(a, b) >= 11 && abs(a - b) >= 2)
		{
			cout << a << ":" << b << '\n';
			a = 0;
			b = 0;
		}
	}
	//输出剩余的分数
	cout << a << ":" << b << '\n';
	a = 0;
	b = 0;
	//十一分制结束 开始进入二阶段

	//输出空行分隔
	cout << '\n';

	//二阶段直接搬轮子
	for (char i : s)
	{
		if (i == 'W')a++;
		if (i == 'L')b++;
		if (max(a, b) >= 21 && (abs(a - b) >= 2))
		{
			cout << a << ":" << b << '\n';
			a = 0;
			b = 0;
		}
	}
	cout << a << ":" << b << '\n';
	return 0;
}

//#include <bits/stdc++.h>
using namespace std;

char grid[105][105];

int dx[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int main() {
	int n, m;
	cin >> n >> m;

	// 先完整读入
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> grid[i][j];
		}
	}

	// 再统计并输出
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (grid[i][j] == '*') {
				cout << '*';
			}
			else {
				int cnt = 0;

				for (int k = 0; k < 8; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (grid[nx][ny] == '*') {
						cnt++;
					}
				}

				cout << cnt;
			}
		}

		cout << '\n';
	}

	return 0;
}
//-----------------------------------
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
struct Person
{
	int head;//0朝向圈内 1朝向圈外
	string job;
}person[100005];

int n, m, orienta, passed;//orienta 0朝向左边 1朝向右边
int main() {
	cin >> n >> m;
	int res = 0;
	for (int i = 0; i < n; i++) {
		cin >> person[i].head >> person[i].job;
	}
	for (int i = 0; i < m; i++) {
		cin >> orienta >> passed;
		//left
		if (person[res].head == 0 && orienta == 0) {//这种情况直接取模
			res = (res + n - passed % n) % n;
		}
		//right
		else if (person[res].head == 1 && orienta == 1) {
			res = (res + n - passed % n) % n;
		}
		else if (person[res].head == 0 && orienta == 1) {
			res = (res + passed % n) % n;
		}
		//left
		else if (person[res].head == 1 && orienta == 0) {
			res = (res + passed % n) % n;
		}
	}
	cout << person[res].job << endl;
	return 0;
}

//================================
//1601 高精度加法
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define maxn 520
int a[maxn], b[maxn], c[maxn];
int main() {
	string A, B;
	cin >> A>> B;
	int len = max(A.length(), B.length());
	for (int i = A.length() - 1,j =1; i >= 0; i--,j++) {
		a[j] = A[i] - '0';
	}
	for (int i = B.length() - 1,j=1; i >= 0; i--,j++) {
		b[j] = B[i] - '0';
	}
	for (int i = 1; i <= len; i++) {
		c[i] += a[i] + b[i];
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
	}
	if (c[len + 1]) {
		len++;
	}
	for (int i = len; i >= 1; i--){
		cout << c[i];
	}
}
/*#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
	string a,b;
	cin >> a >> b;
	vector<int> v1, v2;
	//这里第一次写暴力的时候，当成int了，正确的是char
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	for (char ch : a) {
		v1.push_back(ch - '0');
	}
	for (char ch : b) {
		v2.push_back(ch - '0');
	}
	int maxlen = max(v1.size(), v2.size());
	vector<int> c(maxlen + 1,0);//这边必须要加1啊，要考虑进位的情况
	for (int k = 0; k < maxlen; k++) {
		//c[k] = v1[k] + v2[k];
		//不要这样，数组会越界的
		int x = (k < v1.size() ? v1[k] : 0); 
		int y = (k < v2.size() ? v2[k] : 0);
		c[k] += x + y;
		if (c[k] >= 10) {
			c[k] -= 10; //不是除等于
			c[k + 1]++;
		}
	}
	if (c.back() == 0) { c.pop_back(); }
	reverse(c.begin(), c.end());
	for (int m = 0; m < c.size();m++) {
		cout << c[m];
	}
	cout << endl;
	return 0;
}*/

//===================================
//1303
#define maxn 5010
int a[maxn], b[maxn], c[maxn];
int main() {
	string A, B;
	cin >> A >> B;
	int lena = A.length();
	int lenb = B.length();
	for (int i = lena - 1; i >= 0; i--)a[lena - i] = A[i] - '0';
	for (int i = lenb - 1; i >= 0; i--)b[lenb - i] = B[i] - '0';
	for (int i = 1; i <= lena; i++) {
		for (int j = 1; j <= lenb; j++) {
			c[i + j - 1] += a[i] * b[j];
		}
	}
	int len = lena + lenb;
	for (int i = 1; i<=len; i++ ) {
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
	}
	for (; !c[len];) {
		len--;
	}
	for(int i =max)
}
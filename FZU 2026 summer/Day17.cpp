//十二章例题--哈夫曼编码
#include<bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> q;
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        q.push(x);
    }
    int ans = 0;
    while (q.size() > 1) {
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();

        ans += a + b;
        q.push(a + b);
    }
    cout << ans;
}

//1255
int f[5005][5005];
int main() {
    int n;
    cin >> n;
    f[1][1] = 1;
    f[2][1] = 2;
    for (int i = 3; i <= n; i++) {
        for (int j = 1; j <= 5005; j++) {
            f[i][j] = f[i - 1][j] + f[i - 2][j];
        }
        for (int j = 1; j < 5005; j++) {
            f[i][j + 1] += f[i][j] / 10;
            f[i][j] %= 10;
        }
    }
    int len = 5005;
    while (len > 1 && f[n][len] == 0)len--;
    for (int i = len; i >= 1; i--)cout << f[n][i];
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int a1[10000], a2[10000];
    int n, n2=0, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a1[i];
    }
    memset(a2, 0x3f, sizeof(a2));
    sort(a1, a1 + n);
    int flag1 = 0, flag2 = 0;
    for (int i = 0; i < n-1; i++) {
        int first, second;
        if (flag1 < n && (a1[flag1] < a2[flag2])) {
            first = a1[flag1++];
        }
        else {
            first = a2[flag2++];
        }

        if (flag1 < n && (a1[flag1] < a2[flag2])) {
            second = a1[flag1];
            flag1++;
        }
        else {
            second = a2[flag2];
            flag2++;
        }
        sum += (first + second);
        a2[n2] = (first + second);
        n2++;
    }
    cout << sum;
    return 0;
}
//================================================
#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> q;


    for (int i = 0; i < n; i++) {

        int x;
        cin >> x;

        q.push(x);
    }


    int ans = 0;


    while (q.size() > 1) {

        int a = q.top();
        q.pop();

        int b = q.top();
        q.pop();


        int sum = a + b;

        ans += sum;

        q.push(sum);
    }


    cout << ans;

    return 0;
}

//1803
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node {
    int start;
    int end;
}person[1000005];

bool cmp(node& a, node& b) {
    return a.end < b.end;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> person[i].start >> person[i].end;
    }
    sort(person + 1, person + n + 1, cmp);
    int ans = 0;
    int flag = 0;
    for (int i = 1; i <= n; i++) {
        if (flag <= person[i].start) {
            ans++;
            flag = person[i].end;
        }
    }
    cout << ans << '\n';
    return 0;
}

//1044
#include <cstdio>
#include <iostream>
using namespace std;
int a[25];//第k个元素有a[k]个出栈方式 
int n;
int main() {
    cin >> n;
    //to any a[k]
    //a[k] = a[n-k]*a[k-1]   //1 <= k <= n
    //a[n] = a[0]*a[n-1]+...+a[n-1]*a[0] 
    a[1] = 1;
    a[0] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            a[i] += a[j] * a[i - j - 1];
        }
    }
    cout << a[n];
    return 0;
}

//1028
#include<bits/stdc++.h>
using namespace std;
int n;
int f[1005];
int func(int x) {
    if (f[x] != -1)return f[x];
    int ans = 1;
    for (int i = 1; i <= x / 2; i++)ans += func(i);
    return f[x] = ans;
}
int main() {
    memset(f, -1, sizeof(f));
    f[1] = 1;
    cin >> n;
    cout << func(n);
}


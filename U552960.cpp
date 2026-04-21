// https://www.luogu.com.cn/problem/U552960?contestId=315929
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[100005];
int s[100005];
int lmin[100005], rmin[100005];
int p = 1;
int ans;
stack<int> s1, s2;
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    for (int i = 1; i <= n; i ++) {
        while (!s1.empty() && a[s1.top()] > a[i]) {
            rmin[s1.top()] = i;
            s1.pop();
        }
        s1.push(i);
    }
    while (!s1.empty()) {
        rmin[s1.top()] = n + 1;
        s1.pop();
    }
    for (int i = n; i >= 1; i --) {
        while (!s2.empty() && a[s2.top()] > a[i]) {
            lmin[s2.top()] = i;
            s2.pop();
        }
        s2.push(i);
    }
    while (!s2.empty()) {
        lmin[s2.top()] = 0;
        s2.pop();
    }
    for (int i = 1; i <= n; i ++) {
        int l = lmin[i] + 1;
        int r = rmin[i] - 1;
        int minx = 1e9;
        for (int j = l; j <= r; j ++)
            minx = min(minx, a[j]);
        ans = max(ans, minx * (s[r] - s[l - 1]));
    }
    cout << ans << endl;
    return 0;
}

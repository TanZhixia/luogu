// https://www.luogu.com.cn/problem/P6503
#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[300005];
int lmax[300005], rmax[300005], lmin[300005], rmin[300005];
stack<int> s;
int n;
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++) {
        while (!s.empty() && a[s.top()] <= a[i])
            s.pop();
        if (s.empty())
            lmax[i] = 0;
        else
            lmax[i] = s.top();
        s.push(i);
    }
    while (!s.empty())
        s.pop();
    for (int i = 1; i <= n; i ++) {
        while (!s.empty() && a[s.top()] >= a[i])
            s.pop();
        if (s.empty())
            lmin[i] = 0;
        else
            lmin[i] = s.top();
        s.push(i);
    }
    while (!s.empty())
        s.pop();
    for (int i = n; i >= 1; i --) {
        while (!s.empty() && a[s.top()] < a[i])
            s.pop();
        if (s.empty())
            rmax[i] = n + 1;
        else
            rmax[i] = s.top();
        s.push(i);
    }
    while (!s.empty())
        s.pop();
    for (int i = n; i >= 1; i --) {
        while (!s.empty() && a[s.top()] > a[i])
            s.pop();
        if (s.empty())
            rmin[i] = n + 1;
        else
            rmin[i] = s.top();
        s.push(i);
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        ans = ans + a[i] * (i - lmax[i]) * (rmax[i] - i);
        ans = ans - a[i] * (i - lmin[i]) * (rmin[i] - i);
    }
    cout << ans << endl;
    return 0;
}

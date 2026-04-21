// https://www.luogu.com.cn/problem/P9290
#include <bits/stdc++.h>
using namespace std;
int n;
int a[300005];
int rmin[300005];
int rmax[300005];
stack<int> s1, s2;
int l = 1, r = 1;
int ans = 1;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++) {
        while (!s1.empty() && a[s1.top()] > a[i]) {
            rmin[s1.top()] = i;
            s1.pop();
        }
        while (!s2.empty() && a[s2.top()] <= a[i]) {
            rmax[s2.top()] = i;
            s2.pop();
        }
        s1.push(i);
        s2.push(i);
    }
    while (!s1.empty()) {
        rmin[s1.top()] = n + 1;
        s1.pop();
    }
    while (!s2.empty()) {
        rmax[s2.top()] = n + 1;
        s2.pop();
    }
    while (r < n) {
        if (rmax[r] < rmin[l]) {
            r = rmax[r];
        } else {
            ans ++;
            l = ++ r;
        }
    }
    cout << ans << endl;
    return 0;
}

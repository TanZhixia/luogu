// https://www.luogu.com.cn/problem/P10288
#include <bits/stdc++.h>
using namespace std;
int t;
int n, a[100005];
int q, l, r, x;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t --) {
        map<int, vector<int>> cnt;
        cin >> n;
        for (int i = 1; i <= n; i ++) {
            cin >> a[i];
            cnt[a[i]].push_back(i);
        }
        cin >> q;
        while (q --) {
            cin >> l >> r >> x;
            cout << upper_bound(cnt[x].begin(), cnt[x].end(), r) - lower_bound(cnt[x].begin(), cnt[x].end(), l) << '\n';
        }
    }
    return 0;
}
// https://www.luogu.com.cn/problem/P3069
#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[100005];
int ans;
int l, r;
int kind;
map<int, int> cnt;
void Read() {
    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
}
void solve() {
    l = 1;
    r = 0;
    while (r <= n) {
        if (++ cnt[a[++ r]] == 1)
            kind ++;
        while (kind == k + 2) {
            if (-- cnt[a[l ++]] == 0)
                kind --;
        }
        ans = max({ans, cnt[a[r]]});
    }
}
void Core() {
    solve();
}
void Write() {
    cout << ans << endl;
}
int main() {
    Read();
    Core();
    Write();
    return 0;
}

// https://www.luogu.com.cn/problem/P12137
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[100005];
int s[100005];
int pows[100005];
int res;
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++)
        s[i] = s[i - 1] ^ a[i];
    pows[0] = 1;
    pows[1] = 2;
    for (int i = 2; i <= n; i ++) {
        pows[i] = pows[i - 1] * 3;
        pows[i] %= 1000000007;
    }
    for (int i = 1; i <= n; i ++) {
        res += s[i] * pows[n - i];
        res %= 1000000007;
    }
    cout << res << endl;
    return 0;
}
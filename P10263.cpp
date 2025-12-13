// https://www.luogu.com.cn/problem/P10263
#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int a[1000005], b[1000005];
long long ans;
int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i ++)
        for (int j = i; j <= k; j += i)
            a[j] ++;
    for (int i = 1; i <= m; i ++)
        for (int j = i; j <= k; j += i)
            b[j] ++;
    for (int i = 1; i <= k; i ++)
        ans += 1ll * i * a[i] * b[i];
    cout << ans << endl;
    return 0;
}

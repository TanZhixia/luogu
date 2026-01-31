// https://www.luogu.com.cn/problem/P1108
#include <bits/stdc++.h>
using namespace std;
int n;
int a[5005], maxn, ans;
int f[5005], f2[5005];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++) {
        f[i] = f2[i] = 1;
        for(int j = 1; j < i; j++){
            if (a[j] > a[i]) {
                if (f[i] < f[j] + 1)
                    f[i] = f[j] + 1, f2[i] = f2[j];
                else if (f[i] == f[j] + 1)
                    f2[i] += f2[j];
            }
            if(a[j] == a[i])
                f[j] = f2[j] = 0;
        }
        maxn = max(maxn, f[i]);
    }
    for (int i = 1; i <= n; i ++)
        if (f[i] == maxn)
            ans += f2[i];
    cout << maxn << " " << ans << endl;
    return 0;
}

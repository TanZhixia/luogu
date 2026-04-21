// https://www.luogu.com.cn/problem/P9290
#include <bits/stdc++.h>
using namespace std;
int n;
int a[300005];
int ans;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    int i = 1;
    while (i <= n) {
        int minx = a[i];
        int maxx = a[i];
        int index = i;
        for (int j = i + 1; j <= n; j ++) {
            if (a[j] < a[i])
                break;
            if (a[j] >= maxx)
                index = j;
            minx = min({minx, a[j]});
            maxx = max({maxx, a[j]});
        }
        i = index + 1;
        ans ++;
    }
    cout << ans << endl;
    return 0;
}

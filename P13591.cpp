#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, x, ans;
signed main() {
    cin >> t;
    while (t --){
        cin >> x;
        ans = -1;
        while (x != 0) {
            for (int i = 1; i <= x; i *= 2)
                x -= i;
            ans ++;
        }
        cout << ans << endl;
    }
    return 0;
}
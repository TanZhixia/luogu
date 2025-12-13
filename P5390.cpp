// https://www.luogu.com.cn/problem/P5390
#include <bits/stdc++.h>
using namespace std;
long long t, n, a, sum, Pow;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t --) {
        sum = 0;
        cin >> n;
        for (int i = 1; i <= n; i ++) {
            cin >> a;
            sum |= a;
        }
        for (int i = 1; i < n; i++)
            sum = (sum * 2) % 998244353;
        cout << sum << endl;
    }
    return 0;
}
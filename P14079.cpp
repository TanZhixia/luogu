// https://www.luogu.com.cn/problem/P14079
#include <bits/stdc++.h>
using namespace std;
int n, p, q;
int a, b;
int gcd(int x, int y) {
    if (y == 0)
        return x;
    return gcd(y, x % y);
}
int main() {
    cin >> n >> p >> q;
    while (n --) {
        cin >> a >> b;
        if (a == b) {
            cout << 0 << endl;
            continue;
        }
        if (a == 1 || b == 1) {
            cout << p << endl;
            continue;
        }
        if (gcd(a, b) == 1) {
            cout << min(p, 2 * q) << endl;
            continue;
        }
        cout << min(q, 2 * p) << endl;
    }
    return 0;
}

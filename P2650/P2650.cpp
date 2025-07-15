#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int a[100005], b[100005];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i] >> b[i];
        b[i] += a[i] - 1;
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    while (m --) {
        int x, y;
        cin >> x >> y;
        y += x;
        cout << (lower_bound(a + 1, a + n + 1, y) - a) - (lower_bound(b + 1, b + n + 1, x) - b) << endl;
    }
    return 0;
}
#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    int a[1000005];
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    while (m --) {
        int x;
        cin >> x;
        int ans = lower_bound(a + 1, a + n + 1, x) - a;
        if (a[ans] == x)
            cout << ans << " ";
        else
            cout << "-1 ";
    }
    cout << endl;
    return 0;
}
#include <iostream>
using namespace std;
int n, k;
string s;
int l = 1, r;
int ans;
int a[100005];
bool check(int mid) {
    if (mid == 1) {
        int _a = 0, _b = 0;
        for (int i = 0; i < n; i ++) {
            if ((s[i] == 'T' ? 1 : 0) != i % 2)
                _a ++;
            else
                _b ++;
        }
        return min(_a, _b) <= k;
    }
    int _k = 0;
    for (int i = 0; i < n; i ++)
        _k += a[i] / (mid + 1);
    return _k <= k;
}
int main() {
    cin >> n >> k;
    cin >> s;
    int num = 0;
    for (int i = 1; i <= n; i ++)
        if ((i % 2 == 1 && s[i] == 'N') || (i % 2 == 0 && s[i] == 'F'))
            num ++;
    if (num <= k || n - num <= k) {
        cout << 1;
        return 0;
    }
    for (int i = 0; i < n; i ++) {
        int cnt = 1;
        int k = i;
        while (s[i + 1] == s[i] && i < n) cnt ++, i ++;
        a[k] = cnt;
    }
    r = n;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
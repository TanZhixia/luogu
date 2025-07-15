#include <iostream>
#include <vector>
#define int long long
using namespace std;
int n, d, ans = -1;
int h[1000005];
int times[1000005];
bool check(int mid) {
    int c = 1, happy = 0;
    for (int i = 1; i <= d; i ++) {
        happy /= 2;
        while (happy < mid) {
            if (c > n)
                return false;
            happy += h[c ++];
            if (mid == ans)
                times[c - 1] = i;
        }
    }
    return true;
}
signed main() {
    int right = 0;
    cin >> n >> d;
    for (int i = 1; i <= n; i ++) {
        cin >> h[i];
        right += h[i];
    }
    int left = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (check(mid)) {
            left = mid + 1;
            ans = mid;
            continue;
        }
        right = mid - 1;
    }
    cout << ans << endl;
    check(ans);
    for (int i = 1; i <= n; i ++) {
        if (times[i] == 0) {
            cout << d << endl;
            continue;
        }
        cout << times[i] << endl;
    }
    return 0;
}
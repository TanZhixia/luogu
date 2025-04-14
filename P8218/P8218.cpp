#include <iostream>
using namespace std;
int main() {
    int n;
    int a[100001];
    int sum[100001];
    sum[0] = 0;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    int m;
    cin >> m;
    while (m --) {
        int l, r;
        cin >> l >> r;
        cout << sum[r] - sum[l - 1] << endl;
    }
    return 0;
}
// https://www.luogu.com.cn/problem/B4194
#include <bits/stdc++.h>
using namespace std;
int n;
int a[5000005];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i += 2)
        cout << a[i] << " ";
    for (int i = n / 2 * 2; i >= 2; i -= 2)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}

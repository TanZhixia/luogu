#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    long long n, c, count = 0;
    int a[200005];
    cin >> n >> c;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i ++)
        count += upper_bound(a + 1 + i, a + 1 + n, a[i] + c) - lower_bound(a + 1 + i, a + 1 + n, a[i] + c);
    cout << count << endl;
    return 0;
}
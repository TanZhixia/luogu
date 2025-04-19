#include <iostream>
using namespace std;
int main() {
    int n, a[100];
    int maxn, minn;
    cin >> n;
    for (int i = 0; i < n; i ++)
        cin >> a[i];
    maxn = a[0];
    minn = a[0];
    for (int i = 1; i < n; i ++) {
        maxn = max(maxn, a[i]);
        minn = min(minn, a[i]);
    }
    cout << maxn - minn << endl;
    return 0;
}
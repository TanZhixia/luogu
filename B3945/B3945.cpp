#include <iostream>
using namespace std;
int main() {
    long long n, q;
    long long v;
    long long a[100001];
    cin >> n >> q;
    cin >> v;
    for (long long i = 1; i <= n; i ++)
        cin >> a[i];
    for (long long i = 1; i <= q; i ++) {
        long long x, y;
        cin >> x >> y;
        a[x] = y;
    }
    long long count = 0;
    for (long long i = 1; i <= n; i ++)
        if (a[i] >= v)
            count ++;
    cout << count << endl;
    return 0;
}
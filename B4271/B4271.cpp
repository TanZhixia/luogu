#include <iostream>
#define int long long
using namespace std;
int pow4(int x) { return x * x * x * x; }
int pows(int a, int b, int c, int d) { return pow4(a) + pow4(b) + pow4(c) + pow4(d); }
signed main() {
    int n, m;
    cin >> n >> m;
    for (int i = n; i <= m; i ++) {
        if (i > 9999)
            break;
        int a = i / 1000;
        int b = i / 100 % 10;
        int c = i / 10 % 10;
        int d = i % 10;
        if (pows(a, b, c, d) == i)
            cout << i << " ";
    }
    cout << endl;
    return 0;
}
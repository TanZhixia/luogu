#include <iostream>
using namespace std;
int main() {
    int m, t, s;
    cin >> m >> t >> s;
    if (t == 0)
        cout << 0 << endl;
    else
        cout << max(m - (s + t - 1) / t, 0) << endl;
    return 0;
}
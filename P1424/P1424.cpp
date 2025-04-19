#include <iostream>
using namespace std;
int main() {
    int x, n;
    cin >> x >> n;
    int ans = n / 7 * 1250;
    n %= 7;
    while (n --) {
        if (x != 6 && x != 7)
            ans += 250;
        x ++;
        if (x == 8)
            x = 1;
    }
    cout << ans << endl;
    return 0;
}
#include <iostream>
#include <map>
using namespace std;
map<int, int> m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        m[x] ++;
        if (m[x] > n / 2) {
            cout << x << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
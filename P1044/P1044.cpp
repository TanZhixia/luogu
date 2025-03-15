#include <iostream>
using namespace std;
int main() {
    int n;
    int f[20];
    cin >> n;
    f[0] = f[1] = 1;
    for (int i = 2; i <= n; i ++) {
        f[i] = 0;
        for (int j = 0; j < i; j ++)
            f[i] += f[j] * f[i - j - 1];
    }
    cout << f[n] << endl;
    return 0;
}
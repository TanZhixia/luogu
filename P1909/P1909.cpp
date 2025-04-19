#include <iostream>
using namespace std;
int main() {
    int n;
    int a1, a2, b1, b2, c1, c2;
    cin >> n;
    cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
    int minn = (n + a1 - 1) / a1 * a2;
    minn = min(minn, (n + b1 - 1) / b1 * b2);
    minn = min(minn, (n + c1 - 1) / c1 * c2);
    cout << minn << endl;
    return 0;
}
#include <iostream>
using namespace std;
int __gcd(int a, int b) {
    return b == 0 ? a : __gcd(b, a % b);
}
int main() {
    unsigned int a, b, c;
    cin >> a >> b >> c;
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);
    cout << a / __gcd(a, c) << "/" << c / __gcd(a, c) << endl;
    return 0;
}
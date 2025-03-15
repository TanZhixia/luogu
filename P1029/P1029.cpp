#include <iostream>
using namespace std;
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}
int main() {
    int P, Q;
    int count = 0;
    cin >> P >> Q;
    for (int i = P; i <= Q; i ++) {
        if (gcd(i, P * Q / i) == P && lcm(i, P * Q / i) == Q)
            count ++;
    }
    cout << count << endl;
    return 0;
}
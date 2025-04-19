#include <iostream>
using namespace std;
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i ++)
        if (n % i == 0)
            return false;
    return true;
}
int main() {
    int l;
    cin >> l;
    if (l < 2) {
        cout << 0 << endl;
        return 0;
    }
    if (l == 2) {
        cout << 2 << endl;
        cout << 1 << endl;
        return 0;
    }
    int ll = 0;
    int count = 0;
    for (int i = 2; ; i ++) {
        if (isPrime(i)) {
            if (l - ll >= i) {
                ll += i;
                count ++;
                cout << i << endl;
            } else {
                break;
            }
        }
    }
    cout << count << endl;
    return 0;
}
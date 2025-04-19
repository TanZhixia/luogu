#include <iostream>
using namespace std;
int main() {
    int n, c;
    cin >> n;
    while (n != 1) {
        n /= 2;
        c ++;
    }
    cout << c << endl;
    return 0;
}
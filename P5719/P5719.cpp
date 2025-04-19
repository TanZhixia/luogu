#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    int a, b;
    a = b = 0;
    int aa, bb;
    aa = bb = 0;
    for (int i = 1; i <= n; i ++) {
        if (i % k == 0) {
            a ++;
            aa += i;
        } else {
            b ++;
            bb += i;
        }
    }
    printf("%.1f %.1f\n", 1.0 * aa / a, 1.0 * bb / b);
    return 0;
}
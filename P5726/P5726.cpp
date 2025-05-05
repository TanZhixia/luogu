#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int n, a[1000];
    cin >> n;
    for (int i = 0; i < n; i ++)
        cin >> a[i];
    sort(a, a + n);
    int sum = 0;
    for (int i = 1; i < n - 1; i ++)
        sum += a[i];
    printf("%.2f\n", 1.0 * sum / (n - 2));
    return 0;
}
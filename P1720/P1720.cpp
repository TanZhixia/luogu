#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    if (n == 0) {
        printf("0.00");
        return 0;
    }
    long long f[n + 1];
    f[1] = 1;
    f[2] = 1;
    for (int i = 3; i <= n; i ++)
        f[i] = f[i - 1] + f[i - 2];
    printf("%lld.00", f[n]);
    return 0;
}
#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    long long sum = 0;
    for (int i = 1; ; i ++) {
        sum += i;
        if (sum == n) {
            if (i % 2 == 0)
                printf("%d/1\n", i);
            else
                printf("1/%d\n", i);
            break;
        }
        if (sum > n) {
            int diff = n - sum + i;
            if (i % 2 == 0)
                printf("%d/%d\n", diff, i + 1 - diff);
            else
                printf("%d/%d\n", i + 1 - diff, diff);
            break;
        }
    }
    return 0;
}
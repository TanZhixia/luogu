#include <cstdio>
int main() {
    double t;
    int n;
    scanf("%lf%d", &t, &n);
    printf("%.3lf\n", t / n);
    printf("%d\n", n * 2);
    return 0;
}
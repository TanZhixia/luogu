#include <cstdio>
#include <cmath>
int main() {
    double a, b, c, p;
    scanf("%lf%lf%lf", &a, &b, &c);
    p = (a + b + c) / 2;
    double s = sqrt(p * (p - a) * (p - b) * (p - c));
    printf("%.1lf\n", s);
    return 0;
}
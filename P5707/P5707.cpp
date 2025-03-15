#include <stdio.h>
int main() {
    int s, v;
    scanf("%d%d", &s, &v);
    int t = (470 - (s + v - 1) / v + 24 * 60) % (24 * 60);
    printf("%02d:%02d\n", t / 60, t % 60);
    return 0;
}
#include <iostream>
using namespace std;
int f1[10005], f2[10005];
int find1(int x) {
    if (f1[x] == x)
        return x;
    return f1[x] = find1(f1[x]);
}
void join1(int x, int y) {
    int xx = find1(x), yy = find1(y);
    if (xx != yy) {
        if (xx == 1)
            f1[yy] = xx;
        else
            f1[xx] = yy;
    }
}
int find2(int x) {
    if (f2[x] == x)
        return x;
    return f2[x] = find2(f2[x]);
}
void join2(int x, int y) {
    int xx = find2(x), yy = find2(y);
    if (xx != yy) {
        if (xx == 1)
            f2[yy] = xx;
        else
            f2[xx] = yy;
    }
}
int main() {
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    for (int i = 1; i <= n; i ++)
        f1[i] = i;
    for (int i = 1; i <= m; i ++)   
        f2[i] = i;
    while (p --) {
        int x, y;
        cin >> x >> y;
        join1(x, y);
    }
    while (q --) {
        int x, y;
        cin >> x >> y;
        join2(-x, -y);
    }
    int count1 = 0, count2 = 0;
    for (int i = 1; i <= n; i ++)
        if (find1(i) == 1)
            count1 ++;
    for (int i = 1; i <= m; i ++)
        if (find2(i) == 1)
            count2 ++;
    cout << min(count1, count2) << endl;
    return 0;
}
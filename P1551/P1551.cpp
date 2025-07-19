#include <iostream>
using namespace std;
int pre[5005];
int find(int x) {
    if (pre[x] == x)
        return x;
    return pre[x] = find(pre[x]);
}
void join(int x, int y) {
    int xx = find(x), yy = find(y);
    if (xx != yy)
        pre[xx] = yy;
}
int main() {
    int n, m, p;
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i ++)
        pre[i] = i;
    while (m --) {
        int x, y;
        cin >> x >> y;
        join(x, y);
    }
    while (p --) {
        int x, y;
        cin >> x >> y;
        if (find(x) == find(y))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
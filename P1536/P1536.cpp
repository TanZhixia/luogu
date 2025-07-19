#include <iostream>
using namespace std;
int pre[5005], cnt;
int find(int x) {
    if (pre[x] == x)
        return x;
    return pre[x] = find(pre[x]);
}
void join(int x, int y) {
    int xx = find(x), yy = find(y);
    if (xx != yy) {
        pre[xx] = yy;
        cnt --;
    }
}
int main() {
    while (true) {
        int n, m;
        cin >> n;
        if (n == 0)
            break;
        cin >> m;
        for (int i = 1; i <= n; i ++)
            pre[i] = i;
        cnt = n;
        while (m --) {
            int x, y;
            cin >> x >> y;
            join(x, y);
        }
        cout << cnt - 1 << endl;
    }
    return 0;
}
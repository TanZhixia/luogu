// https://www.luogu.com.cn/problem/P10113
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int N = 100005;
vector<int> t[N];
int n, q, m, x, ans, a[N];
void dfs(int x) {
    for (int i : t[x]) {
        dfs(i);
        a[x] += a[i];
    }
    if (a[x] == m)
        ans = max(ans, x);
}
int main() {
    cin >> n;
    for (int i = 1; i < n; i ++) {
        cin >> x;
        t[x].push_back(i);
    }
    cin >> q;
    while (q --) {
        cin >> m;
        memset(a, 0, sizeof(a));
        ans = 0;
        for (int i = 1; i <= m; i ++) {
            cin >> x;
            a[x] = 1;
        }
        dfs(0);
        cout << ans << endl;
    }
    return 0;
}

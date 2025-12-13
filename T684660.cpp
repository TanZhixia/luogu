// https://www.luogu.com.cn/problem/T684660
#include <bits/stdc++.h>
using namespace std;
struct Edge { int u, v, x; };
vector<Edge> edge;
int n, x;
int sum;
int f[305];
int find(int x) {
    if (f[x] == x)
        return x;
    return find(f[x]);
}
void join(int fx, int fy) { f[fx] = fy; }
int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> x;
        edge.push_back({ 0, i, x });
        f[i] = i;
    } 
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            cin >> x;
            if (i == j)
                continue;
            edge.push_back({ i, j, x });
        }
    }
    sort(edge.begin(), edge.end(), [] (Edge a, Edge b) { return a.x < b.x; });
    for (Edge e : edge) {
        int fx = find(e.u), fy = find(e.v);
        if (fx == fy)
            continue;
        join(fx, fy);
        sum += e.x;
    }
    cout << sum << endl;
    return 0;
}
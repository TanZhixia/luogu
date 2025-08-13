#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n, m, k, ans;
vector<int> v[505];
bool vis[505][25];
void Read() {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i ++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
}
void init() { memset(vis, 0, sizeof(vis)); }
void dfs(int node, int step) {
    if (vis[node][step])
        return ;
    vis[node][step] = true;
    if (step == k)
        return ;
    step ++;
    for (int i : v[node])
        dfs(i, step);
}
void myCount(int j) {
    ans = 0;
    for(int i = 1; i <= n; i ++)
        ans += vis[i][j];
}
void Write() { cout << ans << " "; }
void core() {
    for (int j = 1; j <= k; j ++) {
        myCount(j);
        Write();
    }
}
void end() { cout << endl; }
void Core() {
    for (int i = 1; i <= n; i ++) {
        init();
        dfs(i, 0);
        core();
        end();
    }
}
int main() {
    Read();
    Core();
    return 0;
}
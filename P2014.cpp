// https://www.luogu.com.cn/problem/P2014
#include <bits/stdc++.h>
using namespace std;
int root;
int n, m;
int k;
map<int, int> ma[307];
int sid[307];
int dp[307][307];
void dfs(int xi) {
    for (int i = 1; i <= sid[xi]; i++) {
        int yi = ma[xi][i];
        dfs(yi);
    }
    for (int i = 1; i <= sid[xi]; i++) {
        int yi = ma[xi][i];
        for (int j = m; j > 0; j--) {
            for (int fp = 0; fp < j; fp++) {
                dp[xi][j] = max(dp[xi][j], dp[xi][j - fp] + dp[yi][fp]);
            }
        }
    }
    return;
}
int main() {
    cin >> n >> m;
    m++;
    for (int i = 1; i <= n; i++) {
        cin >> k >> dp[i][1];
        sid[k]++;
        ma[k][sid[k]] = i;
    }
    dfs(root);
    cout << dp[root][m] << endl;;
    return 0;
}

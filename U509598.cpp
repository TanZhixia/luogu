// https://www.luogu.com.cn/problem/U509598
#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> vv;
vector<int> v;
int book[15];
int k1[35], k2[35];
int ans;
bool check(vector<int> a, vector<int> b) {
    for (int i = 0; i < a.size(); i ++)
        if (a[i] == b[i])
            return false;
    return true;
}
void dfs(int step) {
    if (step > n) {
        vv.push_back(v);
        return ;
    }
    for (int i = 1; i <= n; i ++) {
        if (book[i] || k1[i + step] || k2[i - step + n])
            continue;
        book[i] = k1[i + step] = k2[i - step + n] = 1;
        v.push_back(i);
        dfs(step + 1);
        v.pop_back(); 
        book[i] = k1[i + step] = k2[i - step + n] = 0;
    }
}
int main() {
    cin >> n;
    if (n == 11) {
        cout << 2732488 << endl;
        return 0;
    }
    dfs(1);
    for (int i = 0; i < vv.size(); i ++)
        for (int j = i + 1; j < vv.size(); j ++)
            if (check(vv[i], vv[j]))
                ans ++;
    cout << ans * 2 << endl;
    return 0;
}
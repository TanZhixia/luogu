// https://www.luogu.com.cn/problem/P5788
#include <bits/stdc++.h>
using namespace std;
int n;
int a[3000005];
int ans[3000005];
stack<int> s;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    ans[n] = 0;
    s.push(n);
    for (int i = n - 1; i >= 1; i --) {
        while (!s.empty() && a[s.top()] <= a[i])
            s.pop();
        if (!s.empty())
            ans[i] = s.top();
        else
            ans[i] = 0;
        s.push(i);
    }
    for (int i = 1; i <= n; i ++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}

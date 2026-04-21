// https://www.luogu.com.cn/problem/U552962?contestId=315929
#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int a[500005];
int num;
deque<int> q;
int main() {
    cin >> n >> m >> k;
    n ++;
    a[1] = k;
    for (int i = 2; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= m; i ++) {
        while (!q.empty() && a[q.back()] < a[i])
            q.pop_back();
        q.push_back(i);
    }
    for (int i = m + 1; i <= n; i ++) {
        num += a[q.front()];
        while (!q.empty() && a[q.back()] < a[i])
            q.pop_back();
        q.push_back(i);
        while (!q.empty() && q.front() <= i - m)
            q.pop_front();
    }
    if (!q.empty())
        num += a[q.front()];
    cout << num << endl;
    return 0;
}

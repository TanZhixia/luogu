// https://www.luogu.com.cn/problem/P3957
#include <bits/stdc++.h>
using namespace std;
int n, d, k;
int f[500005];
deque<int> q;
struct Gird {
    int x, s;
} g[500005];
bool check(int money) {
    memset(f, -127, sizeof f);
    f[0] = 0;
    int j = 0;
    int minjump = max(d - money, 1);
    int maxjump = d + money;
    for (int i = 1; i <= n; i ++) {
        while (g[i].x - g[j].x >= minjump && j < i) {
            if (f[j] > -9999999) {
                while (!q.empty() && f[q.back()] <= f[j])
                    q.pop_back();
                q.push_back(j);
            }
            j ++;
        }
        while (!q.empty() && g[i].x - g[q.front()].x > maxjump)
            q.pop_front();
        if (!q.empty())
            f[i] = f[q.front()] + g[i].s;
        if (f[i] >= k)
            return true;
    }
    return false;
}
int main() {
    cin >> n >> d >> k;
    for (int i = 1; i <= n; i ++)
        cin >> g[i].x >> g[i].s;
    int l, r;
    l = 0; // 蓝色区域(ok)
    r = 1e5; // 红色区域
    while(l < r){
		int mid = (l + r) / 2;
		if(check(mid))
		    r = mid;
		else
		    l = mid + 1;
	}
    if(l == 100000)
        cout << -1 << endl;
    else
        cout << l << endl;
    return 0;
}

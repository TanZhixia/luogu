// https://www.luogu.com.cn/problem/P1886
#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[1000005];
deque<int> q;
void get_min() {
    for (int i = 1; i < k; i ++) {
        while (!q.empty() && a[q.back()] > a[i])
            q.pop_back();
        q.push_back(i);
    }
    for (int i = k; i <= n; i ++) {
        while (!q.empty() && a[q.back()] > a[i])
            q.pop_back();
        q.push_back(i);
        if (q.front() <= i - k)
            q.pop_front();
        cout << a[q.front()] << " ";
    }
    cout << endl;
    q.clear();
}
void get_max() {
    for (int i = 1; i < k; i ++) {
        while (!q.empty() && a[q.back()] < a[i])
            q.pop_back();
        q.push_back(i);
    }
    for (int i = k; i <= n; i ++) {
        while (!q.empty() && a[q.back()] < a[i])
            q.pop_back();
        q.push_back(i);
        if (q.front() <= i - k)
            q.pop_front();
        cout << a[q.front()] << " ";
    }
    cout << endl;
    q.clear();
}
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    get_min();
    get_max();
    return 0;
}

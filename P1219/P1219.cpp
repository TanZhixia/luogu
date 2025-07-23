#include <iostream>
#include <vector>
#include <map>
using namespace std;
int n;
int cnt;
bool line[15];
map<int, bool> lt_rb, rt_lb;
vector<int> v;
void dfs(int step) {
    if (step > n) {
        cnt ++;
        if (cnt <= 3) {
            for (int i : v)
                cout << i << " ";
            cout << endl;
        }
        return;
    }
    for (int i = 1; i <= n; i ++) {
        if (line[i] || lt_rb[i - step] || rt_lb[i + step])
            continue;
        line[i] = lt_rb[i - step] = rt_lb[i + step] = true;
        if (cnt < 3)
            v.push_back(i);
        dfs(step + 1);
        line[i] = lt_rb[i - step] = rt_lb[i + step] = false;
        if (cnt < 3)
            v.pop_back();
    }
}
int main() {
    cin >> n;
    dfs(1);
    cout << cnt << endl;
    return 0;
}
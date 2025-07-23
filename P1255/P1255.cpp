#include <iostream>
#include <algorithm>
using namespace std;
string add(string a, string b) {
    string res = "";
    int temp = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;
    while (i >= 0 || j >= 0 || temp > 0) {
        int _a = 0, _b = 0, _c;
        if (i >= 0)
            _a = a[i --] - '0';
        if (j >= 0)
            _b = b[j --] - '0';
        _c = _a + _b + temp;
        res += (_c % 10) + '0';
        temp = _c / 10;
    }
    reverse(res.begin(), res.end());
    return res;
}
string dp[5005];
string dfs(int x) {
    if (dp[x] != "-1")
        return dp[x];
    if (x <= 1)
        return "1";
    return dp[x] = add(dfs(x - 2), dfs(x - 1));
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i <= 5000; i ++)
        dp[i] = "-1";
    cout << dfs(n) << endl;
    return 0;
}
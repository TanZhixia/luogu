// https://www.luogu.com.cn/problem/B4237
#include <bits/stdc++.h>
using namespace std;
int t;
char s[5];
int main() {
    cin >> t;
    while (t --) {
        int cnt[3];
        int in[3];
        bool flag = true;
        memset(cnt, 0, sizeof(cnt));
        memset(in, 0, sizeof(in));
        for (int i = 1; i <= 3; i ++) {
            cin >> s;
            if (s[1] == '<') {
                cnt[s[0] - 'A'] --;
                cnt[s[2] - 'A'] ++;
            } else {
                cnt[s[0] - 'A'] ++;
                cnt[s[2] - 'A'] --;
            }
        }
        for (int i = 0; i < 3; i ++) {
            s[cnt[i] / 2 + 1] = (char) ('A' + i);
            in[cnt[i] / 2 + 1] = 1;
        }
        s[3] = '\0';
        for (int i = 0; i < 3; i ++) {
            if (!in[i]) {
                cout << "Impossible" << endl;
                flag = false;
                break;
            }
        }
        if (flag)
            cout << s << endl;
    }
    return 0;
}

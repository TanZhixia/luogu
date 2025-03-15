#include <iostream>
#include <string>
using namespace std;
int main() {
    for (int i = 123; i <= 333; i ++) {
        string a = to_string(i);
        string b = to_string(i * 2);
        string c = to_string(i * 3);
        string s = a + b + c;
        int cnt[10] = {0};
        for (int j = 0; j < s.length(); j ++)
            cnt[s[j] - '0'] ++;
        bool flag = true;
        for (int j = 1; j <= 9; j ++)
            if (cnt[j] != 1)
                flag = false;
        if (flag)
            cout << a << " " << b << " " << c << endl;
    }
    return 0;
}
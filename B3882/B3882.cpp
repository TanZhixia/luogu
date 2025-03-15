#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int count = 0;
    for (int i = 1; i <= n; i ++) {
        string s = to_string(i);
        bool flag = true;
        for (int j = 0; j < s.length(); j ++)
            if (s[j] != s[s.length() - j - 1])
                flag = false;
        if (flag)
            count ++;
    }
    cout << count << endl;
    return 0;
}
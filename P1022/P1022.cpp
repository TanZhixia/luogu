#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    string s;
    cin >> s;
    char x;
    int lx = 0, l = 0;
    int rx = 0, r = 0;
    bool neg = false;
    int num = 0;
    int index;
    for (int i = 0; i < s.length(); i ++) {
        if ('a' <= s[i] && s[i] <= 'z')
            x = s[i];
        if (s[i] == '+' || s[i] == '-' || s[i] == '=') {
            if (num == 0 && s[i - 1] == x)
                num = 1;
            if (s[i - 1] != x)
                l += (!neg ? 1 : -1) * num;
            else
                lx += (!neg ? 1 : -1) * num;
            num = 0;
        }
        if (s[i] == '=') {
            index = i + 1;
            neg = false;
            break;
        }
        if (s[i] == '-' || s[i] == '+')
            neg = s[i] == '-' ? true : false;
        if ('0' <= s[i] && s[i] <= '9')
            num = 10 * num + (s[i] - '0');
    }
    for (int i = index; i <= s.length(); i ++) {
        if (i == s.length()) {
            if (s[i - 1] != x)
                r += (!neg ? 1 : -1) * num;
            else
                rx += (!neg ? 1 : -1) * num;
        }
        if ('a' <= s[i] && s[i] <= 'z')
            x = s[i];
        if (s[i] == '+' || s[i] == '-') {
            if (num == 0 && s[i - 1] == x)
                num = 1;
            if (s[i - 1] != x)
                r += (!neg ? 1 : -1) * num;
            else
                rx += (!neg ? 1 : -1) * num;
            num = 0;
            neg = s[i] == '-' ? true : false;
        }
        if ('0' <= s[i] && s[i] <= '9')
            num = 10 * num + (s[i] - '0');
    }
    if (r - l == 0)
        printf("%c=0.000\n", x);
    else
        printf("%c=%.3f\n", x, (r - l) * 1.0 / (lx - rx));
    return 0;
}
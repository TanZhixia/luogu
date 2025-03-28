#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    string s = "";
    char c;
    while (cin >> c)
        if (c != 'E')
            s += c;
        else
            break;
    int a = 0, b = 0;
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] == 'W')
            a ++;
        else
            b ++;
        if (max(a, b) >= 11 && (abs(a - b) >= 2)) {
            printf("%d:%d\n", a, b);
            a = b = 0;
        }
    }
    printf("%d:%d\n", a, b);
    cout << endl;
    a = 0, b = 0;
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] == 'W')
            a ++;
        else
            b ++;
        if (max(a, b) >= 21 && abs(a - b) >= 2) {
            printf("%d:%d\n", a, b);
            a = b = 0;
        }
    }
    printf("%d:%d\n", a, b);
    return 0;
}
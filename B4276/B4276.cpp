#include <iostream>
#include <algorithm>
using namespace std;
bool to8(int x) {
    string s("");
    int r;
    while (x > 0) {
        r = x % 8;
        x /= 8;
        s += r + '0';
    }
    string s_cpy = s;
    reverse(s.begin(), s.end());
    if (s_cpy == s)
        return true;
    return false;
}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i * i <= n; i ++) {
        int number = i * i;
        if (to8(number))
            cout << number << " ";
    }
    cout << endl;
    return 0;
}
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
string toTwo(int n) {
    int r;
    string s;
    while (n != 0) {
        r = n % 2;
        n /= 2;
        s += r + '0';
    }
    return s;
}
long long toK(string s, int k) {
    long long result = 0;
    for (int i = 0; i < s.size(); i ++)
        result += (s[i] - '0') * pow(k, i);
    return result;
}
int main() {
    int n, k;
    cin >> k >> n;
    cout << toK(toTwo(n), k) << endl;
    return 0;
}
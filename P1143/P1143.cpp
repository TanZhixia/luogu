#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n, m;
    string s;
    cin >> n >> s >> m;
    int number = 0;
    for (int i = s.size() - 1; i >= 0; i --) {
        int j = s.size() - i - 1;
        if (s[i] >= '0' && s[i] <= '9')
            number += pow(n, j) * (s[i] - '0');
        else
            number += pow(n, j) * (s[i] - 'A' + 10);
    }
    s = "";
    while (number >= 1) {
        int r = number % m;
        if (r < 10)
            s = (char) (r + '0') + s;
        else
            s = (char) (r + 'A' - 10) + s;
        number /= m;
    }
    cout << s << endl;
    return 0;
}
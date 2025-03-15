#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    string s = "";
    while (n != 0) {
        s += to_string(n);
        n /= 2;
    }
    cout << s.length() << endl;
    return 0;
}
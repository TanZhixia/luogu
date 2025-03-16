#include <iostream>
using namespace std;
int main() {
    string n;
    int k;
    cin >> n;
    cin >> k;
    while (k --)
        for (int i = 0; i < n.length(); i ++)
            if (n[i] > n[i + 1]) {
                n.erase(i, 1);
                break;
            }
    if (n.empty()) {
        cout << "0" << endl;
        return 0;
    }
    while (n.length() > 1 && n[0] == '0')
        n.erase(0, 1);
    cout << n << endl;
    return 0;
}
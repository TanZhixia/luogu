#include <iostream>
using namespace std;
int main() {
    int n, c = 1;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n - i; j ++) {
            if (c < 10)
                cout << 0;
            cout << c ++;
        }
        cout << endl;
    }
    return 0;
}
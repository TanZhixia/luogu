#include <iostream>
using namespace std;
int main() {
    int n, c = 1;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            if (c < 10)
                cout << 0;
            cout << c;
            c ++;
        }
        cout << endl;
    }
    cout << endl;
    c = 1;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n - i - 1; j ++)
            cout << "  ";
        for (int j = 0; j < i + 1; j ++) {
            if (c < 10)
                cout << 0;
            cout << c;
            c ++;
        }
        cout << endl;
    }
    return 0;
}
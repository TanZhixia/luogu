#include <iostream>
using namespace std;
char next(char c) {
    if (c != 'Z')
        return c + 1;
    return 'A';
}
int main() {
    int n;
    cin >> n;
    char c = 'A' - 1;
    for (int i = 0; i < n; i ++) {
        c = next(c);
        char c2 = c;
        cout << c2;
        for (int i = 1; i < n; i ++) {
            c2 = next(c2);
            cout << c2;
        }
        cout << endl;
    }
}
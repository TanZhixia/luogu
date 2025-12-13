#include <bits/stdc++.h>
using namespace std;
int c[15][15];
int main() {
    c[0][0] = 1;
    for (int i = 1; i <= 10; i ++)
        for (int j = 0; j <= i; j ++)
            c[i][j] = c[i - 1][j] + (j != 0 ? c[i - 1][j - 1] : 0);
    for (int i = 0; i <= 10; i ++) {
        for (int j = 0; j <= i; j ++)
            cout << setw(4) << c[i][j];
        cout << endl;
    }
    return 0;
}

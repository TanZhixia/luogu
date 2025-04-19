#include <iostream>
using namespace std;
int main() {
    int n;
    int a[100];
    cin >> n;
    for (int i = 0; i < n; i ++)
        cin >> a[i];
    int minn = a[0];
    for (int i = 1; i < n; i ++)
        minn = min(minn, a[i]);
    cout << minn << endl;
    return 0;
}
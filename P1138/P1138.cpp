#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, k;
    int a[10000];
    cin >> n >> k;
    for (int i = 0; i < n; i ++)
        cin >> a[i];
    sort(a, a + n);
    int temp = -1000000;
    int count = 1;
    for (int i = 0; ; i ++) {
        if (i >= n - 1)
            break;
        if (a[i] == temp)
            continue;
        if (count == k) {
            cout << a[i] << endl;
            return 0;
        }
        temp = a[i];
        count ++;
    }
    cout << "NO RESULT" << endl;
    return 0;
}
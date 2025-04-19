#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int a[3];
    string s;
    for (int i = 0; i < 3; i ++)
        cin >> a[i];
    cin >> s;
    sort(a, a + 3);
    for (int i = 0; i < 3; i ++)
        cout << a[s[i] - 'A'] << " ";
    cout << endl;
    return 0;
}
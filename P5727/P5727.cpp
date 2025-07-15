#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n;
    vector<int> v;
    cin >> n;
    while (n != 1) {
        v.push_back(n);
        if (n % 2 == 0) {
            n /= 2;
            continue;
        }
        n = n * 3 + 1;
    }
    v.push_back(1);
    reverse(v.begin(), v.end());
    for (int i : v)
        cout << i << " ";
    cout << endl;
    return 0;
}
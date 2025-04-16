#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    bool one = n % 2 == 0;
    bool two = n > 4 && n <= 12;
    cout << (one && two) << " ";
    cout << (one || two) << " ";
    cout << ((one || two) && !(one && two)) << " ";
    cout << !(one || two) << endl;
    return 0;
}
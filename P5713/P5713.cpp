#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    if (n * 5 < 11 + n * 3)
        cout << "Local" << endl;
    else
        cout << "Luogu" << endl;
    return 0;
}
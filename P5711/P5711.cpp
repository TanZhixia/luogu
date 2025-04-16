#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    cout << (n % 400 == 0 || n % 4 == 0 && n % 100 != 0) << endl;
    return 0;
}
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    cout << "Today, I ate " << n << " apple" << ((n > 1) ? "s." : ".") << endl;
    return 0;
}
#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int h, r;
    cin >> h >> r;
    double v = 3.14 * r * r * h / 1000;
    cout << ceil(20 / v) << endl;
    return 0;
}
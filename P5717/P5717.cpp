#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int n[3] = {a, b, c};
    sort(n, n + 3);
    a = n[0];
    b = n[1];
    c = n[2];
    if (a + b <= c) {
        cout << "Not triangle" << endl;
        return 0;
    }
    if (a * a + b * b == c * c)
        cout << "Right triangle" << endl;
    if (a * a + b * b > c * c)
        cout << "Acute triangle" << endl;
    if (a * a + b * b < c * c)
        cout << "Obtuse triangle" << endl;
    if (a == b || b == c || a == c)
        cout << "Isosceles triangle" << endl;
    if (a == b && b == c)
        cout << "Equilateral triangle" << endl;
    return 0;
}
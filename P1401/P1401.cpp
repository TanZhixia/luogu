#include <iostream>
using namespace std;
int main() {
    long long x1, y1;
    long long x2, y2;
    cin >> x1 >> x2;
    cin >> y1 >> y2;
    long long xy1 = x1 * y1;
    long long xy2 = x2 * y2;
    long long x1y2 = x1 * y2;
    long long x2y1 = x2 * y1;
    if (xy1 >= -2147483648 && xy1 <= 2147483647 && xy2 >= -2147483648 && xy2 <= 2147483647)
        if (x2y1 >= -2147483648 && x2y1 <= 2147483647 && x1y2 >= -2147483648 && x1y2 <= 2147483647)
            cout << "int" << endl;
        else
            cout << "long long int" << endl;
    else
        cout << "long long int" << endl;
    return 0;
}
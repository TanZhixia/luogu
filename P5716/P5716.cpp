#include <iostream>
using namespace std;
int main() {
    int date[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int year, m;
    cin >> year >> m;
    if ((year % 400 == 0 || year % 4 == 0 && year % 100 != 0) && m == 2)
        cout << 29 << endl;
    else
        cout << date[m] << endl;
    return 0;
}
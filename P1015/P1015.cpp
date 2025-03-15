#include <iostream>
using namespace std;
string add(string a, string b, int base) {
    string result;
    int carry = 0;
    for (int i = 1; i <= max(a.length(), b.length()); i ++) {
        int x = 0, y = 0;
        if (i <= a.length())
            if (a[a.length() - i] < '0' || a[a.length() - i] > '9')
                x = a[a.length() - i] - 'A' + 10;
            else
                x = a[a.length() - i] - '0';
        if (i <= b.length())
            if (b[b.length() - i] < '0' || b[b.length() - i] > '9')
                y = b[b.length() - i] - 'A' + 10;
            else
                y = b[b.length() - i] - '0';
        int sum = x + y + carry;
        carry = sum / base;
        if (sum % base >= 10)
            result = (char) (sum % base - 10 + 'A') + result;
        else
            result = (char) (sum % base + '0') + result; 
    }
    if (carry != 0)
        if (carry >= 10)
            result = (char) (carry - 10 + 'A') + result;
        else
            result = (char) (carry + '0') + result;
    return result;
}
string upsideDown(string s) {
    string result;
    for (int i = s.length() - 1; i >= 0; i --)
        result += s[i];
    return result;
}
int main() {
    int base;
    string number;
    cin >> base >> number;
    for (int i = 0; i < 30; i ++) {
        string upside = upsideDown(number);
        if (number == upside) {
            cout << "STEP=" << i << endl;
            return 0;
        }
        number = add(number, upside, base);
    }
    cout << "Impossible!" << endl;
    return 0;
}
#include <iostream>
using namespace std;
int main() {
    string s;
    cin >> s;
    int boy = 0;
    int girl = 0;
    for (int i = 0; i < s.length(); i ++) {
        if (s[i] == '.')
            continue;
        switch (s[i]) {
            case 'b':
                boy ++;
                if (s[i + 1] == 'o') {
                    i ++;
                    if (s[i + 1] == 'y')
                        i ++;
                }
                continue;
            case 'o':
                boy ++;
                if (s[i + 1] == 'y')
                    i ++;
                continue;
            case 'y':
                boy ++;
                continue;
            case 'g':
                girl ++;
                if (s[i + 1] == 'i') {
                    i ++;
                    if (s[i + 1] == 'r') {
                        i ++;
                        if (s[i + 1] == 'l')
                            i ++;
                    }
                }
                continue;
            case 'i':
                girl ++;
                if (s[i + 1] == 'r') {
                    i ++;
                    if (s[i + 1] == 'l')
                        i ++;
                }
                continue;
            case 'r':
                girl ++;
                if (s[i + 1] == 'l')
                    i ++;
                continue;
            case 'l':
                girl ++;
                continue;
        }
    }
    cout << boy << endl;
    cout << girl << endl;
    return 0;
}
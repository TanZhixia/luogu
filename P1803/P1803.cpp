#include <iostream>
#include <algorithm>
using namespace std;
struct Competition {
    int start, end;
};
int main() {
    int n;
    Competition c[1000000];
    cin >> n;
    for (int i = 0; i < n; i ++)
        cin >> c[i].start >> c[i].end;
    sort(c, c + n, [] (Competition a, Competition b) {
        return a.end < b.end;
    });
    int count = 0;
    int end = -1;
    for (int i = 0; i < n; i ++)
        if (c[i].start >= end) {
            count ++;
            end = c[i].end;
        }
    cout << count << endl;
    return 0;
}
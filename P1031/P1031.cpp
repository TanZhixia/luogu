#include <iostream>
using namespace std;
int main() {
    int n;
    int a[101];
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        sum += a[i];
    }
    int avg = sum / n;
    int time = 0;
    for (int i = 1; i < n; i ++) {
        if (a[i] != avg) {
            a[i + 1] += a[i] - avg;
            a[i] = avg;
            time ++;
        }
    }
    cout << time << endl;
    return 0;
}
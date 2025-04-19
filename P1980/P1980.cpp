#include <iostream>
using namespace std;
int main() {
    int n, x, count = 0;
    cin >> n >> x;
    for (int i = 1; i <= n; i ++) {
        int number = i;
        while (number > 0) {
            if (number % 10 == x)
                count ++;
            number /= 10;
        }
    }
    cout << count << endl;
    return 0;
}
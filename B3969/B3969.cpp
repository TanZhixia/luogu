#include <iostream>
using namespace std;
int main() {
    int n, b;
    cin >> n >> b;
    int count = 0;
    for (int i = 1; i <= n; i ++) {
        int maxPrimeFactor = 0;
        int temp = i;
        for (int j = 2; j * j <= temp; j ++)
            while (temp % j == 0) {
                maxPrimeFactor = j;
                temp /= j;
            }
        if (temp > 1)
            maxPrimeFactor = temp;
        if (maxPrimeFactor <= b)
            count ++;
    }
    cout << count << endl;
    return 0;
}
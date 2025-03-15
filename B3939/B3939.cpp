#include <iostream>
using namespace std;
int main() {
    bool prime[101];
    int a, b;
    cin >> a >> b;
    for (int i = 1; i <= 100; i ++)
        prime[i] = true;
    prime[1] = false;
    for (int i = 2; i <= 100; i ++)
        if (prime[i])
            for (int j = 2; i * j <= 100; j ++)
                prime[i * j] = false;
    for (int i = a; i <= b; i ++)
        if (prime[i] && prime[i / 10 + i % 10 * 10])
            cout << i << endl;
    return 0;
}
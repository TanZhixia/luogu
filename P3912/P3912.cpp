#include <iostream>
using namespace std;
bool prime[(long long) (10e8 + 1)];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        prime[i] = true;
    prime[1] = false;
    for (int i = 2; i * i <= n; i ++)
        if (prime[i])
            for (int j = i * i; j <= n; j += i)
                prime[j] = false;
    int count = 0;
    for (int i = 1; i <= n; i ++)
        if (prime[i])
            count ++;
    cout << count << endl;
    return 0;
}
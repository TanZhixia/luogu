#include <iostream>
using namespace std;
int main() {
    int n, count = 0;
    int chinese[1005], math[1005], english[1005], sum[1005];
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> chinese[i] >> math[i] >> english[i];
        sum[i] = chinese[i] + math[i] + english[i];
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = i + 1; j <= n; j ++) {\
            if (abs(chinese[i] - chinese[j]) > 5)
                continue;
            if (abs(math[i] - math[j]) > 5)
                continue;
            if (abs(english[i] - english[j]) > 5)
                continue;
            if (abs(sum[i] - sum[j]) > 10)
                continue;
            count ++;
        }
    }
    cout << count << endl;
    return 0;
}
#include <iostream>
using namespace std;
int answer[1001];
int solve(int n) {
    int result = 1;
    for (int i = 1; i <= n / 2; i ++)
        if (answer[i] == 0)
            result += solve(i);
        else
            result += answer[i];
    if (answer[n] == 0)
        answer[n] = result;
    return result;
}
int main() {
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
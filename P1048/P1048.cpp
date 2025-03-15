#include <iostream>
using namespace std;
long long knapsack(long long capacity, 
        long long quantity, 
        long long w[], 
        long long v[],
        const long long maxC, 
        const long long maxQ,
        long long I,
        long long J) {
    long long f[maxQ + 1][maxC + 1];
    for (int i = 0; i <= quantity; i ++)
        f[i][0] = 0;
    for (int i = 0; i <= capacity; i ++)
        f[0][i] = 0;
    for (int i = 1; i <= quantity; i ++)
        for (int j = 1; j <= capacity; j ++)
            if (j >= w[i])
                f[i][j] = max(f[i - 1][j - w[i]] + v[i], f[i - 1][j]);
            else
                f[i][j] = f[i - 1][j];
    return f[I][J];
}
int main() {
    int t, m;
    long long w[101], v[101];
    cin >> t >> m;
    for (int i = 1; i <= m; i ++)
        cin >> w[i] >> v[i];
    cout << knapsack(t, m, w, v, 1000, 100, m, t) << endl;
    return 0;
}
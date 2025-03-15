#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
struct item {
    int m, v;
};
bool cmp(item a, item b) {
    return (double) a.v / a.m > (double) b.v / b.m ? true : false;
}
int main() {
    int n, t;
    cin >> n >> t;
    item items[100];
    for (int i = 0; i < n; i ++)
        cin >> items[i].m >> items[i].v;
    sort(items, items + n, cmp);
    double count = 0;
    for (int i = 0; i < n; i ++) {
        if (t < items[i].m) {
            count += (double) t / items[i].m * items[i].v;
            break;
        }
        t -= items[i].m;
        count += items[i].v;
    }
    cout << fixed << setprecision(2) << count << endl;
    return 0;
}
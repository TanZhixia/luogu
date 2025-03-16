#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Apple {
    int x, y;
};
int main() {
    int n, s, a, b;
    cin >> n >> s >> a >> b;
    vector<Apple> _apples(n);
    for (int i = 0; i < n; i ++)
        cin >> _apples[i].x >> _apples[i].y;
    vector<Apple> apples;
    for (int i = 0; i < n; i ++)
        if (_apples[i].x <= a + b)
            apples.push_back(_apples[i]);
    sort(apples.begin(), apples.end(), [] (Apple a, Apple b) {
        return a.y < b.y;
    });
    int count = 0;
    for (int i = 0; i < apples.size(); i ++) {
        if (s < apples[i].y)
            break;
        s -= apples[i].y;
        count ++;
    }
    cout << count << endl;
    return 0;
}
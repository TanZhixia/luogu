#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
struct People {
    int time;
    int location;
};
bool cmp(People a, People b) {
    return a.time < b.time;
}
int main() {
    int n;
    People people[1001];
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> people[i].time;
        people[i].location = i;
    }
    sort(people + 1, people + n + 1, cmp);
    for (int i = 1; i <= n; i ++)
        cout << people[i].location << " ";
    cout << endl;
    double count = 0;
    for (int i = 1; i <= n; i ++)
        count += people[i].time * (n - i);
    count /= n;
    cout << fixed << setprecision(2) << count << endl;
    return 0;
}
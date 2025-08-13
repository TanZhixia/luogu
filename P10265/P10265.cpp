#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n, m;
int ans1, ans2;
vector<int> v1[1005], v2[1005];
void Read() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            bool b;
            cin >> b;
            if (b) {
                v1[i].push_back(j);
                v2[j].push_back(i);
            }
        }
    }
}
void get1() { ans1 = v1[m].size(); }
void get2() { ans2 = v2[m].size(); }
void Core() {
    get1();
    get2();
}
void Write() { cout << ans1 << " " << ans2 << " " << ans1 + ans2 << endl; }
int main() {
    Read();
    Core();
    Write();
    return 0;
}
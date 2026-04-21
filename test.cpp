#include <bits/stdc++.h>
using namespace std;
int main() {
    std::vector<int> a = {1, 2, 3};
    std::vector<int> b = a;                    // 拷贝：a 和 b 各有一份数据
    std::vector<int> c = std::move(a);
    cout << a[1] << endl;
    return 0;
}

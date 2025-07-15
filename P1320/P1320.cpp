#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    vector<int> v;
    char c;
    int count = 0;
    int sum = 0;
    bool flag = false;
    while (cin >> c) {
        sum ++;
        if ((bool)(c - '0') != flag) {
            v.push_back(count);
            count = 1;
            flag = (bool)(c - '0');
            continue;
        } 
        count ++;
    }
    v.push_back(count);
    cout << sqrt(sum) << " ";
    for (int i : v)
        cout << i << " ";
    cout << endl;
    return 0;
}
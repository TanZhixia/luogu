#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int count = 0;
    int index = 1;
    while (n >= index) {
        n -= index;
        count += index * index;
        index ++;
    }
    if (n > 0)
        count += n * index;
    cout << count << endl;
    return 0;
}
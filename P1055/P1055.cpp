#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    char num[9];
    char k;
    scanf("%c-%c%c%c-%c%c%c%c%c-%c", &num[0], &num[1], &num[2], &num[3], &num[4], &num[5], &num[6], &num[7], &num[8], &k);
    long long count = 0;
    for (int i = 0; i < 9; i ++)
        count += (num[i] - '0') * (i + 1);
    count %= 11;
    char ans = count == 10 ? 'X' : count + '0';
    if (ans == k)
        cout << "Right" << endl;
    else
        printf("%c-%c%c%c-%c%c%c%c%c-%c\n", num[0], num[1], num[2], num[3], num[4], num[5], num[6], num[7], num[8], ans);
    return 0;
}
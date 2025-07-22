#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct Student {
    string name;
    int val;
    int index;
    void getStudent(int i) {
        val = 0;
        index = i;
        int a, b, e;
        char c, d;
        cin >> name >> a >> b >> c >> d >> e;
        if (a > 80 && e)
            val += 8000;
        if (a > 85 && b > 80)
            val += 4000;
        if (a > 90)
            val += 2000;
        if (a > 85 && d == 'Y')
            val += 1000;
        if (b > 80 && c == 'Y')
            val += 850;
    }
    void outStudent() {
        cout << name << endl;
        cout << val << endl;
    }
} student[105];
void getSum(int n) {
    int res = 0;
    for (int i = 1; i <= n; i ++)
        res += student[i].val;
    cout << res << endl;
}
bool cmp(Student __s1, Student __s2) {
    if (__s1.val != __s2.val)
        return __s1.val > __s2.val;
    return __s1.index < __s2.index;
};
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        student[i].getStudent(i);
    sort(student + 1, student + 1 + n, cmp);
    student[1].outStudent();
    getSum(n);
    return 0;
}
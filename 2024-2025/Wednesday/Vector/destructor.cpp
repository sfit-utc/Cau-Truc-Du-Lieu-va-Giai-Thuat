#include<bits/stdc++.h>
using namespace std;
class DaThuc{
public:
    int n;
    int* a;
    DaThuc(int n = 2) {
        this->n = n;
        a = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            a[i] = i;
        }
    }
    ~DaThuc() {
        delete[] a;
    }
};
main() {
    DaThuc p1(4);
    for (int i = 0; i <= 4; i ++) {
        cout << p1.a[i] << ' ';
    }
    if (2 > 1) {
        DaThuc p2 = p1;
        for (int i = 0; i <= 4; i ++) {
            cout << p2.a[i] << ' ';
        }
    }
    for (int i = 0; i <= 4; i ++) {
        cout << p1.a[i] << ' ';
    }
}
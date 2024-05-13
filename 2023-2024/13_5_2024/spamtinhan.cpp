#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    long long k, x;
    while (t--) {
        cin >> k >> x;
        long long l = 1, r = k*2 -1;
        while (l < r) {
            long long m = (l+r)/2;
            long long g;
            if (m <= k) {
                g = m*(m+1)/2; 
            }
            else {
                g = (k*(k+1)/2) + (k*(k-1)/2) - ((k*2-1-m)*(k*2-1-m+1)/2);
            }
            if (g < x) l = m + 1;
            else r = m;
        }
        cout << l << endl;
    }
}
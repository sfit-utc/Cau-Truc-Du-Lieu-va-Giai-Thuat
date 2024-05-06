#include <bits/stdc++.h>
using namespace std;

int n;

void backtrack(string res, int dem1, int dem2){
    if(dem1 > n || dem2 > n) return;
    if(dem2 > dem1) return;
    if(dem1 == n && dem2 == n){
        cout << res << "\n";
        return;
    }
    backtrack(res + '(', dem1 + 1, dem2);
    backtrack(res + ')', dem1, dem2 + 1);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    backtrack("", 0, 0);
}
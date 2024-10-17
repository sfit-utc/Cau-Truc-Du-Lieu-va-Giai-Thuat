#include <bits/stdc++.h>
using namespace std;

int binarySearch(int a[], int n, int x){
    int l = 0, r = n - 1;
    while(l <= r){
        int mid = (l + r) / 2;
        if(a[mid] >= x){
            r = mid - 1;
        }
        else if(a[mid] < x){
            l = mid + 1;
        }
    }
    return l;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a, a+n);

    int x;
    cin >> x;

    // int res = binarySearch(a, n, x);

    int res1 = lower_bound(a, a + n, x) - a;
    int res2 = upper_bound(a, a + n, x) - a;

    cout << res1 << ' ' << res2;

}

// 10
// 1 2 3 4 5 7 9 9 9 10
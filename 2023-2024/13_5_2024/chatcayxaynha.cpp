#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define TuAnh main
using namespace std;
int get(int h[], int n, int mid) {
    int ret = 0;
    for (int i = 0; i < n; i++) ret += max(0LL, h[i] - mid);
    return ret;
}
TuAnh() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, l; cin >> n >> l;
    int h[n]; for (int i = 0; i < n; i++) cin >> h[i];

    int left = 0, right = LONG_LONG_MAX;
    int res = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        int temp = get(h, n, mid);
        if (temp >= l) {
            res = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << res;
}
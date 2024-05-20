#include <bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//template <typename T>
//using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define endl "\n"
#define int long long
const int MOD = 1e9 + 7;

void solve(){
	int x, n;
    cin >> x >> n;
    int l = x, r = n + x - 1, s1, s2;
    while(l < r){
        int mid = (l + r) / 2;
        s1 = (mid * (mid + 1) / 2 - (x - 1) * x / 2) * (mid - x + 1);
        s2 = ((n + x -1) * (n + x) / 2 - mid * (mid + 1) / 2) * (n - mid + x - 1);
        if(s1 < s2) l = mid + 1;
        else r = mid;
    }
    cout << l - x + 1 << endl;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
	cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s. \n";
}
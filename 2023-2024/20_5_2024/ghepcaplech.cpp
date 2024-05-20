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
	int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int i = 0, j = 1, res = 0;
    while(j < n){
        if(abs(a[i] - a[j] + 1) <= k){
            res += (j - i);
            ++j;
        }
        else{
            ++i;
            if(i == j) ++j;
        }
    }
    sort(a.begin(), a.end(), greater<int>());
    i = 0, j = 1;
    while(j < n){
        if(abs(a[i] - a[j] + 1) <= k){
            res += (j - i);
            ++j;
        }
        else{
            ++i;
            if(i == j) ++j;
        }
    }
    cout << res;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
	cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s. \n";
}
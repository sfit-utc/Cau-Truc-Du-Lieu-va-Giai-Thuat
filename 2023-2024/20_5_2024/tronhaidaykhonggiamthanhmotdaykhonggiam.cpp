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
	int n, m;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	cin >> m;
	int b[m];
	for(int i = 0; i < m; i++) cin >> b[i];	
	int i = 0, j = 0;
	while(i < n && j < m){
		if(a[i] < b[j]){
			cout << a[i++] << ' ';
		}
		else{
			cout << b[j++] << ' ';
		}
	}
	while(i < n) cout << a[i++] << ' ';
	while(j < m) cout << b[j++] << ' ';
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
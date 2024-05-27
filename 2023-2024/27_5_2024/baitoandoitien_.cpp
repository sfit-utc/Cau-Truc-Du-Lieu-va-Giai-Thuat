#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define endl "\n"
#define int long long
#define TuAnh main
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int mod = 1e9+7;
TuAnh() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> dp(10005, 1e5);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = a[i]; j <= 10000; j++){
            dp[j] = min(dp[j], dp[j - a[i]] + 1);
        }
    }
    while(q--){
        int m;
        cin >> m;
        if(dp[m] == 1e5) cout << -1;
        else cout << dp[m];
        cout << endl;
    }
}
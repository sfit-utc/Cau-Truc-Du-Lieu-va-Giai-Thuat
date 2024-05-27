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
const int N = 1e6 + 5;

bool check[N] = {};
int dp[N];

TuAnh() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        check[x] = true;
    }
    dp[0] = 0;
    for(int i = 1; i <= 1e6; i++){
        dp[i] = dp[i-1];
        if(check[i]) ++dp[i];
    }
    while(q--){
        int a, b;
        cin >> a >> b;
        cout << dp[b] - dp[a-1] << endl;
    }
}
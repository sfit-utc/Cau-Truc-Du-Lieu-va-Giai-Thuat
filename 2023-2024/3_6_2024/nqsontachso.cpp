#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;

int dp[10005] = {};

main(){
    int n;
    cin >> n;
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = n; j >= i; j--){
            dp[j] += dp[j-i];
            dp[j] %= MOD;
        }
    }
    cout << dp[n];
}
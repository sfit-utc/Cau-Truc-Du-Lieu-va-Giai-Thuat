#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[100005][3] = {};

main(){
    int m;
    cin >> m;
    int a[m][3];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < 3; j++) cin >> a[i][j];
    }
    dp[0][0] = a[0][0];
    dp[0][1] = a[0][1];
    dp[0][2] = a[0][2];
    for(int i = 1; i < m; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                if(j == k) continue;
                dp[i][j] = max(dp[i][j], dp[i-1][k]);
            }
            dp[i][j] += a[i][j];
        }
        // dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + a[i][0];
        // dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + a[i][1];
        // dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + a[i][2];
    }
    int res = max(dp[m-1][0], max(dp[m-1][1], dp[m-1][2]));
    cout << res;
}
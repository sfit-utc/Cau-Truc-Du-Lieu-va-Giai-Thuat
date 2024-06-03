#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005] = {};
int a[1005][1005];

main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < 1005; i++){
        for(int j = 0; j < 1005; j++){
            dp[i][j] = -100005;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(i == 1 && j == 1){
                dp[i][j] = a[i][j];
                continue;
            }
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + a[i][j];
        }
    }
    cout << dp[n][m];
}
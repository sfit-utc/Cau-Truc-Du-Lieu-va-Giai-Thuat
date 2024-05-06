#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n;
vector<int> a;
bool vis[25] = {};
int cnt = 0;

void backtrack(int step){
    if(step == n){
        ++cnt;
        for(int i : a) cout << i << ' ';
        cout << endl;
        return;
    }
    for(int i = 1; i <= n; i++){
        if(vis[i]) continue;
        if(a.size()){
            if((a[step-1] + i) % 4 == 0) continue;
        }
        vis[i] = true;
        a.push_back(i);
        backtrack(step + 1);
        a.pop_back();
        vis[i] = false;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    backtrack(0);
    cout << cnt;
}
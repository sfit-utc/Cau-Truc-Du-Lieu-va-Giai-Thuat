#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end(), greater<int>());
    deque<int> dq;
    dq.push_back(a[0]);
    for(int i = 1; i < n; i++){
        dq.push_back(a[i]);
        dq.push_back(dq.front());
        dq.pop_front();
    }
    while(dq.size()){
        cout << dq.back() << ' ';
        dq.pop_back();
    }
}
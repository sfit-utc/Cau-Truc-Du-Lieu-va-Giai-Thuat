#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    queue <int> q;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        q.push(x);
    }
    for(int i = 0; i < n; i++){
        q.push(q.front());
        q.pop();
        cout << q.front() << " ";
        q.pop();
    }
}
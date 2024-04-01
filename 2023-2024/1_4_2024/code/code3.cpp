#include <bits/stdc++.h>
using namespace std;

int main(){
    int tc; cin >> tc;
    while (tc--){
        int sz; cin >> sz;
        set<int> s;
        for (int i =0; i < sz; ++i){
            int x; cin >> x;
            s.insert(x);
        }
        cout << s.size() << "\n";
    }
    
}
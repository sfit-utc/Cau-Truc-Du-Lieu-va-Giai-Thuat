#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n;

void backtrack(string s){
    if(s.size() == n){
    	cout << s << endl;
    	return;
    }
    backtrack(s + '0');
    backtrack(s + '1');
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    backtrack("");
}
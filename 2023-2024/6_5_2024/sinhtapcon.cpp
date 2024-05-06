#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n, k;

void backtrack(int start, int step, string s){
    if(step == k){
    	cout << s << endl;
    	return;
    }
    for(int i = start; i <= n; i++){
    	backtrack(i + 1, step + 1, s + to_string(i) + ' ');
    }
}

signed main() {
	cin >> n >> k;
	backtrack(1, 0, "");
}
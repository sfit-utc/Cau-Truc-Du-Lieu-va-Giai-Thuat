#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(v.empty()) v.push_back(x);
        else{
            if(x < *v.begin()){
                v.clear();
                v.push_back(x);
            }
            else if(x == *v.begin()) v.push_back(x);
        }
    }
    cout << v.size();
}
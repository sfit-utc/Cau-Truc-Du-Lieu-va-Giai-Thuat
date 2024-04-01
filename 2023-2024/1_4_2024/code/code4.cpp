#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        string s;
        cin.ignore();
        getline(cin, s);
        set<string> res;
        string tmp = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] != ' '){
                tmp += s[i];
            }
            else{
                res.insert(tmp);
                tmp = "";
            }
        }
        if(tmp != "") res.insert(tmp);
        cout << res.size() << endl;
    }
}
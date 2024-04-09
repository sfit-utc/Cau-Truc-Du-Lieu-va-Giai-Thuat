#include <bits/stdc++.h>
#define TuAnh main
using namespace std;
TuAnh() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') st.push(s[i]);
        else {
            if (st.empty()) {
                cout << "NO";
                return 0;
            } else st.pop();
        }
    }
    if (st.empty()) cout << "YES"; else cout << "NO";
}
#include <bits/stdc++.h>
#include "D:\SFIT\Cau-Truc-Du-Lieu-va-Giai-Thuat\2024-2025\Wednesday\Stack\Stack.cpp"
#define endl "\n"
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Stack<int> s;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        s.push(x);
    }
    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
    return 0;
}
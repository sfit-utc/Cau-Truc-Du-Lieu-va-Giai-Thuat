#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define endl "\n"
#define int long long
#define TuAnh main
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int mod = 1e9+7;
TuAnh() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    vector<int> v(5, 3);
    for (auto &x: v) cout << x << ' '; cout << endl;
    v.assign(4, 2);
    for (auto &x: v) cout << x << ' '; cout << endl;
    v.insert(v.begin() + 2, 10);
    for (auto &x: v) cout << x << ' '; cout << endl;
    v.erase(v.begin(), v.begin() + 1);
    for (auto &x: v) cout << x << ' '; cout << endl;
    int a = 6;
    v.push_back(a);
    v.emplace_back(a);
    v.resize(10);
    cout << v.size() << endl;
    for (auto &x: v) cout << x << ' '; cout << endl;
    cout << v.max_size() << endl;
    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); it++) {
        
    }
}
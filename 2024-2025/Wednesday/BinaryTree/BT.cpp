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
class BT{
public:
    BT *left, *right;
    int value;
    BT(int val) {
        value = val;
        left = right = NULL;
    }
    void insert(int val) {
        if (val < value) {
            if (left == NULL) {
                left = new BT(val);
            } else left->insert(val);
        } else if (val > value) {
            if (right == NULL) {
                right = new BT(val);
            } else right->insert(val);
        }
    }
    void traverse(int depth) {
        if (left != NULL) {
            left->traverse(depth + 1);
        }
        cout << value << ' ' << depth << endl;
        if (right != NULL) {
            right->traverse(depth + 1);
        }
    }
};
TuAnh() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int x; cin >> x;
    BT root(x);
    for (int i = 1; i < n; i++) {
        cin >> x;
        root.insert(x);
    }
    root.traverse(0);
}
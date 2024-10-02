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
class Tree{
public:
    int val;
    vector<Tree*> child;
    Tree(int n) {
        val = n;
    }
    void build() {
        if (val == 0) return;
        for (int a = 1; a <= sqrt(val); a++) {
            if (val % a == 0) {
                int b = val / a;
                int tmp = (a - 1) * (b + 1);
                Tree* tr = new Tree(tmp);
                child.push_back(tr);
            }
        }
        for (int i = 0; i < child.size(); i++) {
            child[i]->build();
        }
    }
    void pre() {
        cout << val << ' ';
        for (auto u: child) u->pre();
    }
    void ino() {
        //quên kiểm tra vector rỗng :>> (nếu rỗng thì không thể truy cập child[0])
        //hehehe
        if (!child.empty()) child[0]->ino();
        cout << val << ' ';
        for (int i = 1; i < child.size(); i++) {
            child[i]->ino();
        }
    }
    void pos() {
        for (auto u: child) u->pos();
        cout << val << ' ';
    }
};
TuAnh() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    Tree* tr = new Tree(n);
    tr->build();
    tr->pre(); cout << endl;
    tr->ino(); cout << endl;
    tr->pos(); cout << endl;
}
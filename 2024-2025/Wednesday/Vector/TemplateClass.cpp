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
template <typename T>
class HCN{
private:
    T cd, cr;
public:
    HCN(T cd, T cr) {
        this->cd = cd;
        this->cr = cr;
    }
    double dientich(){
        return cd * cr;
    }
    double chuvi(){
        return (cd + cr) * 2;
    }
    ~HCN() {

    }
};



TuAnh() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    HCN<int> abcd(4, 2);
    cout << "chu vi: " << abcd.chuvi() << "\ndien tich: " << abcd.dientich();
}
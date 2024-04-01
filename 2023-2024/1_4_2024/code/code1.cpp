#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> v;
    int n; cin >> n;
    int min_value = 1000000, cnt = 0;
    for(int i = 1; i <= n; ++i)
    {
        int x; cin >> x;
        v.push_back(x);
        if(x < min_value){
            min_value = x;
            cnt = 0;
        }
        if(x == min_value) cnt++;
    }
    for(auto x : v) cout << x << ' ';
    cout << endl << cnt;
}
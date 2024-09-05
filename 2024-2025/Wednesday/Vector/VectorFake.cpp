#include<bits/stdc++.h>
#include<vector>
#include<vector>
#include"D:\SFIT\Cau-Truc-Du-Lieu-va-Giai-Thuat\2024-2025\Wednesday\Vector\Vector.cpp"
using namespace std;
main() {
    //V.begin() + 5;
    Vector<int> V(5, 6);
    Vector<int>::iterator it;
    for (it = V.begin(); it != V.end(); it++) cout << *it; cout << endl;
    for (int i = 0; i < V.size(); i++) V[i] = i + 1;
    for (it = V.begin(); it != V.end(); it++) cout << *it; cout << endl;
    for (it = V.begin(); it != V.end(); it++) cout << it - V.begin() << ' ' << it << endl;
    cout << V.begin() << endl << V.end() <<endl << V.end() - V.begin() << endl;
    cout << V.begin() + 2 << endl;
    cout << endl;
    V.insert((V.begin() + 2), 9);
    for (it = V.begin(); it != V.end(); it++) cout << *it;
};
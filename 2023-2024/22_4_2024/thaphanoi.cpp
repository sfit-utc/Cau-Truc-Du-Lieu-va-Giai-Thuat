#include <bits/stdc++.h>
using namespace std;

int step = 1;

void towerOfHanoi(int n, char a, char b, char c){
    if(n == 1){
        cout << "Buoc" << step << "Chuyen dia " << n << " tu " << a << " sang " << b << endl;
        step++;
        return;
    }
    towerOfHanoi(n-1, a, c, b);
    cout << "Buoc" << step << "Chuyen dia " << n << " tu " << a << " sang " << b << endl;
    step++;
    towerOfHanoi(n-1, c, b, a);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    towerOfHanoi(n, 'A', 'B', 'C');
}
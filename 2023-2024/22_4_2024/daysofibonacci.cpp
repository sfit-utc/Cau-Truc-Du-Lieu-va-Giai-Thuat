#include <bits/stdc++.h>
using namespace std;

int n;

void fib(int a, int b, int step){
    if(step == n) return;
    cout << b << ' ';
    fib(b, a + b, step + 1);
}

int main(){
    cin >> n;
    cout << 0 << ' ';
    if(n >= 2) fib(0, 1, 1);
}
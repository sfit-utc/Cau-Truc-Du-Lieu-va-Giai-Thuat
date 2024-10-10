#include <bits/stdc++.h>
using namespace std;

void Print(int a[], int n){
    for(int id = 0; id < n; id++){
        cout << a[id] << ' ';
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    Print(a, n);
    for(int i = 1; i < n; i++){
        int key = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > key){
            a[j+1] = a[j];
            --j;
        }
        a[j+1] = key;
        Print(a, n);
    }
}
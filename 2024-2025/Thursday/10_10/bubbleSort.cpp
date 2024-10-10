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

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(a[j] > a[j+1]){
                swap(a[j], a[j+1]);
            }
        }
    }

    Print(a, n);
}

// 6
// 12 45 32 10 8 5
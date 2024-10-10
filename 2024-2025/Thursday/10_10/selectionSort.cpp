#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int id = 0; id < n; id++)
    {
        cout << a[id] << ' ';
    }
    cout << endl;
    for (int i = 0; i < n - 1; i++)
    {
        int k = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[k])
                k = j;
        }
        swap(a[i], a[k]);

        for (int id = 0; id < n; id++)
        {
            cout << a[id] << ' ';
        }
        cout << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;

void merge(int a[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> l(n1), r(n2);
    
    //Lay du lieu vao 2 mang trai, phai
    for(int i = 0; i < n1; i++){
        l[i] = a[left + i];
    }
    for(int i = 0; i < n2; i++){
        r[i] = a[mid + 1 + i];
    }

    int i = 0, j = 0; //Chi so cua 2 mang l, r
    int k = left; //Chi so dau tien cua mang tron

    while(i < n1 && j < n2){
        if(l[i] <= r[j]){
            a[k] = l[i];
            ++i;
        }
        else{
            a[k] = r[j];
            ++j;
        }
        k++;
    }

    while(i < n1){
        a[k] = l[i];
        ++i;
        ++k;
    }

    while(j < n2){
        a[k] = r[j];
        ++j;
        ++k;
    }
}

void MergeSort(int a[], int left, int right){
    if(left < right){
        int mid = (left + right) / 2;

        //Sap xep nua trai
        MergeSort(a, left, mid);
        //Sap xep nua phai
        MergeSort(a, mid + 1, right);

        //Tron 2 mang vua sap xep
        merge(a, left, mid, right);
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    // MergeSort(a, 0, n-1);

    for(int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }
}

// 6
// 12 45 32 10 8 5
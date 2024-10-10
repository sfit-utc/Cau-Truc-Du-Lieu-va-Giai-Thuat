#include <bits/stdc++.h>
using namespace std;

int Partition(int a[], int low, int high){
    int pivot = a[high]; //Chon phan tu cuoi cung lam pivot
    int i = low - 1; //Luu vi tri cua phan tu nho hon pivot

    //Sap xep cac phan tu xoay quanh pivot (nho hon ben trai, lon hon ben phai)
    for(int j = low; j < high; j++){
        if(a[j] <= pivot){
            ++i;
            swap(a[i], a[j]);
        }
    }

    //Dua pivot ve giua
    swap(a[i + 1], a[high]);
    return i + 1;
}

void QuickSort(int a[], int low, int high){
    if(low < high){
        //Lay vi tri cua pivot
        int p = Partition(a, low, high);

        //Sap xep mang ben trai pivot
        QuickSort(a, low, p - 1);
        //Sap xep mang ben phai pivot
        QuickSort(a, p + 1, high);
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    QuickSort(a, 0, n-1);

    for(int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }

}

// 6
// 12 45 32 10 8 5
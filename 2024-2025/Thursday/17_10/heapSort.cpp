#include <bits/stdc++.h>
using namespace std;

void printA(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }
    cout << endl;
}

void heapify(int a[], int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // dua node lon nhat len lam cha
    if(left < n && a[left] > a[largest]){
        largest = left;
    }
    if(right < n && a[right] > a[largest]){
        largest = right;
    }

    //doi cho va tiep tuc heapify voi node bi vi pham
    if(largest != i){
        swap(a[i], a[largest]);

        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n){
    // xay dung max-heap
    for(int i = n / 2 - 1; i >= 0; i--){
        heapify(a, n, i);
    }
    printA(a, n);

    for(int i = n - 1; i >= 0; i--){
        swap(a[0] , a[i]);

        heapify(a, i, 0);

        printA(a, n);
    }
}

int main(){
    int a[] = {6, 12, 20, 10, 5, 7, 8, 6, 4, 3, 11};
    int n = 11;
    printA(a, n);

    heapSort(a, n);
    
}
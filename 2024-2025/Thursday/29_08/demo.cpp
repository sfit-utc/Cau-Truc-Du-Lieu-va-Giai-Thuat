#include <iostream>
#include "myvector.cpp"
using namespace std;

int main(){
    Vector<int> a(5, 0);
    for(int i = 0; i < 5; i++){
        cout << a[i] << ' ';
    }
}
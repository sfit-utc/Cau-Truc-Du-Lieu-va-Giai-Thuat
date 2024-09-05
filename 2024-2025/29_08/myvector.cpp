#include <iostream>
using namespace std;

#ifndef __vector__cpp__
#define __vector__cpp__

template <class T>
class Vector{
private:
    T *V;
    int cap, num;
public:
    Vector(){
        cap = 0;
        num = 0;
        V = new T[1];
    }
    Vector(int n, T value){
        cap = n;
        num = n;
        V = new T[n];
        for(int i = 0; i < n; i++){
            V[i] = value;
        }
    }
    ~Vector(){
        if(V){
            delete[] V;
        }
    }
    int size(){
        return num;
    }
    bool empty(){
        return num == 0;
    }
    int capacity(){
        return cap;
    }
    void pop_back(){
        if(num > 0){
            num--;
        }
        else{
            cout << "Khong co phan tu nao!";
        }
    }
    T &back(){
        return V[num - 1];
    }
    T &front(){
        return V[0];
    }
    void extend(int newCap){
        if(newCap < cap){
            return;
        }
        cap = newCap;
        T *tmp = new T[cap];
        for(int i = 0; i < num; i++){
            tmp[i] = V[i];
        }
        if(V) delete[] V;
        V = tmp;
    }
    void push_back(T value){
        if(num == cap){
            extend(cap * 2);
        }
        V[num] = value;
        ++num;
    }
    void insert(int pos, T x){
        if(num == cap){
            extend(cap * 2);
        }
        for(int i = num - 1; i >= pos; i--){
            V[i+1] = V[i];
        }
        V[pos] = x;
        ++num;
    }
    void erase(int pos){
        if(pos < 0 || pos >= size()){
            cout << "Chi so khong hop le!";
            return;
        }
        for(; pos < num; pos++){
            V[pos] = V[pos + 1];
        }
        num--;
    }
    T &operator [](int i){
        // if(i >= size() || i < 0){
        //     cout << "Chi so khong hop le!";
        //     return error;
        // }
        return V[i];
    }
    Vector &operator =(Vector<T> b){
        num = b.num;
        cap = b.cap;
        if(cap != 0){
            V = new T[cap];
            for(int i = 0; i < num; i++){
                V[i] = b.V[i];
            }
        }
        else{
            V = nullptr;
        }
        return *this;
    }
    typedef T *iterator;
    iterator begin(){
        return V;
    }
    iterator end(){
        return V + num;
    }
};

#endif

// #ifndef __vector__cpp__
// #define __vector__cpp__
// #endif

// int main(){
//     //Nhap vao 1 mang co n phan tu, in ra cac phan tu cua mang do
//     int n;
//     cin >> n;
//     Vector<int> a(n, 0);
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     for(int i = 0; i < n; i++){
//         cout << a[i] << ' ';
//     }
// }
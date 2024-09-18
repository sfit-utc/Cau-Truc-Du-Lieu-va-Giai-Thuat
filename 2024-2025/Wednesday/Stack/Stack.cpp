#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#ifndef __STACK__
#define __STACK__
template<typename T>
class Stack{
private:
    int Size;
    int Space;
    T* elem; 
public:
    Stack() {
        Size = Space = 0;
        elem = NULL;
    }
    ~Stack() {
        if (elem != NULL) delete[] elem;
    }
    //copy constructor
    // a = b = c = d
    //cin >> a
    //a = a
    Stack<T>& operator=(Stack<T>& s) {
        if (this == &s) return *this;
        this->Size = s.Size;
        this->Space = s.Space;
        if (elem != NULL) delete[] elem;
        elem = new T[Space];
        for(int i = 0; i < Size; i++){
            elem[i] = s.elem[i];
        }
        return *this;
    }
    //copy constructor
    Stack(Stack<T>& s) {
        *this = s;
    }
    int size() {
        return Size;
    }
    bool empty() {
        return Size == 0;
    }
    T& top() {
        return elem[Size - 1];
    }
    void pop() {
        if (empty()) return;
        Size--;
    }
    void clear() {
        Size = 0;
    }
    void push(T val) {
        if (Size == Space) {
            Space = Size == 0 ? 1 : Size * 2;
            T* temp = new T[Space];
            for (int i = 0; i < Size; i++) {
                temp[i] = elem[i];
            }
            if (elem != NULL) delete[] elem;
            elem = temp;
        }
        elem[Size] = val;
        ++Size;
    }
};
#endif
// int main() {
//     ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//     Stack<int> st1;

//     //Nhập vào dãy số, in ra thứ tự ngược lại
//     return 0;
// }
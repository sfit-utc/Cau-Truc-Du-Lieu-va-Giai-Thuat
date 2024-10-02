#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
template<typename T>
class Queue{
private:
    int Size, Space, f, l;
    T* elem;
public:
    Queue() {
        Size = Space = f = l = 0;
        elem = NULL;
    }
    ~Queue() {
        if (elem != NULL) delete[] elem;
    }
    Queue<T>& operator=(Queue<T>& B) {
        this->Size = B.Size;
        this->Space = B.Space;
        this->f = B.f;
        this->l = B.l;
        T* temp = new T[Space];
        for (int i = 0; i < Space; i++) {
            temp[i] = B.elem[i];
        }
        if (elem != NULL) delete[] elem;
        elem = temp;
        return *this;
    }
    //a = (b = c);
    Queue(Queue<T>& B) {
        *this = B;
    }
    bool empty() {
        return Size == 0;
    }
    int size() {
        return Size;
    }
    T& front() {
        return elem[f];
    }
    T& back() {
        if (l == 0) {
            return elem[Space - 1];
        } else return elem[l - 1];
    }
    void push(T val) {
        if (Size == Space) {
            Space = Space == 0 ? 1 : Space * 2;
            T* temp = new T[Space];
            for (int i = 0, j = f; i < Size; i++, j++) {
                //j%space
                temp[i] = elem[j % Size];
            }
            if (elem != NULL) delete[] elem;
            elem = temp;
            f = 0;
            l = f + Size;
        }
        elem[l] = val;
        Size++;
        l = (l + 1) % Space;
    }
    void pop() {
        if (Size == 0) return;
        f = (f + 1) % Space;
        Size--;
    }
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Queue<int> q;
    q.push(3);
    q.push(1);
    q.push(0);
    q.push(7);
    while (!q.empty()) {
        cout << q.front() << ' ';
        q.pop();
    }
    return 0;
}
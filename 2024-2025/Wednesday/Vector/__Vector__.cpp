/*
    Author: Tu Anh
*/
#include<iostream>
using namespace std;
#ifndef __Vector__
#define __Vector__
template <typename T>
class Vector {
public:
    
    class iterator;
    class rev_iterator;
    /*-----CONSTRUCTOR-----*/
    Vector(size_t s, T value);
    Vector(size_t s);
    Vector() : Size(0), Space(0) {Elements = NULL;}
    Vector(T* arr_0, T* arr_n); //constructor copy array
    Vector(typename Vector<T>::iterator first, typename Vector<T>::iterator last);
    Vector(const Vector<T>& V); //copy constructor
    Vector<T>& operator=(const Vector<T>& V); //copy assignment
    /*-----DESTRUCTOR-----*/
    ~Vector();
    /*-----ITERATORS-----*/
    iterator begin() const;
    iterator end() const;
    const iterator cbegin() const; //const iterator to begin
    const iterator cend() const; //const iterator to end
    /*-----REVERSE ITERATORS-----*/
    rev_iterator rbegin() const;
    rev_iterator rend() const;
    const rev_iterator crbegin() const;
    const rev_iterator crend() const;
    /*-----MODIFIERS-----*/
    void clear(); //remove all elements from the Vector (Capacity is not changed)
    void push_back(const T& val);
    void pop_back();
    void assign(size_t s, const T& value);
    void assign(T* first, T* last);
    void assign(typename Vector<T>::iterator first, typename Vector<T>::iterator last);
    void assign(initializer_list<T> ilist);
    iterator insert(typename Vector<T>::iterator position, const T& value); //single element
    void insert(typename Vector<T>::iterator position, size_t n, const T& value); //fill
    //iterator insert(typename Vector<T>::iterator position, typename Vector<T>::iterator first, typename Vector<T>::iterator last); //range
    iterator erase(typename Vector<T>::iterator position);
    iterator erase(typename Vector<T>::iterator start_position, typename Vector<T>::iterator end_position);  //remove [first, last)
    void swap(Vector<T>& V);
    /*-----ELEMENT ACCESS-----*/
    T& at(int position);
    const T& at(int position) const;
    T* data();
    const T* data() const;
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;
    T& operator[](int i);
    const T& operator[](int i) const;
    /*-----CAPACITY-----*/
    bool empty() const;
    size_t size() const;
    size_t capacity() const;
    void resize(int new_size, T val);
    void resize(int new_size);
    void reserve(int new_malloc);
    void shrink_to_fit();
private:
    size_t Size; //number of elements in Vector
    size_t Space; //total space used by Vector including elements and free space
    T* Elements; //pointer to first element of Vector
};

//rev_iterator
template<typename T>
class Vector<T>::rev_iterator {
private:
    T* curr;
public:
    rev_iterator (T* p = NULL) : curr(p) {}
    rev_iterator& operator++() {
        curr--;
        return *this;
    }
    rev_iterator& operator++(int) {
        curr--;
        return *this;
    }
    rev_iterator& operator--() {
        curr++;
        return *this;
    }
    rev_iterator& operator--(int) {
        curr--;
        return *this;
    }
    rev_iterator operator+(int x) {
        return curr - x;
    }
    rev_iterator operator-(int x) {
        return curr + x;
    }
    int operator-(rev_iterator B) {
        return curr - B.curr;
    }
    T& operator*() {
        return *curr;
    }
    bool operator==(rev_iterator B) {
        return this->curr == B.curr;
    }
    bool operator!=(rev_iterator B) {
        return !((*this) == B);
    }
};

//iterator
template <typename T> 
class Vector<T>::iterator {
public:
    iterator(T* p = NULL) : curr(p) {}
    iterator& operator++() {
        curr++;
        return *this;
    }
    iterator& operator++(int) {
        curr++;
        return *this;
    }
    iterator& operator--() {
        curr--;
        return *this;
    }
    iterator& operator--(int) {
        curr--;
        return *this;
    }
    iterator operator+(int x) {
        return curr + x;
    }
    iterator operator-(int x) {
        return  curr - x; //not change the object
    }
    int operator-(iterator B) {
        return this->curr - B.curr;
    }
    T& operator*() {
        return *curr;
    }
    bool operator==(const iterator& B) const {
        return curr == B.curr;
    }
    bool operator!=(const iterator& B) const {
        return ! ((*this ) == B);
    }
    // friend ostream& operator<< (ostream& os, const iterator& it) {
    //         os << it.curr;
    //         return os;
    //     }
private:
    T* curr;
};

//constructor
template <typename T>
inline Vector<T>::Vector(size_t s, T value) : Size(s), Space(s), Elements(new T[s]) {
    for (int i = 0; i < s; i++) Elements[i] = value;
}
template <typename T>
inline Vector<T>::Vector(size_t s) {
    Size = s;
    Space = s;
    Elements = new T[s];
    for (int i = 0; i < s; i++) Elements[i] = T();
}
template <typename T>
inline Vector<T>::Vector(T* arr_0, T* arr_n) : Size(arr_n - arr_0), Space(arr_n - arr_0), Elements(new T[arr_n - arr_0]) {
    for (int i = 0; i < Size; i++) {
        Elements[i] = *arr_0;
        arr_0++;
    }
}
template <typename T>
inline Vector<T>::Vector(typename Vector<T>::iterator first, typename Vector<T>::iterator last) {
    Size = last - first;
    Space = Size;
    Elements = new T[Size];
    for (int i = 0; i < Size; i++) Elements[i] = *(first + i);
}
template <typename T>
inline Vector<T>::Vector(const Vector<T>& V) : Size(V.Size), Space(V.Space), Elements(new T[V.Space]) {
    for (int i = 0; i < V.Size; i++) Elements[i] = V.Elements[i];
}
template <typename T>
inline Vector<T>& Vector<T>::operator=(const Vector<T>& V) {
    if (this == &V) return *this;
    if (V.Size <= Space) {
        for (int i = 0; i < V.Size; i++) {
            Elements[i] = V.Elements[i];
        }
        Size = V.Size;
    }
    T* temp = new T[V.Size];
    for (int i = 0; i < V.Size; i++) temp[i] = V.Elements[i];
    if (Elements != NULL) delete[] Elements;
    Elements = temp;
    Size = V.Size;
    Space = V.Size;
    return *this;
}
template <typename T> 
Vector<T>::~Vector() {
    delete[] Elements;
}

//iterator
template <typename T>
inline typename Vector<T>::iterator Vector<T>::begin() const {  //typename:Vector<t>::iterator (nested class)
    return Vector<T>::iterator(&Elements[0]);
}
template <typename T>
inline typename Vector<T>::iterator Vector<T>::end() const {
    return Vector<T>::iterator(&Elements[Size]);
}
template <typename T>
inline const typename Vector<T>::iterator Vector<T>::cend() const {
    return Vector<T>::iterator(&Elements[Size]);
}
template <typename T>
inline const typename Vector<T>::iterator Vector<T>::cbegin() const {
    return Vector<T>::iterator(&Elements[0]);
}

//reverse iterator
template<typename T>
inline typename Vector<T>::rev_iterator Vector<T>::rbegin() const {
    return Vector<T>::rev_iterator(&Elements[Size - 1]);
}
template<typename T>
inline typename Vector<T>::rev_iterator Vector<T>::rend() const {
    return Vector<T>::rev_iterator(Elements - 1);
}
template<typename T>
inline const typename Vector<T>::rev_iterator Vector<T>::crbegin() const {
    return Vector<T>::rev_iterator(&Elements[size - 1]);
}
template<typename T>
inline const typename Vector<T>::rev_iterator Vector<T>::crend() const {
    return Vector<T>::rev_iterator(Elements - 1);
}


//capacity
template <typename T>
inline bool Vector<T>::empty() const {
    return Size == 0;
}
template <typename T>
inline size_t Vector<T>::size() const {
    return Size;
}
template <typename T>
inline size_t Vector<T>::capacity() const {
    return Space;
}
template <typename T>
inline void Vector<T>::reserve(int new_malloc) {
    if (new_malloc <= Space) return;
    T* temp = new T[new_malloc];
    for (int i = 0; i < Size; i++) {
        temp[i] = Elements[i];
    }
    if (Elements) delete[] Elements;
    Elements = temp;
    Space = new_malloc;
}
template <typename T>
inline void Vector<T>::resize(int new_size, T val) {
    reserve(new_size);
    for (int i = Size; i < new_size; i++) Elements[i] = val;
    Size = new_size;
}
template <typename T>
inline void Vector<T>::resize(int new_size) {
    reserve(new_size);
    for (int i = Size; i < new_size; i++) Elements[i] = T();
    Size = new_size;
}
template <typename T>
inline void Vector<T>::shrink_to_fit() {
    T* temp = new T[Size];
    for (int i = 0; i < Size; i++) temp[i] = Elements[i];
    if (Elements != NULL) delete[] Elements;
    Elements = temp;
    Space = Size;
}

//modifiers
template <typename T>
inline void Vector<T>::clear() {
    Size = 0;
}
template <typename T>
inline void Vector<T>::push_back(const T& val) {
    if (Space == 0) reserve(8);
    if (Size == Space) {
        reserve(2 * Space);
    }
    Elements[Size] = val;
    Size++;
}
template <typename T>
inline void Vector<T>::pop_back() {
    if (Size > 0) --Size;
}
template <typename T>
inline void Vector<T>::assign(size_t s, const T& value) {
    if (Space < s) reserve(s);
    Size = s;
    for (int i = 0; i < Size; i++) Elements[i] = value;
}
template <typename T>
inline void Vector<T>::assign(T* first, T* last) {
    int temp = last - first;
    if (Space < temp) reserve(temp);
    Size = temp;
    for (int i = 0; i < Size; i++) Elements[i] = *(first + i);
}
template <typename T>
inline void Vector<T>::assign(typename Vector<T>::iterator first, typename Vector<T>::iterator last) {
    int temp = last - first;
    if (Space < temp) reserve(temp);
    Size = temp;
    for (int i = 0; i < Size; i++) Elements[i] = *(first + i);
}
template <typename T>
inline void Vector<T>::assign(initializer_list<T> ilist) {
    int temp = ilist.size();
    if (Space < temp) reserve(temp);
    Size = temp;
    int id = 0;
    for (auto x : ilist) {Elements[id++] = x;}
}
template <typename T>
inline typename Vector<T>::iterator Vector<T>::insert(typename Vector<T>::iterator position, const T& value) {
    int temp = position - begin();
    //IT'S YOUUUUUUUUUU
    if (Size == Space) {reserve(Space * 2);}
    Size++;
    for (int i = Size; i > temp; i--) {
        Elements[i] = Elements[i - 1];
    }
    *(begin() + temp) = value;
    return begin() + temp;
} // return the iterator that points to the first of the newly inserted elements
template <typename T>
inline void Vector<T>::insert(typename Vector<T>::iterator position, size_t n, const T& value) {
    int temp = position - begin();
    //remember to change the size
    if (Size + n > Space) {reserve(Size + n);}
    Size = Size + n;
    for (int i = Size + n - 1; i > (temp) + n - 1; i--) {
        Elements[i] = Elements[i - n];
    }
    for (int i = temp; i < temp + n; i++) {
        Elements[i] = value;
    }
}
template <typename T>
inline typename Vector<T>::iterator Vector<T>::erase(typename Vector<T>::iterator position) {
    int temp = position - begin();
    for (int i = temp; i < Size - 1; i++) {
        Elements[i] = Elements[i + 1];
    }
    Size--;
    return begin() + temp;
}
template <typename T>
inline typename Vector<T>::iterator Vector<T>::erase(typename Vector<T>::iterator start_position, typename Vector<T>::iterator end_position) {
    int temp = start_position - begin();
    int l = end_position - start_position;
    for (int i = temp; i < Size - l; i++) {
        Elements[i] = Elements[i + l];
    }
    Size -= l;
    return begin() + temp;
}
template <typename T>
void Vector<T>::swap(Vector<T>& V) {
    Vector<T> temp = V;
    V = *this;
    *this = temp;
}

//element access
template <typename T>
T& Vector<T>::at(int position) {
    return Elements[position];
}
template <typename T>
const T& Vector<T>::at(int position) const {
    return Elements[position];
}
template <typename T>
T& Vector<T>::front() {
    return Elements[0];
}
template <typename T>
const T& Vector<T>::front() const {
    return Elements[0];
}
template <typename T>
T& Vector<T>::back() {
    return Elements[Size - 1];
}
template <typename T>
const T& Vector<T>::back() const {
    return Elements[Size - 1];
}
template <typename T>
T& Vector<T>::operator[](int i) {
    return Elements[i];
}
template <typename T>
const T& Vector<T>::operator[](int i) const {
    return Elements[i];
}
template <typename T>
T* Vector<T>::data() {
    return Elements;
}
template <typename T>
const T* Vector<T>::data() const {
    return Elements;
}
#endif





//  main() {
//      Vector<int> V(10);
//      int i = 1;
//      for (auto &x:V) x = i++;
// //     for (Vector<int>::rev_iterator rit = V.rbegin(); rit != V.rend(); rit++) cout << *rit << ' ';
//         Vector<int>::iterator it = V.begin(), it2;
//         it2 = it++;
//         it++;
//         cout << *it2;
// }
// main() {
//     //V.begin() + 5;
//     Vector<int> V(5, 6);
//     Vector<int>::iterator it;
//     for (it = V.begin(); it != V.end(); it++) cout << *it; cout << endl;
//     for (int i = 0; i < V.size(); i++) V[i] = i + 1;
//     for (it = V.begin(); it != V.end(); it++) cout << *it; cout << endl;
//     for (it = V.begin(); it != V.end(); it++) cout << it - V.begin() << ' ' << it << endl;;
//     cout << V.begin() << endl << V.end() <<endl << V.end() - V.begin() << endl;
//     cout << V.begin() + 2 << endl;
//     cout << endl;
//     V.insert((V.begin() + 2), 9);
//     for (it = V.begin(); it != V.end(); it++) cout << *it;
// };
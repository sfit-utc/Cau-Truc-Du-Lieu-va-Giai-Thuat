#ifndef __VECTOR__
#define __VECTOR__
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Vector
{
private:
    T *elements;
    int Size;
    int space;

public:
    class iterator
    {
    private:
        T *curr;

    public:
        //Constructor
        iterator(T *p = NULL)
        {
            curr = p;
        }
        iterator& operator++(int)
        {
            curr = curr + 1; // chuyển con trỏ tới ô nhớ tiếp theo
            return *this;
        }
        iterator& operator++()
        {
            curr = curr + 1; // chuyển con trỏ tới ô nhớ tiếp theo
            return *this;
        }
        iterator& operator--(int)
        {
            curr = curr - 1;
            return *this;
        }
        iterator& operator--()
        {
            curr = curr - 1;
            return *this;
        }
        iterator operator+(int i) {
            return curr + i; //chuyen toi curr + i   123456
        }
        iterator operator-(int i) {
            return curr - i;
        }
        //it1 = v.begin() + 5, it2 = v.begin() + 1
        int operator-(iterator it) {
            return this->curr - it.curr;
        }
        // iterator& operator=(iterator itdung)
        // {
        //     curr = itdung.curr;
        //     return *this;
        // }
        bool operator==(const iterator& itdung) const 
        {
            return curr == itdung.curr;
        }
        bool operator!=(const iterator& it) const
        {
            return !(it == (*this));
        }
        // 01234 Size = 5
        T& operator*()
        {
            // vector<int>::iterator it;
            //*it (giá trị tại vị trí it đang trỏ đến)
            return *curr;
        }
        friend ostream& operator<< (ostream& os, const iterator& it) {
            os << it.curr;
            return os;
        }
    };
    iterator begin() const
    {
        return iterator(&elements[0]);
        // iterator it(elements);
        // return it;
    }
    iterator end() const 
    {
        return iterator(elements + Size);
    }
    iterator rbegin() const {
        return elements + Size - 1;
    }
    iterator rend() const {
        return elements - 1;
    }
// 1, 2, 3, 4, 5
//*V.begin() = 4
// 4, 2, 3, 4, 5
    Vector()
    {
        Size = 0;
        space = 0;
    }
    Vector(int n)
    {
        Size = n;
        space = n;
        elements = new T[n];
        for (int i = 0; i < n; i++)
        {
            elements[i] = T();
        }
    }
    Vector(int n, T value)
    {
        Size = n;
        space = n;
        elements = new T[n];
        for (int i = 0; i < n; i++)
        {
            elements[i] = value;
        }
    }
    void reserve(int newmalloc) {
        if (space >= newmalloc) {
            return;
        }
        space = newmalloc;
        T* temp = new T[newmalloc];
        for (int i = 0; i < Size; i++) {
            temp[i] = elements[i];
        }
        if (elements) delete[] elements;
        elements = temp;
    }
    void push_back(T& val) {
        if (space == 0) reserve(8);
        if (space == size) {
            reserve(space * 2);
            Size++;
            elements[Size - 1] = val;
        } else {
            size++;
            elements[Size - 1] = val;
        }
    }
    void pop_back() {
        if (Size == 0) {
            return;
        }
        Size--;  
    }
    //V[0] = 5, V[0] = 6
    T& operator[](int i) {
        return elements[i];
    }
    int size() const {
        return Size;
    }
    void insert(iterator it, T val) {
        //1 2 3 4 5 0
        int pos =  it - begin();//cần gán pos = it - begin() trước khi cấp phát thêm bộ nhớ
        if (Size == space) {
            reserve(Size * 2); //lúc này địa chỉ elem đã thay đổi
        }
        Size++;
        //cout << it << endl << begin() << endl;
        //cout << "---" << *(it) << endl;
        // cout << "pos" << pos << endl;
        for (int i = Size; i > pos; i--) {
            elements[i] = elements[i - 1];
        }
        elements[pos] = val;
    }
};

// main()
// {
//     Vector<int> A(5, 3);
//     Vector<int>::iterator it;
//     for (it = A.begin(); it != A.end(); it++)
//     {
//         cout << *it << ' ';
//     }
// //A  4 -> 5 reserve(5)
//     //reserve, pushb, popb, assign(5, 4)
// }
#endif
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Vector
{
private:
    T *elements;
    int size;
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
        iterator operator++(int)
        {
            curr = curr + 1; // chuyển con trỏ tới ô nhớ tiếp theo
            return curr;
        }
        iterator operator=(iterator itdung)
        {
            curr = itdung.curr;
            return *this;
        }
        bool operator==(iterator itdung)
        {
            return curr == itdung.curr;
        }
        bool operator!=(iterator it)
        {
            return !(it == (*this));
        }
        // 01234 size = 5
        T operator*()
        {
            // vector<int>::iterator it;
            //*it (giá trị tại vị trí it đang trỏ đến)
            return *curr;
        }
    };
    iterator begin()
    {
        return iterator(elements);
        // iterator it(elements);
        // return it;
    }
    iterator end()
    {
        return iterator(elements + size);
    }
    Vector()
    {
        size = 0;
        space = 0;
    }
    Vector(int n)
    {
        size = n;
        space = n;
        elements = new T[n];
        for (int i = 0; i < n; i++)
        {
            elements[i] = T();
        }
    }
    Vector(int n, T value)
    {
        size = n;
        space = n;
        elements = new T[n];
        for (int i = 0; i < n; i++)
        {
            elements[i] = value;
        }
    }
};

main()
{
    Vector<int> A(5, 3);
    Vector<int>::iterator it;
    for (it = A.begin(); it != A.end(); it++)
    {
        cout << *it << ' ';
    }
}
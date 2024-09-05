#include <bits/stdc++.h>
using namespace std;

#ifndef __SingleLinkedList__
#define __SingleLinkedList__

template <typename T>
class Node
{
private:
    T data;
    Node *next;
    // Node *prev;

public:
    Node(T value)
    {
        data = value;
        next = nullptr;
    }
};

template <typename T>
class SingleLinkedList
{
private:
    Node<T> *header;
    Node<T> *trailer;
    int num = 0;

public:
    SingleLinkedList()
    {
        header = trailer = nullptr;
        num = 0;
    }

    int size()
    {
        return num;
    }

    bool empty()
    {
        return num == 0;
    }

    T back()
    {
        if (trailer)
        {
            return trailer->data;
        }
    }

    T front()
    {
        if (header)
        {
            return header->data;
        }
    }

    void push_back(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        if (empty())
        {
            header = trailer = newNode;
        }
        else
        {
            trailer->next = newNode;
            trailer = newNode;
        }
        ++num;
    }

    void push_front(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        if (empty())
        {
            header = trailer = newNode;
        }
        else
        {
            newNode->next = header;
            header = newNode;
        }
        ++num;
    }

    void insert(int pos, T value)
    {
        if (pos < 0 || pos > num)
        {
            return;
        }
        if (pos == 0)
        {
            push_front(value);
        }
        else if (pos == num)
        {
            push_back(value);
        }
        else
        {
            Node<T> *newNode = new Node<T>(value);
            Node<T> *tmp = header;
            for (int i = 1; i < pos; i++)
            {
                tmp = tmp->next;
            }
            newNode->next = tmp->next;
            tmp->next = newNode;
            ++num;
        }
    }

    void pop_front()
    {
        if (empty())
        {
            return;
        }
        Node<T> *tmp = header;
        header = header->next;
        delete tmp;
        --num;
        if (num == 0)
            trailer = nullptr;
    }

    void pop_back()
    {
        if (empty())
        {
            return;
        }
        if (header == trailer)
        {
            delete header;
            header = trailer = nullptr;
        }
        else
        {
            Node<T> *tmp = header;
            while (tmp->next != trailer)
            {
                tmp = tmp->next;
            }
            delete trailer;
            trailer = tmp;
            trailer->next = nullptr;
        }
        --num;
    }

    void erase(int pos)
    {
        if (pos < 0 || pos >= num)
        {
            return;
        }
        if (pos == 0)
        {
            pop_front();
        }
        else if (pop == num - 1)
        {
            pop_back();
        }
        else
        {
            Node<T> *tmp = header;
            for (int i = 1; i < pos; i++)
            {
                tmp = tmp->next;
            }
            Node<T> *eraseNode = tmp->next;
            tmp->next = eraseNode->next;
            delete eraseNode;
            --num;
        }
    }

    typedef Node<T> *iterator;
    iterator begin()
    {
        return header;
    }

    iterator end()
    {
        return nullptr;
    }

    bool operator!=(const iterator &a, const iterator &b)
    {
        return a != b;
    }

    iterator& operator++(iterator& it){
        it = it->next;
        return it;
    }

    T& operator*(iterator& it){
        return it->data;
    }
};

#endif
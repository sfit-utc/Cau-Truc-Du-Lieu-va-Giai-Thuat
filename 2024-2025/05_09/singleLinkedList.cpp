#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;

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

    Node<T>* back()
    {
        return trailer;
    }

    Node<T>* front()
    {
        return header;
    }

    void push_back(Node<T>* newNode)
    {
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

    void push_front(Node<T>* newNode)
    {
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

    void insert(int pos, Node<T>* newNode)
    {
        if (pos < 0 || pos > num)
        {
            return;
        }
        if (pos == 0)
        {
            push_front(newNode);
        }
        else if (pos == num)
        {
            push_back(newNode);
        }
        else
        {
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
        else if (pos == num - 1)
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

    class iterator {
    private:
        Node<T>* node;

    public:
        iterator(Node<T>* n) : node(n) {}

        bool operator!=(const iterator& other) const {
            return node != other.node;
        }

        iterator& operator++() {
            node = node->next;
            return *this;
        }

        T& operator*() {
            return node->data;
        }
    };

    iterator begin() {
        return iterator(header);
    }

    iterator end() {
        return iterator(nullptr);
    }
};

int main()
{
    SingleLinkedList<int> a;
    Node<int> *newNode = new Node<int>(10);
    
    a.push_back(newNode);
    
    for (auto it = a.begin(); it != a.end(); ++it)
    {
        cout << *it << endl;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Node{
private:
    int data;
    Node *parent;
    vector<Node*> child;
public:
    Node(int data){
        this->data = data;
        parent = NULL;
    }
    Node *getParent(){
        return parent;
    }
    void setParent(Node* parent){
        this->parent = parent;
    }
    Node *getChild(int i){
        return child[i];
    }
    void insertChild(int data){
        Node *newNode = new Node(data);
        child.push_back(newNode);
    }
    vector<Node*> getChild(){
        return child;
    }
    int getElem(){
        return data;
    }
    void setElem(int data){
        this->data = data;
    }
};

class Tree{
private:
    Node *root;
    int num;
public:
    Tree(){
        root = NULL;
    }
    Node *getRoot(){
        return root;
    }
    int size(){
        return num;
    }
    bool empty(){
        return num == 0;
    }
    bool isInternal(Node *x){
        return x->getChild().size() != 0;
    }
    bool isExternal(Node *x){
        return x->getChild().size() == 0;
    }
    bool isRoot(Node *x){
        return x->getParent() == NULL;
    }
    void add(Node *a, Node *p, int data){
        if(a == NULL) return;
        if(a == p){
            p->insertChild(data);
            return;
        }
        for(auto v : a->getChild()){
            add(v, p, data);
        }
    }
    void preOrder(Node *v){
        if(v == NULL){
            return;
        }
        cout << v->getElem() << ' ';
        for(auto w : v->getChild()){
            preOrder(w);
        }
    }
    void inOrder(Node *v){
        if(v == NULL){
            return;
        }
        Node *w;
        if(v->getChild().size()){
            w = v->getChild()[0];
            inOrder(w);
        }
        cout << v->getElem() << ' ';
        for(auto w1 : v->getChild()){
            if(w1 != w){
                inOrder(w1);
            }
        }
    }
    void postOrder(Node *v){
        if(v == NULL){
            return;
        }
        for(auto w : v->getChild()){
            preOrder(w);
        }
        cout << v->getElem() << ' ';
    }
};

int main(){
    Tree tree;
}
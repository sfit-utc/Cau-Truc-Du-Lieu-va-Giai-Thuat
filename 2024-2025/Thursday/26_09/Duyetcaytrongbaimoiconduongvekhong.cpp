#include <bits/stdc++.h>
using namespace std;

class Node{
private:
    int data;
    vector<Node*> child;
public:
    Node(int data = 0){
        this->data = data;
    }
    int getData(){
        return data;
    }
    void setData(int data){
        this->data = data;
    }
    vector<Node*> &getChild(){
        return child;
    }
};

class Tree{
private:
    Node *root;
public:
    Tree(int x = 0){
        root = new Node(x);
    }
    Node *getRoot(){
        return root;
    }
    void add(Node *v){
        int x = v->getData();
        if(x != 0){
            for(int i = 1; i * i <= x; i++){
                if(x % i == 0){
                    int a = i, b = x / i;

                    int tmp = (a - 1) * (b + 1);

                    Node *newNode = new Node(tmp);
                    
                    v->getChild().push_back(newNode);

                    add(newNode);
                }
            }
        }
    }
    void preOrder(Node *v){
        if(!v) return;
        cout << v->getData() << ' ';
        for(auto w : v->getChild()){
            preOrder(w);
        }
    }
    void inOrder(Node *v){
        if(!v) return;
        if(v->getChild().size()) inOrder(v->getChild()[0]);
        cout << v->getData() << ' ';
        for(int i = 1; i < v->getChild().size(); i++){
            inOrder(v->getChild()[i]);
        }
    }
    void postOrder(Node *v){
        if(!v) return;
        for(auto i : v->getChild()){
            postOrder(i);
        }
        cout << v->getData() << ' ';
    }
};

int main(){
    int n;
    cin >> n;
    Tree *tree = new Tree(n);
    tree->add(tree->getRoot());
    tree->preOrder(tree->getRoot()); cout << endl;
    tree->inOrder(tree->getRoot()); cout << endl;
    tree->postOrder(tree->getRoot());
}
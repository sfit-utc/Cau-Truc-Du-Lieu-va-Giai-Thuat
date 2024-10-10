#include <bits/stdc++.h>
using namespace std;

class Node{
private:
    int data;
    Node *left;
    Node *right;
public:
    Node(int data = 0){
        this->data = data;
        left = NULL;
        right = NULL;
    }
    int GetData(){
        return data;
    }
    void SetData(int data){
        this->data = data;
    }
    void SetLeft(int data){
        left = new Node(data);
    }
    void SetRight(int data){
        right = new Node(data);
    }
    Node *GetLeft(){
        return left;
    }
    Node *GetRight(){
        return right;
    }
};

class BSTree{
private:
    Node *root;
public:
    BSTree(int data = 0){
        root = new Node(data);
    }
    void Add(Node *v, int x){
        if(x < v->GetData()){
            if(v->GetLeft() == NULL){
                v->SetLeft(x);
                return;
            }
            else Add(v->GetLeft(), x);
        }
        else{
            if(v->GetRight() == NULL){
                v->SetRight(x);
                return;
            }
            else Add(v->GetRight(), x);
        }
    }
    void preOrder(Node *v){
        cout << v->GetData() << ' ';
        if(v->GetLeft()) preOrder(v->GetLeft());
        if(v->GetRight()) preOrder(v->GetRight());
    }
    void inOrder(Node *v){
        if(v->GetLeft()) inOrder(v->GetLeft());
        cout << v->GetData() << ' ';
        if(v->GetRight()) inOrder(v->GetRight());
    }
    void postOrder(Node *v){
        if(v->GetLeft()) postOrder(v->GetLeft());
        if(v->GetRight()) postOrder(v->GetRight());
        cout << v->GetData() << ' ';
    }
    Node *GetRoot(){
        return root;
    }
};

int main(){
    int n = 6;
    int a[8] = {3, 2, 5, 1, 7, 9, 8, 10};
    BSTree *tree = new BSTree(n);
    for(int i = 0; i < 8; i++){
        tree->Add(tree->GetRoot(), a[i]);
    }
    tree->preOrder(tree->GetRoot()); cout << endl;
    tree->inOrder(tree->GetRoot()); cout << endl;
    tree->postOrder(tree->GetRoot()); cout << endl;
}
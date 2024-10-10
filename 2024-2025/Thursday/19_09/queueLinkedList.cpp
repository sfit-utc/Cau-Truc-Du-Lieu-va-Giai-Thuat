//cai dat queue bang node
#include <bits/stdc++.h>
using namespace std;
#ifndef _nodequeue__cpp
#define _nodequeue__cpp
template <class T>
class node{
	T elem;
	node<T> *next;
	public:
	node(T x, node<T> *N=nullptr){
		elem=x;
		next = N;
	}
	T &getelem(){
		return elem;
	}
	void setnext(node *N){
		next = N;
	}
	node<T> *getnext(){
		return next;
	}
};
template<class T>
class QUEUE{
	unsigned num;
	node<T> *F,*L;
	public:
		QUEUE(){num=0;
		F=L=nullptr;
		}
		unsigned size(){return num;
		}
		T &front(){
			return F->getelem();
		}
		T &back(){
			return L->getelem();
		}
		void push(T x){
			if(num==0) F=L=new node<T>(x);
			else{
				L->setnext(new node<T>(x));
				L=L->getnext();
			}
			num++;
		}
		void pop(){
			if(num==0) return;
			F=F->getnext();
			num--;
		}
		
};
#endif
//cai dat queue bang mang
#include<bits/stdc++.h>
using namespace std;
template <class T> 
class Queue
{
	int num,cap,F,L;    //F-first elem[F] ->front  //L-last  E[last-1] = back
	T *elem;
	public:
		Queue() {num=F=L=cap=0; elem=NULL;}
		~Queue() {if(elem) delete[]elem;}
		int size() {return num;}
		bool empty() {return num==0;}  //if(num==0) return true; else return false;
		T &front() {return elem[F];}
		T &back() {return  L==0?elem[cap-1]:elem[L-1];}
		void pop() {F=(F+1)%cap; num--;} //if(F==cap-1) F=0; else F++;
		void push(T x)
		{
			if(num==cap)
			{
				cap=cap?cap*2:1;   //cap=(1+cap)*2;
				T *tem=new T[cap];
				for(int i=0,j=F;j<F+num;j++,i++) tem[i]=elem[j%num];
				if(elem) delete[]elem;
				elem=tem;
				F=0;L=num;
			}
			elem[L]=x ; L=(L+1)%cap;
			num++;
		}
};
int main()
{
	Queue<int> Q;
	for(auto x:{4,7,2,8,4,8,3,2,5,6}) Q.push(x);
	while(Q.size()) {cout<<Q.front()<<" "; Q.pop();}
}

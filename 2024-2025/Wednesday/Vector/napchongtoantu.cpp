#include<iostream> 
using namespace std; 
class Enclosing {       
    private:    
        int x; 
        
    
    public:
    Enclosing(): x(9) {
    }
    class Nested { 
        private:
        int y;    
        public:
        void NestedFun(Enclosing *e) { 
            cout<<e->x; 
        }        
    }; 
};
  
class c1{
int x1, x2;
public:
c1(int x1 = 0, int x2 = 0) {
    this->x1 = x1;
    this->x2 = x2;
}
c1 operator+(c1 obj2) {
    c1 sum;
    sum.x1 = x1 + obj2.x1;
    sum.x2 = x2 + obj2.x2;
    return sum;
}
c1 operator-(c1 obj2) {
    c1 ret;
    ret.x1 = x1 - obj2.x1;
    ret.x2 = x2 - obj2.x2;
    return ret;
}
void get(){
    cout << x1 << ' ' << x2;
}

}  ;
int main() 
{      
    Enclosing *A = new Enclosing();
    Enclosing::Nested N;
    //N.NestedFun(A);
    c1 obj1(2, 3), obj2(2, 9); 
    //obj1 + obj2 = obj(obj1.x1 + obj2.x1, obj1.x2 + obj2.x2)
    c1 obj3 = obj1 + obj2;
    obj3.get();
       

} 
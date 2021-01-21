#include <iostream>    
using namespace std;  
class Demo  
{  
    int a;  
    int b;  
    int *p;  
    public:  
    Demo()  
    {  
        p=new int;  
    }  
    void setdata(int x,int y,int z)  
    {  
        a=x;  
        b=y;  
        *p=z;  
    }  
    void change(int n){
        *p=n;
    }
    void showdata()  
    {  
        std::cout << "value of a is : " <<a<< std::endl;  
        std::cout << "value of b is : " <<b<< std::endl;  
        std::cout << "value of *p is : " <<*p<< std::endl;  
    }  
};  
int main()  
{  
  Demo d1;  
  d1.setdata(4,5,7);  
  Demo d2 = d1;  
  d2.change(5);
  d2.showdata();  
  d1.showdata();
  //address of p is same fror both the obj
//   value of a is : 4
// value of b is : 5
// value of *p is : 5
// value of a is : 4
// value of b is : 5
// value of *p is : 5
    return 0;  
} 
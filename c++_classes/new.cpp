// https://www.javatpoint.com/cpp-copy-constructor

#include <iostream>  
using namespace std;  
class Demo  
{  
    public:  
    int a;  
    int b;  
    int *p;  
    int *g;
  
    Demo()  
    {  
        p=new int; 
        g=new int;  

    }  
    //notice that i have not done anything for g then also the memory allocation of g is diff for both the objects
    Demo(Demo &d)  
    {  
        a = d.a;  
        b = d.b;  
        p = new int;  
        *p = *(d.p);  
    }  
    void setdata(int x,int y,int z,int i)  
    {  
        a=x;  
        b=y;  
        *p=z;  
        *g=i;
    }  
    void change(int n){
        *p=n;
    }
    void change1(int n){
        // *p=n;
        *g=n;
    }
    void showdata()  
    {  
        std::cout << "value of a is : " <<a<< std::endl;  
        std::cout << "value of g is : " <<*g<< std::endl;  
        std::cout << "value of b is : " <<b<< std::endl;  
        std::cout << "value of *p is : " <<*p<< std::endl;  
    }  
};  
int main()  
{  
  Demo d1;  
  d1.setdata(4,5,7,10);  
  Demo d2 = d1;  
  d2.change(5);
  d2.change1(1);

  d2.showdata();  
  d1.showdata();

  //address of p is different fror both the obj

    // value of a is : 4
    // value of g is : 0x7ffdae657a80
    // value of b is : 5
    // value of *p is : 5
    // value of a is : 4
    // value of g is : 0x55b78a726ed0
    // value of b is : 5
    // value of *p is : 7
  return 0;  
}  
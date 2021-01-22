#include <bits/stdc++.h>
#include <complex.h>
using namespace std;
class A
{

    int a,b;

    public:

    void setdata(int x,int y)
    {
        a=x;
        b=y;
    }

    A operator+(A c)
    {
        A temp;
        temp.a=a+c.a;
        temp.b=b+c.b;
        return temp;
    }
    void show()
    {
        cout<< a << "+"<<" i"<<b;
    }
};

int main(){

    A c1,c2,c3;
    c1.setdata(1,2);
    c2.setdata(3,4);
    c3=c1+c2;
    c3.show();


}
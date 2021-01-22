#include <bits/stdc++.h>
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
        cout<< a << "+"<<" i"<<b <<endl;
    }
};

int main(){

    A c1,c2,c3,c4;
    c1.setdata(1,2);
    c2.setdata(3,4);
    c3=c1+c2;//overloading of a binary operator which requires two arguments first is the caller object and the second is the object on which the operation is performed
    c4 = c1.operator+(c2);
    c3.show();
    c4.show();
    //same output


}
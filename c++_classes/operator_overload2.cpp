// operator overloading of a unary operator -
#include<bits/stdc++.h>

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

    A operator-()
    {
        A temp;
        temp.a=-a;
        temp.b=-b;
        return temp;
    }
    void show()
    {
        cout<< a << " "<<b <<endl;
    }
};

int main(){

    A c1,c3;
    c1.setdata(1,2);
    c3=c1.operator-();//overloading of a binary operator which requires two arguments first is the caller object and the second is the object on which the operation is performed
    c3.show();
    //same output


}
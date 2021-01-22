// how to make the complier differentiate that ++ is a pre or a post operator??

#include<bits/stdc++.h>

using namespace std;

class A
{

    int a;

    public:

    void setdata(int x)
    {
        a=x;
    }
    friend A operator++( A obj1);


    void show()
    {
        cout<< a  <<endl;
    }
};

A operator++( A obj1)//pre
    {
        ++obj1.a;
        return obj1;
    }

int main(){

    A c0,c1,c2,c3;

    c0.setdata(1);

    c1.setdata(1);

    c2=++c1;
    c2.show();//2
    c1.show();//2 
    // c3=c0++;
    // c3.show();//1


}
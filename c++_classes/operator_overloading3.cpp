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

    A operator++()//pre
    {
        A temp;
        temp.a=++a;
        return temp;
    }

    A operator++(int)//post
    {
        A temp;
        temp.a=a++;
        return temp;
    }

    void show()
    {
        cout<< a  <<endl;
    }
};

int main(){

    A c0,c1,c2,c3;

    c0.setdata(1);

    c1.setdata(1);

    c2=++c1;
    c2.show();//2
    c1.show();//2 
    c3=c0++;
    c3.show();//1


}
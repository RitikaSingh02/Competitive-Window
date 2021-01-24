//https://www.youtube.com/watch?v=0IR_D1qZy2g&list=PLLYz8uHU480j37APNXBdPz7YzAi4XlQUF&index=46&ab_channel=C%2B%2BbySaurabhShuklaSir
#include<bits/stdc++.h>

using namespace std;

class A
{

    public:
    virtual void fun()=0;//pure virtual func( ie a  func with no definition) // or a do nothing func
    void fun1()
    {
        cout<<"I AM A NON PURE VIRTUAL FUNCTION";
    }
};

int main(){
    return 0;
}

// so class A is an abstract class which is a class that has atleast one or more than pure virtual func and we can not any
// object of this class

// so to access any func of this class we have to create the child classes in order to access the non pure virual func of this class A
// here function fun1
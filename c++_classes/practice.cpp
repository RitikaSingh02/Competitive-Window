#include <bits/stdc++.h>
using namespace std;

class C1
{
    int i = 0; //by default the classes are private so the var / data members are privateonly // ENCAPSULATION

public:
    C1(int i)
    {
        i = 2;
    }
    //https://www.geeksforgeeks.org/can-constructor-private-cpp/
    void setval(int val)
    {
        i = val;
    }
    int getval()
    {
        return i;
    }
    void printval();
};

void C1 ::printval()
{
    cout << i;
}
int main()
{
    int i = 1;
    C1 obj(i);
    obj.setval(i);
    cout << obj.getval();
    obj.printval();

    return 0;
}
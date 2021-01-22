#include <iostream>    
using namespace std;    
class Box    
{    
    int length;    
        
    public:    
        Box(): length(0) { }    
        friend int printLength(Box); //friend function    
        int getlen()
        {
            return length;
        }
};    
int printLength(Box b)    
{    
   b.length += 10;    
    return b.length;    
}    
int main()    
{    
    Box b;    
    cout<<"Length of box: "<< printLength(b)<<endl;    //10
    cout<<"Length of box: "<< b.getlen()<<endl;    //0

    return 0;    
} 

// friend func is not the member func of a class to which it is friend
// it must be defined outside the class to which it is a friend
// they can access the members but not directly like the member func do
// it isdeclared in the class with the keyword friend
// it has no caller object
// it should not be defined with the membership label
// a same friend function can become friend of more than one class


//friend func / class can access the private/protected members of the class
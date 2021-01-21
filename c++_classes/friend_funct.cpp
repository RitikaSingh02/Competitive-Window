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

//friend func / class can access the private/protected members of the class
//template is a keyword in c++ which makes us form the template class or template func

//https://www.youtube.com/watch?v=xNBWR_uFqQ8&list=PLLYz8uHU480j37APNXBdPz7YzAi4XlQUF&index=47
//for example the forms in banks

//like for eaxmple like if u are bound to do function overloading because of
// different types of parameters but the no and code in the function is same
// so in this case we need to have a generalised func using template func

#include <bits/stdc++.h>

using namespace std;

template <class X> // a func template also called generic func
X big(X a, X b)
{
    if (a > b)
        return a;
    else
        return b;
}

template <class X, class Y> // a func template also called generic func
Y big1(X a, Y b)
{
    if (a > b)
        return a;
    else
        return b;
}

template <class X, class Y> // a func template also called generic func
X big2(X a, Y b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main()
{
    cout << big(5, 4) << endl;
    cout << big(5.8, 6.9) << endl;

        // below two are important
    cout << big1(5, 5.4) << endl; //5.4
    cout << big2(5, 5.4) << endl; //5

    return 0;
}
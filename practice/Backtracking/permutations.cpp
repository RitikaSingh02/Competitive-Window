#include <bits/stdc++.h>
#define ll long long
using namespace std;

//when ever u do permutations and if u are free to choose strings then do it coz in arrays once the positions are changed
//u have to backtrck the changes

///NO BACKTRACKING while USING STRINGS AS SFTER EACH LEVEL THE STRING IS NOT CHANGES

// void permutation(string test, int start)
// {
//base case
//     if (start == test.size() - 1)
//     {
//         cout << test << "\n";
//         return;
//     }

//recursive case

//     for (int j = start; j < test.size(); j++)
//     {
//         swap(test[start], test[j]);
//         permutation(test, start + 1);
//     }
// }

// int main()
// {
//     string s;
//     cin >> s;

//     permutation(s, 0);

//     return 0;
// }

///YES BACKTRACKING while USING ARRAYS WE HAVE TO RESTORE THE ORIGINAL ARRAY

void permutation(char *test, int start)
{
    //base case
    if (test[start] == '\0')
    {
        cout << test << "\n";
        return;
    }

    //recursive case

    for (int j = start; test[j] != '\0'; j++)
    {
        swap(test[start], test[j]);
        permutation(test, start + 1);
        swap(test[start], test[j]); //for backtracking
    }
}

int main()
{
    char s[100];
    cin >> s;

    permutation(s, 0);

    return 0;
}
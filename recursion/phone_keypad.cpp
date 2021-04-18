#include <bits/stdc++.h>
#define ll long long
using namespace std;

unordered_map<char, string> user = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
vector<string> vec;
void phone_book(string in, char out[], int i, int j, unordered_map<char, string> hash)
{
    //base case
    if (in[i] == '\0')
    {
        out[j] = '\0';
        vec.push_back(out);
        // cout << out << endl;
        return;
    }
    //rec case
    char digit = in[i];
    for (int k = 0; in[k] != '\0'; k++)
    {
        out[j] = hash[digit][k];
        //fill the rest part
        phone_book(in, out, i + 1, j + 1, hash);
    }
}
int main()
{
    string in = "23";
    char out[100];
    phone_book(in, out, 0, 0, user);
    for (auto i : vec)
    {
        cout << i << endl;
    }
    return 0;
}

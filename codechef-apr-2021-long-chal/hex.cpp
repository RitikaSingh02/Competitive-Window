#include <bits/stdc++.h>
#define ll long long

using namespace std;

string decToBinary(int n)
{

    std::vector<int> binaryNum;
    if (n == 0)
        return "0";
    while (n > 0)
    {

        binaryNum.push_back(n % 2);
        n = n / 2;
    }

    string res = "";
    for (int j = binaryNum.size() - 1; j >= 0; j--)
        res += to_string(binaryNum[j]);

    return res;
}
bool isSubsequence(string s, string t)
{
    // find the size of the substring
    int sz = s.size();

    // empty string is a substring of all the strings
    if (sz == 0)
    {
        return true;
    }

    // take index of the substring to be 0
    int indx = 0;

    // iterate over the actual given string
    for (int i = 0; i < t.size(); i++)
    {

        // if the substring character at `indx` is same as the ith caharcter of the given string
        if (t[i] == s[indx])
        {

            // go to the next index of the substring
            indx++;
        }

        // as soon as we finish finding all the characters of the substring
        if (indx >= sz)
        {

            // that means the substring is present in the given string
            return true;
        }
    }

    // if we iterated over all the given string and still couldn't find all the substring characters
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int i = 0;
        while (true)
        {
            // cout<<"b";
            string res = decToBinary(i);
            // cout << "\nbinary" << res << "\n";

            if (isSubsequence(res, s) == false)
            {
                cout << res << "\n";
                break;
            }
            i++;
        }
    }

    return 0;
}

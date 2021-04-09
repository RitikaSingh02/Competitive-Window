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
bool counter = true;

string Subsequences(string s, string search, string out)
{
    int len = s.size();
    int search_size = search.size();
    cout << "search" << search << "\n";
    string sub = "";

    if (out == search)
    {
        counter = true;
        return out;
    }

    Subsequences(s.substr(1), search, out + s[0]);

    // output is passed without
    // including the Ist character
    // of Input string
    Subsequences(s.substr(1), search, out);

    // return false;
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
            cout << "binary" << res << "\n";
            Subsequences(s, res, "");
            if (counter == false)
            {
                cout << "\n"
                     << "res" << res << "\n";
                break;
            }
            i++;
        }
    }

    return 0;
}

/* Code By kosnoa
GitHub : kosnoa */


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;


int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    string s;
    getline(cin, s);

    int n=0, m=0;

    for (int i=0; i<s.length(); i++)
    {
        if (i<s.length()-3 && s[i] == ':' && s[i+1] == '-' && s[i+2] == ')')
        {
            n++;
        }
        else if (i<s.length()-3 && s[i] == ':' && s[i+1] == '-' && s[i+2] == '(')
        {
            m++;
        }
    }

    if (!n && !m)
    {
        cout << "none" << '\n';
    }
    else if (n==m)
    {
        cout << "unsure" << '\n';
    }
    else if (n > m)
    {
        cout << "happy" << '\n';
    }
    else
    {
        cout << "sad" << '\n';
    }

    return 0;
}
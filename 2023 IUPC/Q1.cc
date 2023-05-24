/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    string s;
    cin >> s;
    bool c[5];
    memset(c, false, sizeof(c));
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'M')
        {
            c[0] = true;
        }
        else if (s[i] == 'O')
        {
            c[1] = true;
        }
        else if (s[i] == 'B')
        {
            c[2] = true;
        }
        else if (s[i] == 'I')
        {
            c[3] = true;
        }
        else if (s[i] == 'S')
        {
            c[4] = true;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        if (!c[i])
        {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

    return 0;
}
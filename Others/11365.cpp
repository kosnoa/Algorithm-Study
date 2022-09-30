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
    while (1)
    {
        getline(cin, s);

        if (s == "END")
        {
            break;
        }
        else
        {
            reverse(s.begin(), s.end());
            cout << s;
        }
        cout << '\n';
    }

    return 0;
}
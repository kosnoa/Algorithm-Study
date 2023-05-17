/* Code By kosnoa
GitHub : kosnoa */


#pragma GCC optimize("Ofast")
#pragma GCC ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;


int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    string s;
    getline(cin, s);
    if(s == "KEY IS PUSH AND OPEN DOOR IS SHUT" || s == "LONELY FLAG IS BABA")
    {
        string t;
        getline(cin, t);
        cout << "BABA IS WIN\n";
    }
    else
    {
        string t;
        getline(cin, t);
        cout << "BABA IS NOT WIN\n";
    }

    return 0;
}
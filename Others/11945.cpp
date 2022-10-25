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

    int a, b;
    cin >> a >> b;

    string s;

    vector<string> v;

    for (int i = 0; i < a; i++)
    {
        cin >> s;
        v.push_back(s);
    }

    for (int i = 0; i < a; i++)
    {

        reverse(v[i].begin(), v[i].end());
        cout << v[i] << "\n";
    }


    return 0;
}
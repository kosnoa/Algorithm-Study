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

    int n;
    cin >> n;
    vector<string> str(n);

    for(auto &i : str)
    {
        cin >> i;
    }

    sort(str.begin(), str.end());

    for(auto i : str)
    {
        cout << i << ' ';
    }

    return 0;
}
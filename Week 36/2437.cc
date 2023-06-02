/* Code By kosnoa
GitHub : kosnoa */


#pragma GCC optimize("Ofast")
#pragma GCC ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
int n, res = 1;
vector<ll> vec;


int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;
    vec = vector<ll>(n);

    for(auto &i : vec)
    {
        cin >> i;
    }

    sort(vec.begin(), vec.end());

    for(int i = 0; i < n; i++)
    {
        if(res < vec[i])
        {
            break;
        }
        res += vec[i];
    }

    cout << res;


    return 0;
}
/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

int n;
ll fuel[100001];
ll dist[100001];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> dist[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> fuel[i];
    }

    ll z = 1, m = fuel[0], res = fuel[0] * dist[0];

    for(int i = 1; i < n; i++)
    {
        if(m * dist[z] > fuel[i] * dist[z])
        {
            m = fuel[i];
        }

        res += m * dist[z];
        z++;
    }

    cout << res << '\n';

    return 0;
}
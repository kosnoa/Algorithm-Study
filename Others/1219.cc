/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
int n, s, e, m;

struct price
{
    int p1;
    int p2;
    int cost;
};
vector<price> v;
ll arr[51];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> s >> e >> m;

    for (int i = 0; i < n; i++)
    {
        int p, q, r;
        cin >> p >> q >> r;
        v.push_back({p, q, r});
    }

    

    return 0;
}
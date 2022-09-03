/* Code By kosnoa
GitHub: kosnoa */


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

ll n, m;
queue<pair<ll, ll>> q;
vector<ll> v;


int bfs(ll x, ll y)
{
    q.push({x, 1});

    while(!q.empty())
    {
        pair<ll, ll> cur = q.front();
        q.pop();

        if (cur.first == y)
        {
            return cur.second;
        }

        if (cur.first*2 <= y)
        {
            q.push({cur.first*2, cur.second+1});
        }

        if (cur.first*10 + 1 <= y)
        {
            q.push({cur.first*10+1, cur.second+1});
        }
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m;
    cout << bfs(n, m) << '\n';

    return 0;
}
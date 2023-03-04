/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
int n, m, k;
vector<pair<ll, ll>> graph[10001];
ll d[10005][25];
ll ans = 1e15;

/*
3 3 1
1 2 10
1 3 1
2 3 1

답 0
출력 1
*/

void dijkstra()
{
    priority_queue<tuple<ll, ll, ll>> pq;
    pq.push({0, 1, 0});
    d[1][0] = 0;

    while (!pq.empty())
    {
        ll dist = -get<0>(pq.top());
        int cur = get<1>(pq.top());
        int cnt = get<2>(pq.top());
        pq.pop();
        if (d[cur][cnt] < dist)
        {
            continue;
        }

        for (int i = 0; i < graph[cur].size(); i++)
        {
            int node = graph[cur][i].first;
            ll cost = dist + graph[cur][i].second;

            if (cost < d[node][cnt])
            {
                d[node][cnt] = cost;
                pq.push({-cost, node, cnt});
            }

            if (dist < d[node][cnt + 1] && cnt + 1 <= k)
            {
                d[node][cnt + 1] = dist;
                pq.push({-dist, node, cnt + 1});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    fill(&d[0][0], &d[10004][25], 1e15);

    dijkstra();

    for (int i=0; i<=k; i++)
    {
        ans = min(ans, d[n][i]);
    }

    cout << ans << '\n';

    return 0;
}
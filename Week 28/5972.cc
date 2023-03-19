/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
int n, m;
vector<pair<ll, ll>> graph[50005];
int dist[50005];

void dijkstra()
{
    priority_queue<pair<ll, ll>> pq;
    pq.push({0, 1});
    dist[1] = 0;

    while (!pq.empty())
    {
        int d = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if(dist[cur] < d)
        {
            continue;
        }

        for (int i=0; i<graph[cur].size(); i++)
        {
            int cost = d + graph[cur][i].second;
            if (cost < dist[graph[cur][i].first])
            {
                dist[graph[cur][i].first] = cost;
                pq.push({-cost, graph[cur][i].first});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    fill(dist, dist + 50005, 1e9);

    dijkstra();

    cout << dist[n] << '\n';

    return 0;
}
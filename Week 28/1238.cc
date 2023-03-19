/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
vector<pair<ll, ll>> graph[10001];
ll dist[10001];
ll dist2[10001];
int n, m, t, depart = -1;

void dijkstra(int x)
{
    priority_queue<pair<ll, ll>> pq;
    pq.push({0, x});
    dist[x] = 0;

    while (!pq.empty())
    {
        int d = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < d)
        {
            continue;
        }

        for (int i = 0; i < graph[cur].size(); i++)
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

void dijkstra2()
{
    priority_queue<pair<ll, ll>> pq;
    pq.push({0, t});
    dist2[t] = 0;

    while (!pq.empty())
    {
        int d = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist2[cur] < d)
        {
            continue;
        }

        for (int i = 0; i < graph[cur].size(); i++)
        {
            int cost = d + graph[cur][i].second;

            if (cost < dist2[graph[cur][i].first])
            {
                dist2[graph[cur][i].first] = cost;
                pq.push({-cost, graph[cur][i].first});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m >> t;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    for (int i = 1; i <= n; i++)
    {
        fill(dist, dist + 10001, 1e9);
        fill(dist2, dist2 + 10001, 1e9);
        dijkstra(i);
        dijkstra2();
        if (depart < dist[t] + dist2[i])
        {
            depart = dist[t] + dist2[i];
        }
    }

    cout << depart << '\n';

    return 0;
}
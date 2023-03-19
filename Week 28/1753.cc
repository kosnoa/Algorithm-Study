/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
int n, m, start;
vector<pair<ll, ll>> graph[100001];
int dist[100001];

void dijkstra()
{
    priority_queue<pair<ll, ll>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while(!pq.empty())
    {
        int d = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (dist[cur] < d)
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
    cin >> n >> m >> start;

    for (int i = 0; i < m; i++)
    {
        int point1, point2, cost;
        cin >> point1 >> point2 >> cost;
        graph[point1].push_back({point2, cost});
    }

    fill(dist, dist + 100001, 1e9);

    dijkstra();

    for (int i=1; i<=n; i++)
    {
        if (dist[i] == 1e9)
        {
            cout << "INF\n";
        }
        else
        {
            cout << dist[i] << '\n';
        }
    }

    return 0;
}
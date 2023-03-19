/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
vector<pair<ll, ll>> graph[801];
ll d[801];
ll n, m, point1, point2, val1, val2;

void dijkstra(int x)
{
    priority_queue<pair<ll, ll>> pq;
    pq.push({0, x});
    d[x] = 0;

    while (!pq.empty())
    {
        int dist = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        for (int i = 0; i < graph[cur].size(); i++)
        {
            int cost = dist + graph[cur][i].second;

            if (cost < d[graph[cur][i].first])
            {
                d[graph[cur][i].first] = cost;
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

    cin >> point1 >> point2;

    fill(d, d + 801, 1e9);
    dijkstra(1);
    val1 += d[point1];

    fill(d, d + 801, 1e9);
    dijkstra(point1);
    val1 += d[point2];

    fill(d, d + 801, 1e9);
    dijkstra(point2);
    val1 += d[n];

    //

    fill(d, d + 801, 1e9);
    dijkstra(1);
    val2 += d[point2];

    fill(d, d + 801, 1e9);
    dijkstra(point2);
    val2 += d[point1];

    fill(d, d + 801, 1e9);
    dijkstra(point1);
    val2 += d[n];

    if (val1 >= 1e9 && val2 >= 1e9)
    {
        cout << -1 << '\n';
    }
    else
    {
        if (val1 > val2)
        {
            cout << val2 << '\n';
        }
        else
        {
            cout << val1 << '\n';
        }
    }

    return 0;
}
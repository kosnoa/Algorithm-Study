/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
int n, m, start, fin;
vector<pair<ll, ll>> graph[100001];
ll dist[100001][3];

void dijkstra()
{
    priority_queue<pair<ll, ll>> pq;
    pq.push({0, start});
    dist[start][0] = 0;

    while (!pq.empty())
    {
        int d = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (dist[cur][0] < d)
        {
            continue;
        }

        for (int i = 0; i < graph[cur].size(); i++)
        {
            int cost = d + graph[cur][i].second;

            if (cost < dist[graph[cur][i].first][0])
            {
                dist[graph[cur][i].first][0] = cost;
                dist[graph[cur][i].first][1] = dist[cur][1] + 1;
                dist[graph[cur][i].first][2] = cur;
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
        int point1, point2, cost;
        cin >> point1 >> point2 >> cost;
        graph[point1].push_back({point2, cost});
    }

    cin >> start >> fin;

    for (int i = 0; i < 100001; i++)
    {
        dist[i][0] = 1e9;
    }

    dijkstra();

    cout << dist[fin][0] << '\n';
    cout << dist[fin][1] + 1 << '\n';
    int tmp = fin;
    vector<ll> v;
    for (int i = 0; i < dist[fin][1]; i++)
    {
        v.push_back(dist[tmp][2]);
        tmp = dist[tmp][2];
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ' ';
    }
    cout << fin << ' ';

    return 0;
}
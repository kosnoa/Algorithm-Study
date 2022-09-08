/* Code By kosnoa
GitHub: kosnoa */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

bool visited[1005][1005];
int n, m;
bool found = false;
vector<pair<int, int>> vp[1000001];
queue<pair<int, int>> qp;

void bfs(int x, int y)
{
    qp.push({x, y});

    while (!found && !qp.empty())
    {
        int nx = qp.front().first;
        int ny = qp.front().second;
        qp.pop();

        if (nx == 1 && ny == 1)
        {
            found = true;
            return;
        }

        if (!visited[nx][ny])
        {
            visited[nx][ny] = true;

            for (int i = 0; i < vp[nx * ny].size(); i++)
            {
                qp.push({vp[nx * ny][i].first, vp[nx * ny][i].second});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int t;
            cin >> t;
            vp[t].push_back({i, j});
        }
    }

    bfs(n, m);

    if (found)
    {
        cout << "yes" << '\n';
    }
    else
    {
        cout << "no" << '\n';
    }

    return 0;
}
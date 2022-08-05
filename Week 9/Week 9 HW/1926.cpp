/* Code By kosnoa
GitHub: kosnoa */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

int arr[500][500];
bool visited[500][500];
ll res[500*500];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
ll n, m, c=0;

void dfs(int x, int y)
{
    res[c]++;
    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        ll nx = x + dx[i];
        ll ny = y + dy[i];

        if (0 <= nx && nx < n && 0 <= ny && ny < m)
        {
            if (arr[nx][ny] == 1 && visited[nx][ny] == false)
            {
                dfs(nx, ny);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m;
    ll max = 0;

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (arr[i][j] == 1 && visited[i][j] == false)
            {
                c++;
                dfs(i, j);

                if (res[c] > max)
                {
                    max = res[c];
                }
            }
        }
    }

    cout << c << '\n';
    cout << max << '\n';

    return 0;
}
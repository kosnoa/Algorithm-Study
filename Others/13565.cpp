/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int arr[1001][1001];
bool check[1001][1001];
bool arrived = false;
int n, m;

void dfs(int y, int x)
{
    check[y][x] = true;

    if (y == m - 1)
    {
        arrived = true;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
        {
            continue;
        }

        if (arr[ny][nx] == 0 && !check[ny][nx])
        {
            dfs(ny, nx);
        }
    }
}

int main()
{
    cin >> m >> n;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%1d", &arr[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[0][i] == 0)
        {
            dfs(0, i);

            if (arrived)
            {
                cout << "YES\n";
                return 0;
            }

            memset(check, sizeof(check), false);
        }
        else
        {
            continue;
        }
    }

    cout << "NO\n";

    return 0;
}
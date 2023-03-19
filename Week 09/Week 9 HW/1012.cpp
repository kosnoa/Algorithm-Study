/* Code By kosnoa
GitHub: kosnoa */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

int arr[51][51];
bool visited[51][51];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, m, k;

void dfs(int x, int y)
{
    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

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

    int t;
    cin >> t;

    while (t--)
    {
        int c = 0;

        cin >> n >> m >> k;
        for (int i = 0; i < k; i++)
        {
            int a, b;
            cin >> a >> b;
            arr[a][b] = 1;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == 1 && visited[i][j] == false)
                {
                    c++;
                    dfs(i, j);
                }
            }
        }

        cout << c << '\n';

        memset(arr, 0, sizeof(arr));
        memset(visited, false, sizeof(visited));
    }

    return 0;
}
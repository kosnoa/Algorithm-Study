/* Code By kosnoa
GitHub : kosnoa */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
int arr[101][101];
bool visited[101][101];
int res[100 * 100];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, m, k, c;

void dfs(int x, int y)
{
    visited[x][y] = true;
    res[c]++;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 <= nx && nx < n && 0 <= ny && ny < m)
        {
            if (arr[nx][ny] == 1 && !visited[nx][ny])
            {
                dfs(nx, ny);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    memset(arr, 1, sizeof(arr));

    cin >> n >> m >> k;

    while (k--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        for (int i = a; i <= c; i++)
        {
            for (int j = b; j <= d; j++)
            {
                arr[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1 && !visited[i][j])
            {
                c++;
                dfs(i, j);
            }
        }
    }

    cout << c << '\n';

    sort(res + 1, res + c + 1);

    for (int i = 1; i <= c; i++)
    {
        cout << res[i] << ' ';
    }

    return 0;
}
/* Code By kosnoa
GitHub : kosnoa */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

int arr[101][101];
bool visited[101][101];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, max_height = 0, min_height = 0;

void dfs(int x, int y)
{
    visited[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 <= nx && nx < n && 0 <= ny && ny < n)
        {
            if (arr[nx][ny] > min_height && !visited[nx][ny])
            {
                dfs(nx, ny);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] > max_height)
            {
                max_height = arr[i][j];
            }

        }
    }

    int tmp = max_height + 1;
    int res[tmp];

    memset(res, 0, sizeof(res));

    while (max_height >= min_height)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] > min_height && !visited[i][j])
                {
                    res[min_height]++;
                    dfs(i, j);
                }
            }
        }
        min_height++;
        memset(visited, false, sizeof(visited));
    }

    int ans = 0;

    for (int i = 0; i < tmp; i++)
    {
        if (res[i] > ans)
        {
            ans = res[i];
        }
    }

    cout << ans << '\n';

    return 0;

}
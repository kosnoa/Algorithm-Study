/* Code By kosnoa
GitHub : kosnoa */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
int arr[105][105];
bool visited[105][105];
vector<int> res;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, m, k, c;

void dfs(int x, int y)
{
    visited[x][y] = true;
    c++;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 <= nx && nx < m && 0 <= ny && ny < n)
        {
            if (arr[nx][ny] == 0 && !visited[nx][ny])
            {
                dfs(nx, ny);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    memset(arr, 0, sizeof(arr));

    cin >> m >> n >> k;

    while (k--)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int i = y1; i < y2; i++)
        {
            for (int j = x1; j < x2; j++)
            {
                arr[i][j] = 1;
                visited[i][j];
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 0 && !visited[i][j])
            {
                c=0;
                dfs(i, j);
                res.push_back(c);
            }
        }
    }

    cout << res.size() << '\n';

    sort(res.begin(), res.end());

    for (auto i : res)
    {
        cout << i << ' ';
    }
    

    return 0;
}
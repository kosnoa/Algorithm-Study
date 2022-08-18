/* Code By kosnoa
GitHub: kosnoa */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

int arr[126][126];
int tmp[126][126];
bool visited[126][126];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, cnt = 0;
queue<pair<int, int>> qp;

void bfs(int x, int y)
{
    tmp[x][y] = arr[x][y];
    visited[x][y] = true;
    qp.push({x, y});

    while (!qp.empty())
    {
        int x = qp.front().first;
        int y = qp.front().second;
        qp.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 <= nx && nx < n && 0 <= ny && ny < n)
            {
                visited[nx][ny] = true;
                tmp[nx][ny] += arr[x][y];
                qp.push({nx, ny});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    while (cin >> n)
    {
        cnt++;
        if (n == 0)
        {
            break;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cin >> arr[i][j];
                }
            }

            bfs(0, 0);

            cout << "Problem " << cnt << ": " << tmp[n - 1][n - 1] << '\n';

            memset(arr, 0, sizeof(arr));
            memset(tmp, 0, sizeof(tmp));
            memset(visited, false, sizeof(visited));
        }
    }

    return 0;
}
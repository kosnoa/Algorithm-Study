/* Code By kosnoa
GitHub: kosnoa */

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;

int arr[126][126];
int tmp[126][126];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, cnt = 1;
queue<pair<int, int>> qp;

void bfs(int x, int y)
{
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
                if (tmp[nx][ny] > arr[nx][ny] + tmp[x][y])
                {
                    tmp[nx][ny] = arr[nx][ny] + tmp[x][y];
                    qp.push({nx, ny});
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    while (true)
    {
        cin >> n;

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

            fill(&tmp[0][0], &tmp[125][126], 1126);
            tmp[0][0] = arr[0][0];

            bfs(0, 0);

            cout << "Problem " << cnt << ": " << tmp[n - 1][n - 1] << '\n';

            cnt++;
            memset(arr, 0, sizeof(arr));
            fill(&tmp[0][0], &tmp[125][126], 1126);
        }
    }

    return 0;
}
/* Code By kosnoa
GitHub: kosnoa */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

int arr[1001][1001];
bool visited[1001][1001];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int n, m, c = 0, cnt, day;
bool temp;
queue<pair<int, int>> tmp;
queue<pair<int, int>> qp;


void bfs(int x, int y)
{
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

            if (0 <= nx && nx < n && 0 <= ny && ny < m && arr[nx][ny] == 0)
            {
                arr[nx][ny]++;
                tmp.push({nx, ny});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> m >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];

            if (arr[i][j] == 1)
            {
                tmp.push({i, j});
            }
        }
    }

    day = tmp.size();

    while (!tmp.empty())
    {
        for (int i = 0; i < day; i++)
        {
            bfs(tmp.front().first, tmp.front().second);
            tmp.pop();
        }
        c++;
        day = tmp.size();
    }

    int res1 = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                temp = true;
                res1++;
            }
        }
        if (i == n - 1 && res1 == 0)
        {
            temp = false;
        }
    }

    if (!temp)
    {
        cout << c - 1 << '\n';
    }
    else
    {
        cout << "-1" << '\n';
    }

    return 0;
}
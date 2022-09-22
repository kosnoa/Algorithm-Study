/* Code By kosnoa
GitHub: kosnoa */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

int arr[101][101][101];
bool visited[101][101][101];
int dx[] = {-1, 1, 0, 0, 0, 0};
int dy[] = {0, 0, 0, 0, -1, 1};
int dz[] = {0, 0, -1, 1, 0, 0};
int n, m, h, c = 0, cnt, day;
bool temp;
queue<tuple<ll, ll, ll>> tmp;
queue<tuple<ll, ll, ll>> qp;

void bfs(int x, int y, int z)
{
    visited[x][y][z] = true;
    qp.push(make_tuple(x, y, z));

    while (!qp.empty())
    {
        int x = get<0>(qp.front());
        int y = get<1>(qp.front());
        int z = get<2>(qp.front());
        qp.pop();

        for (int i = 0; i < 6; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if (0 <= nx && nx < n && 0 <= ny && ny < m && 0 <= nz && nz < h && arr[nx][ny][nz] == 0)
            {
                arr[nx][ny][nz]++;
                tmp.push(make_tuple(nx, ny, nz));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> h >> m >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < h; k++)
            {
                cin >> arr[i][j][k];

                if (arr[i][j][k] == 1)
                {
                    tmp.push(make_tuple(i, j, k));
                }
            }
        }
    }

    day = tmp.size();

    while (!tmp.empty())
    {
        for (int i = 0; i < day; i++)
        {
            bfs(get<0>(tmp.front()), get<1>(tmp.front()), get<2>(tmp.front()));
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
            for (int k = 0; k < h; k++)
            {
                if (arr[i][j][k] == 0)
                {
                    temp = true;
                    res1++;
                }
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
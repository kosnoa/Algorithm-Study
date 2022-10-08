
#include <iostream>
#include <queue>
using namespace std;

int map[1000][1000];
int check[1000][1000];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, m;

queue<pair<int, int>> qp;

// qp : 3, 3
// p : 1, 1

void bfs()
{
    while (!qp.empty())
    {
        pair<int, int> p;
        p = qp.front();
        qp.pop();
        if (map[p.first][p.second] == 3)
            continue;

        for (int i = 0; i < 4; i++)
        {
            int nx = p.first + dx[i];  // nx : 0
            int ny = p.second + dy[i]; // ny : 1
            if (0 <= nx && nx < n && 0 <= ny && ny < m)
            {
                if (map[p.first][p.second] == map[nx][ny])
                    continue;

                if (map[nx][ny] == 0)
                {
                    map[nx][ny] = map[p.first][p.second];         // map[0][1] : 1
                    check[nx][ny] = check[p.first][p.second] + 1; // check[0][1] : 0
                    qp.push({nx, ny});
                }
                else if (check[p.first][p.second] + 1 == check[nx][ny])
                {
                    map[nx][ny] = 3;
                }
            }
        }
    }
}
int main()
{

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] > 0)
            {
                qp.push({i, j});
            }
        }
    }

    bfs();

    int a = 0, b = 0, c = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 1)
            {
                a++;
            }
            else if (map[i][j] == 2)
            {
                b++;
            }
            else if (map[i][j] == 3)
            {
                c++;
            }
        }
    }
    cout << a << " " << b << " " << c;
    return 0;
}

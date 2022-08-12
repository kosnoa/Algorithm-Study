#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int map[25][25];
bool visited[25][25];
int result[25 * 25];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, c;

queue<pair<int, int>> qp;

void bfs(int x, int y)
{
    visited[x][y] = true;
    qp.push({x, y}); // qp : 0 1
    while (!qp.empty())
    {
        int first = qp.front().first;
        int second = qp.front().second;
        result[c]++;
        qp.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = first + dx[i];  // 1
            int ny = second + dy[i]; // 1
            if (0 <= nx && nx < n && 0 <= ny && ny < n)
            {
                if (map[nx][ny] == 1 && !visited[nx][ny])
                {
                    qp.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%1d", &map[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == 1 && !visited[i][j])
            {
                c++;
                bfs(i, j);
            }
        }
    }
    cout << c << endl;
    sort(result + 1, result + c + 1);
    for (int i = 1; i <= c; i++)
    {
        cout << result[i] << endl;
    }

    return 0;
}
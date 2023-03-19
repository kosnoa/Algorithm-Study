#include <iostream>
#include <algorithm>

using namespace std;

int map[25][25];
bool visited[25][25];
int res[25 * 25];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, c;

void dfs(int x, int y)
{
    res[c]++;
    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < n)
        {
            if (map[nx][ny] == 1 && visited[nx][ny] == false)
            {
                dfs(nx, ny);
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
            if (map[i][j] == 1 && visited[i][j] == false)
            {
                c++; // 총 단지 갯수
                dfs(i, j);
            }
        }
    }
    cout << c << "\n";
    sort(res + 1, res + c + 1);
    for (int i = 1; i <= c; i++)
    {
        cout << res[i] << "\n";
    }
    return 0;
}

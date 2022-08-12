/* Code By kosnoa
GitHub : kosnoa */


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

// fill (arr, arr+301, 1) : 1차원 배열 초기화
// fill (&arr[0][0], &arr[300][301], 1) : 2차원 배열 초가화

int arr[301][301];
bool visited[301][301];
int dx[] = {2, 1, 2, 1, -1, -2, -2, -1};
int dy[] = {1, 2, -1, -2, -2, -1, 1, 2};
int n;
queue<pair<int, int>> qp;

void bfs(int x, int y)
{
    arr[x][y] = 0;
    visited[x][y] = true;
    qp.push({x, y});

    while(!qp.empty())
    {
        int x = qp.front().first;
        int y = qp.front().second;
        qp.pop();

        for(int i=0; i<8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 <= nx && nx < n && 0 <= ny && ny < n)
            {
                if (!visited[nx][ny])
                {
                    visited[nx][ny] = true;
                    arr[nx][ny] = arr[x][y] + 1;
                    qp.push({nx, ny});
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--)
    {
        int x1, y1, x2, y2;
        cin >> n;
        cin >> x1 >> y1 >> x2 >> y2;

        bfs(x1, y1);

        cout << arr[x2][y2] << '\n';

        memset(arr, 0, sizeof(arr));
        memset(visited, false, sizeof(visited));
    }


    return 0;
}
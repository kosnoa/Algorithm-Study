/* Code By kosnoa
GitHub: kosnoa */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

char arr[1001][1001];
bool visited[1001][1001];
vector<pair<int, int>> res(1000*1000);
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int n, c;

void count(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (-1 <= nx && nx <= n && -1 <= ny && ny <= n)
        {
            if (arr[nx][ny] != '#')
            {
                res[c].second++;
            }
        }
    }
    
}

void dfs(int x, int y)
{
    visited[x][y] = true;
    res[c].first++;
    count(x, y);

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 <= nx && nx < n && 0 <= ny && ny < n)
        {
            if (arr[nx][ny] == '#' && !visited[nx][ny])
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
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == '#' && !visited[i][j])
            {
                c++;
                dfs(i, j);
            }
        }
    }


    sort(res.rbegin(), res.rend());

    cout << res[0].first << ' ' << res[0].second << '\n';

    return 0;
}
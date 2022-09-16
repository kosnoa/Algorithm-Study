/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
char arr[500][500];
bool visited[500][500];
deque<char> dq;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
ll n, m;

void dfs(int x, int y)
{
    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 <= nx && nx < n * 2 && 0 <= ny && ny < m * 2)
        {
            if (arr[nx][ny] == '*' && !visited[nx][ny])
            {
                if (i == 0)
                {
                    dq.push_back('N');
                    dfs(nx, ny);
                }

                if (i == 1)
                {
                    dq.push_back('E');
                    dfs(nx, ny);
                }

                if (i == 2)
                {
                    dq.push_back('S');
                    dfs(nx, ny);
                }

                if (i == 3)
                {
                    dq.push_back('W');
                    dfs(nx, ny);
                }
            }
        }
    }
}

void Solve()
{
    bool check = false;
    cin >> n >> m;

    for (int i = 0; i < n*2; i+=2)
    {
        for (int j = 0; j < m*2; j+=2)
        {
            char a;
            cin >> a;

            if (a == '#')
            {
                arr[i][j] = '#';
                arr[i + 1][j] = '#';
                arr[i][j + 1] = '#';
                arr[i + 1][j + 1] = '#';
            }

            if (a == '*')
            {
                arr[i][j] = '*';
                arr[i + 1][j] = '*';
                arr[i][j + 1] = '*';
                arr[i + 1][j + 1] = '*';
            }
        }
    }

    dfs(0, 0);

    for (int i = 0; i < n * 2; i++)
    {
        for (int j = 0; j < m * 2; j++)
        {
            if (arr[i][j] == '*' && !visited[i][j])
            {
                cout << "IMPOSSIBLE" << '\n';
                check = true;
                break;
            }
        }
        if (check)
        {
            break;
        }
    }

    if (check)
    {
        fill(&arr[0][0], &arr[499][500], '0');
        memset(visited, sizeof(visited), false);
        while(!dq.empty())
        {
            dq.pop_back();
        }
    }
    else
    {
        for (int i=0; i<dq.size(); i++)
        {
            cout << dq.front();
            dq.pop_front();
        }
        cout << '\n';
        fill(&arr[0][0], &arr[499][500], '0');
        memset(visited, sizeof(visited), false);
        while(!dq.empty())
        {
            dq.pop_back();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";
        Solve();
    }

    return 0;
}
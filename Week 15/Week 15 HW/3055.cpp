/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

char arr[51][51];
int visited[51][51];
queue<pair<ll, ll>> water;
pair<ll, ll> start;
pair<ll, ll> finish;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
ll r, c;
bool check;

void bfs()
{
    queue<pair<ll, ll>> hedge;
    hedge.push(start);
    visited[start.first][start.second] = 1;

    while (!hedge.empty())
    {
        ll w_size = water.size();

        for (int i = 0; i < w_size; i++)
        {
            ll cur_water_x = water.front().first;
            ll cur_water_y = water.front().second;
            water.pop();

            for (int j = 0; j < 4; j++)
            {
                ll nx = cur_water_x + dx[j];
                ll ny = cur_water_y + dy[j];

                if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                {
                    continue;
                }

                if (arr[nx][ny] == '.')
                {
                    arr[nx][ny] = '*';
                    water.push({nx, ny});
                }
            }
        }

        ll h_size = hedge.size();

        for (int i = 0; i < h_size; i++)
        {
            ll cur_hedge_x = hedge.front().first;
            ll cur_hedge_y = hedge.front().second;
            hedge.pop();

            if (cur_hedge_x == finish.first && cur_hedge_y == finish.second)
            {
                cout << visited[cur_hedge_x][cur_hedge_y] - 1 << '\n';
                check = true;
                return;
            }

            for (int j = 0; j < 4; j++)
            {
                ll nx = cur_hedge_x + dx[j];
                ll ny = cur_hedge_y + dy[j];

                if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                {
                    continue;
                }

                if (arr[nx][ny] != '*' && arr[nx][ny] != 'X' && visited[nx][ny] == 0 )
                {
                    visited[nx][ny] = visited[cur_hedge_x][cur_hedge_y] + 1;
                    hedge.push({nx, ny});
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> r >> c;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];

            if (arr[i][j] == 'S')
            {
                start = make_pair(i, j);
            }
            else if (arr[i][j] == 'D')
            {
                finish = make_pair(i, j);
            }
            else if (arr[i][j] == '*')
            {
                water.push({i, j});
            }
        }
    }

    bfs();

    if (!check)
    {
        cout << "KAKTUS" << '\n';
    }

    return 0;
}
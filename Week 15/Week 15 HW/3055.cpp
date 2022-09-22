/* Code By kosnoa
GitHub : kosnoa */


#pragma GCC optimize("Ofast")
#pragma GCC ("unroll-loops")
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


void bfs()
{
    queue<pair<ll, ll>> hedge;
    hedge.push(start);
    visited[start.first][start.second] = 1;

    while (!hedge.empty())
    {
        ll w_size = water.size();

        for (int i=0; i<w_size; i++)
        {
            ll nx_water = water.front().first;
            ll ny_water = water.front().second;
            water.pop();

            for (int j=0; j<4; j++)
            {
                ll nx = nx_water + dx[j];
                ll ny = ny_water + dy[j];

                if (0 <= nx && nx < r && 0 <= ny && ny < c)
                {
                    if (arr[nx][ny] == '.')
                    {
                        arr[nx][ny] = '*';
                        water.push({nx, ny});
                    }
                }
                else
                {
                    continue;
                }
            }
        }

        ll h_size = hedge.size();

        for (int i=0; i<h_size; i++)
        {
            ll nx_hedge = hedge.front().first;
            ll ny_hedge = hedge.front().second;
            hedge.pop();

            if (nx_hedge == finish.first && ny_hedge == finish.second)
            {
                cout << visited[nx_hedge][ny_hedge] - 1 << '\n';
                return;
            }

            for (int j=0; j<4; j++)
            {
                ll nx = nx_hedge + dx[i];
                ll ny = ny_hedge + dy[i];
                
                if (0 <= nx && nx < r && 0 <= ny && ny < c)
                {
                    if (arr[nx][ny] != '*' && visited[nx][ny] == 0 && arr[nx][ny] != 'X')
                    {
                        arr[nx][ny] = arr[nx_hedge][ny_hedge] + 1;
                        hedge.push({nx, ny});
                    }
                }
                else
                {
                    continue;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> r >> c;

    for (int i=0; i<r; i++)
    {
        for (int j=0; j<c; j++)
        {
            cin >> arr[i][j];

            if (arr[i][j] == 'S')
            {
                start = make_pair(i, j);
            }

            if (arr[i][j] == 'D')
            {
                finish = make_pair(i, j);
            }

            if (arr[i][j] == '*')
            {
                water.push({i, j});
            }
        }
    }

    bfs();

    return 0;
}
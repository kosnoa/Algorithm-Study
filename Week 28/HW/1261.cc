/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
int n, m, ans = 1e9;
int arr[105][105];
bool check[105][105];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

struct node
{
    int x;
    int y;
    int cnt;

    node(int a, int b, int c) : x(a), y(b), cnt(c)
    {
    }
};

struct cmp
{
    bool operator()(node a, node b)
    {
        return a.cnt > b.cnt;
    }
};

void dijkstra()
{
    priority_queue<node, vector<node>, cmp> pq;
    pq.push({0, 0, 0}); // wall, x, y
    check[0][0] = true;

    while (!pq.empty())
    {
        node cur = pq.top();
        pq.pop();

        if ((cur.y == n - 1) && (cur.x == m - 1))
        {
            ans = min(ans, cur.cnt);
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];

            if (0 > nx || nx >= m || 0 > ny || ny >= n)
            {
                continue;
            }

            if (!check[ny][nx])
            {
                if (arr[ny][nx] == 1)
                {
                    pq.push({nx, ny, cur.cnt + 1});
                }
                else
                {
                    pq.push({nx, ny, cur.cnt});
                }
                check[ny][nx] = true;
            }
        }
    }
}

int main()
{
    scanf("%d %d", &m, &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%1d", &arr[i][j]);
        }
    }

    dijkstra();

    printf("%d\n", ans);

    return 0;
}
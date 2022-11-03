/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
int arr[1005][1005];
bool visited[1005];
bool check[1005][1005];
int n, m, start;

void dfs(int x)
{
    visited[x] = true;
    cout << x << " ";
    for (int i = 1; i <= n; i++)
    {
        if (arr[x][i] && !visited[i])
        {
            dfs(i);
        }
    }
}

void bfs(int x)
{
    queue<int> q;
    q.push(x);

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        cout << cur << " ";
        for (int i=1; i<=n; i++)
        {
            if(arr[cur][i] && !check[cur][i] && !visited[i])
            {
                visited[i] = true;
                check[cur][i] = true;
                check[i][cur] = true;
                q.push(i);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m >> start;

    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    dfs(start);
    cout << '\n';
    memset(visited, false, sizeof(visited));
    bfs(start);

    return 0;
}
/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

bool visited[1001][1001];
bool check[1001];
int n, m, c;

void dfs(int res)
{
    check[res] = true;

    for (int i = 1; i <= n; i++)
    {
        if (visited[res][i] && !check[i])
        {
            dfs(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        visited[a][b] = true;
        visited[b][a] = true;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!check[i])
        {
            c++;
            dfs(i);
        }
    }

    cout << c << '\n';

    return 0;
}
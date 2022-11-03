/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
int arr[1001][1001];
bool check[1001];
int n, m, c;

void dfs(int x)
{
    check[x] = true;

    for (int i = 1; i <= n; i++)
    {
        if (arr[x][i] && !check[i])
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
        int u, v;
        cin >> u >> v;
        arr[u][v] = 1;
        arr[v][u] = 1;
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
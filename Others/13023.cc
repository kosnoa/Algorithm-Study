/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
int n, k;
vector<vector<int>> v(2005);
vector<bool> check(2005);
bool ans;

void dfs(int depth, int x)
{
    check[x] = true;
    if (depth == 4)
    {
        ans = true;
        return;
    }

    for (int i = 0; i < v[x].size(); i++)
    {
        if (ans)
        {
            return;
        }

        if (!check[v[x][i]])
        {
            dfs(depth + 1, v[x][i]);
        }
    }

    check[x] = false;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        dfs(0, i);
    }

    if (ans)
    {
        cout << 1 << '\n';
    }
    else
    {
        cout << 0 << '\n';
    }

    return 0;
}

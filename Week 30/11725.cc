/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
int arr[100001];
bool check[100001];
vector<int> vec[100001];
int n;

void dfs(int a)
{
    check[a] = true;

    for (int j = 0; j < vec[a].size(); j++)
    {
        if (!check[vec[a][j]])
        {
            arr[vec[a][j]] = a;
            dfs(vec[a][j]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }

    dfs(1);

    for (int i = 2; i <= n; i++)
    {
        cout << arr[i] << '\n';
    }

    return 0;
}
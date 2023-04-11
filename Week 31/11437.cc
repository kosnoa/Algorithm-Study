/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
ll n;
vector<int> vec[50001];
bool check[50001];
int parent[50001];
int level[50001];

int LCA(int a, int b)
{
    if (level[a] < level[b])
    {
        swap(a, b);
    }

    while (level[a] != level[b])
    {
        a = parent[a];
    }

    while(a != b) {
        a = parent[a];
        b = parent[b];
    }

    return a;
}

void bfs()
{
    queue<int> q;
    check[1] = true;
    q.push(1);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int i = 0; i < vec[node].size(); i++)
        {
            if (!check[vec[node][i]])
            {
                level[vec[node][i]] = level[node] + 1;
                parent[vec[node][i]] = node;
                check[vec[node][i]] = true;
                q.push(vec[node][i]);
            }
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

    bfs();

    int T;
    cin >> T;
    while (T--)
    {
        int a, b;
        cin >> a >> b;
        cout << LCA(a, b) << '\n';
    }

    return 0;
}
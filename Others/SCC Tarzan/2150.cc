/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
int v, e, idx, d[10001];
bool check[10001];
vector<int> vec[10001];
vector<vector<int>> SCC;
stack<int> s;

int dfs(int p)
{
    d[p] = ++idx;
    s.push(p);

    int parent = d[p];
    for (int i = 0; i < vec[p].size(); i++)
    {
        int tmp = vec[p][i];
        if (d[tmp] == 0)
        {
            parent = min(parent, dfs(tmp));
        }
        else if (!check[tmp])
        {
            parent = min(parent, dfs(tmp));
        }
    }

    if (parent == d[p])
    {
        vector<int> scc;
        while (1)
        {
            int t = s.top();
            s.pop();
            scc.push_back(t);
            check[t] = true;
            if (t == p)
            {
                break;
            }
        }
        SCC.push_back(scc);
    }

    return parent;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> v >> e;

    

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
    }

    for (int i = 1; i <= v; i++)
    {
        if (d[i] == 0)
        {
            dfs(i);
        }
    }

    cout << SCC.size() << '\n';

    for (int i = 0; i < SCC.size(); i++)
    {
        cout << i + 1 << ' ';
        for (int j = 0; j < SCC[i].size(); j++)
        {
            cout << SCC[i][j] << ' ';
        }

        cout << '\n';
    }

    return 0;
}
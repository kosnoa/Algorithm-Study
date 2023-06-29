/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
#define endl '\n';
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

struct p
{
    int s;
    int e;
    int c;
};
vector<p> vec;
ll arr[51];
ll n, sc, ec, m;
ll earn[51];
bool check[51];

bool dfs(int t)
{
    if (t == ec)
    {
        return true;
    }

    check[t] = true;
    bool tmp = false;
    for (auto i : vec)
    {
        if (i.s == t && !check[i.e])
        {
            tmp |= dfs(i.e);
        }
    }

    return tmp;
}

void bellman_ford()
{
    arr[sc] = earn[sc];

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < vec.size(); j++)
        {
            int start = vec[j].s;
            int fin = vec[j].e;
            int cost = vec[j].c;

            if (arr[start] == -1e9)
            {
                continue;
            }

            if (arr[fin] < arr[start] - cost + earn[fin])
            {
                arr[fin] = arr[start] - cost + earn[fin];
            }
        }
    }

    if (arr[ec] == -1e9)
    {
        cout << "gg\n";
        return;
    }
    else
    {
        for (int i = 0; i < vec.size(); i++)
        {
            int start = vec[i].s;
            int fin = vec[i].e;
            int cost = vec[i].c;

            if (arr[start] == -1e9)
            {
                continue;
            }

            if (arr[fin] < arr[start] - cost + earn[fin])
            {
                if (dfs(start))
                {
                    cout << "Gee\n";
                    return;
                }
            }
        }
    }

    cout << arr[ec] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> sc >> ec >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        vec.push_back({a, b, c});
    }

    for (int i = 0; i < n; i++)
    {
        cin >> earn[i];
    }

    fill(arr, arr + 51, -1e9);

    bellman_ford();

    return 0;
}
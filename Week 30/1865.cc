/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

struct holes
{
    int s;
    int e;
    int t;
};
vector<holes> v;
ll arr[501];
int n, m, w;
// 음수 사이클 존재시 Yes
// 음수 사이클 존재 안할 시 No

void bellman_ford()
{
    arr[1] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            int start = v[j].s;
            int finish = v[j].e;
            int time = v[j].t;


            if (arr[finish] > arr[start] + time)
            {
                arr[finish] = arr[start] + time;
            }
        }
    }

    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            int start = v[j].s;
            int finish = v[j].e;
            int time = v[j].t;

            if (arr[finish] > arr[start] + time)
            {
                cout << "YES\n";
                return;
            }
        }
    }

    
    cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        v.clear();
        cin >> n >> m >> w;

        for (int i = 0; i < m; i++)
        {
            int p, q, r;
            cin >> p >> q >> r;
            v.push_back({p, q, r});
            v.push_back({q, p, r});
        }

        for (int i = 0; i < w; i++)
        {
            int p, q, r;
            cin >> p >> q >> r;
            v.push_back({p, q, -r});
        }

        fill(arr, arr + 501, 1e9);

        bellman_ford();
    }

    return 0;
}
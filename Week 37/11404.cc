/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
ll n, m;
ll arr[105][105];

void floyd()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m;

    fill(&arr[0][0], &arr[104][105], 1e9);
    for (int i = 1; i <= n; i++)
    {
        arr[i][i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        arr[a][b] = min(arr[a][b], c);
    }

    floyd();

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (arr[i][j] == 1e9)
            {
                cout << 0 << ' ';
            }
            else
            {
                cout << arr[i][j] << ' ';
            }
        }

        cout << '\n';
    }

    return 0;
}
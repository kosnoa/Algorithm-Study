/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
#define endl '\n';
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
int n, m;
int arr[101][101];

void floyd()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                {
                    continue;
                }
                else if (arr[i][k] != 0 && arr[k][j] != 0)
                {
                    if (arr[i][j] == 0)
                    {
                        arr[i][j] = arr[i][k] + arr[k][j];
                    }
                    else
                    {
                        arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
                    }
                }
            }
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
        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    floyd();

    int res = 1e9;
    int p = 0;

    for (int i = 1; i <= n; i++)
    {
        int tmp = 0;
        for (int j = 1; j <= n; j++)
        {
            tmp += arr[i][j];
        }

        if (res > tmp)
        {
            res = tmp;
            p = i;
        }
    }

    cout << p << endl;

    return 0;
}
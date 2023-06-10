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
int arr[501][501];

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
                else
                {
                    if (arr[i][k] + arr[k][j] < arr[i][j])
                    {
                        arr[i][j] = arr[i][k] + arr[k][j];
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
    fill(&arr[0][0], &arr[100][101], 1e9);
    for (int i = 1; i <= n; i++)
    {
        arr[i][i] = 1;
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
    }

    floyd();

    int res = 0;

    for (int i = 1; i <= n; i++)
    {
        bool tmp = false;
        for (int j = 1; j <= n; j++)
        {
            if (arr[i][j] == 1e9 && arr[j][i] == 1e9)
            {
                tmp = true;
            }
        }

        if (!tmp)
        {
            res++;
        }
    }

    cout << res << endl;

    return 0;
}
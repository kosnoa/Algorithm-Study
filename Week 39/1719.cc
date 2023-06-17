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
int arr[203][203];
int res[203][203];

void floyd()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = n; i >= 1; i--)
        {
            for (int j = n; j >= 1; j--)
            {
                if (i == j)
                {
                    continue;
                }

                if (arr[i][j] > arr[i][k] + arr[k][j])
                {
                    arr[i][j] = arr[i][k] + arr[k][j];
                    res[i][j] = res[i][k];
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m;

    fill(&arr[0][0], &arr[202][203], 1e9);

    for (int i = 1; i <= n; i++)
    {
        arr[i][i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a][b] = c;
        arr[b][a] = c;
        res[a][b] = b;
        res[b][a] = a;
    }

    floyd();

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                cout << "- ";
            }
            else
            {
                cout << res[i][j] << ' ';
            }
        }

        cout << endl;
    }

    return 0;
}
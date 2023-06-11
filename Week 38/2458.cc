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
bool arr[502][502];

void floyd()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (arr[i][k] && arr[k][j])
                {
                    arr[i][j] = true;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m;
    fill(&arr[0][0], &arr[100][101], false);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a][b] = true;
    }

    floyd();

    int res = 0;

    for (int i = 1; i <= n; i++)
    {
        int tmp = 0;
        for (int j = 1; j <= n; j++)
        {
            if (arr[i][j] || arr[j][i])
            {
                tmp++;
            }
        }

        if (tmp == n - 1)
        {
            res++;
        }
    }

    cout << res << endl;

    return 0;
}
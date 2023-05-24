/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
int n, m, res;
int arr[6];

void rec(int x, int y, int cnt) // 진척도, 전에 행동했던 위치, 날짜
{
    if (cnt <= n)
    {
        for (int i = 0; i < 6; i++)
        {
            if (i % 3 == y)
            {
                cnt++;
                rec(x + arr[i] / 2, i % 3, cnt);
            }
            else
            {
                cnt++;
                rec(x + arr[i], i % 3, cnt);
            }
        }
    }
    else
    {
        if(x >= m)
        {
            res++;
        }
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < 6; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < 6; i++)
    {
        rec(arr[i], i % 3, 1);
    }

    cout << res;

    return 0;
}
/*
Study Purpose
*/

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

int k, s, arr[1024];
int res[11][1025];

void triversal(int start, int end, int depth)
{
    int a = 0;
    while (1)
    {
        if (res[depth][a] == 0)
        {
            int tmp = floor((start + end) / 2) - 1;
            res[depth][a] = arr[tmp];
            break;
        }
        else
        {
            a++;
        }
    }

    if (start == end)
    {
        return;
    }

    triversal(start, (start + end) / 2 - 1, depth + 1);
    triversal((start + end) / 2 + 1, end, depth + 1);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    cin >> k;
    s = pow(2, k) - 1;

    for (int i = 0; i < s; i++)
    {
        cin >> arr[i];
    }

    triversal(1, s, 0);

    for (int i = 0; i < k; i++)
    {
        int tmp = pow(2, i);

        for (int j = 0; j < tmp; j++)
        {
            cout << res[i][j] << ' ';
        }

        cout << '\n';
    }

    return 0;
}

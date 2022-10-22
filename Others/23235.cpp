/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int cnt = 0;
    while (1)
    {
        int arr[101];
        int n;
        cin >> n;

        if (n == 0)
        {
            break;
        }

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cnt++;
    }

    for (int i = 1; i <= cnt; i++)
    {
        cout << "Case " << i << ": Sorting... done!" << '\n';
    }

    return 0;
}
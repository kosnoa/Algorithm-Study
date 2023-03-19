/* Code By kosnoa
GitHub: kosnoa */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n, m, sum = 0, tmp = 1e9, ans = 0;
    cin >> n >> m;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                sum = v[i] + v[j] + v[k];
                if (m - sum < tmp && m - sum >= 0)
                {
                    tmp = m - sum;
                    ans = sum;
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
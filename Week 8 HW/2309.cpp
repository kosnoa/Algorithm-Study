/* Code By kosnoa
GitHub: kosnoa */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    vector<int> v(9);
    int sum = 0, h = 1;
    for (int i = 0; i < 9; i++)
    {
        cin >> v[i];
        sum += v[i];
    }
    sum -= 100;

    for (int i = 0; i < 8; i++)
    {
        if (h == 0)
        {
            break;
        }
        for (int j = i + 1; j < 9; j++)
        {
            if (sum == v[i] + v[j])
            {
                v[i] = -1;
                v[j] = -1;
                h--;
                break;
            }
        }
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < 9; i++)
    {
        if (v[i] > 0)
        {
            cout << v[i] << '\n';
        }
    }

    return 0;
}
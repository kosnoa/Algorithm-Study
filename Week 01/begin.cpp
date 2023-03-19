#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        bool room[105] = {
            true,
        };

        int cnt = 0;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= (n / i); j++)
            {
                if (room[i * j])
                {
                    room[i * j] = false;
                }
                else
                {
                    room[i * j] = true;
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (room[i] == false)
            {
                cnt++;
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}
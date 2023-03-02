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
        int n, cnt = 0;
        cin >> n;
        vector<pair<int, int>> vp;

        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            vp.push_back({a, b});
        }

        sort(vp.begin(), vp.end());

        int num = 1000001, i=0;

        while (1)
        {

            if (vp[i].second < num)
            {
                num = vp[i].second;
                cnt++;
            }
            
            i++;

            if (num == 1)
            {
                break;
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    ll n, cnt = 1;
    cin >> n;
    vector<pair<int, int>> vp;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        vp.push_back({b, a});
    }

    sort(vp.begin(), vp.end());

    int s = vp[0].first;

    for (int i=1; i<vp.size(); i++)
    {
        if (vp[i].second >= s)
        {
            cnt++;
            s = vp[i].first;
        }
    }

    cout << cnt << '\n';

    return 0;
}
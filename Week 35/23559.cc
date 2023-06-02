/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
int n, x, res;
int arr1[100001];
int arr2[100001];
vector<pair<ll, ll>> v;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> x;
    for(int i = 0; i < n; i++)
    {
        cin >> arr1[i] >> arr2[i];
        v.push_back({arr1[i] - arr2[i], i});
        res += arr2[i];
        x -= 1000;
    }

    sort(v.rbegin(), v.rend());

    for(int i=0; i < n; i++)
    {
        if(x < 4000)
        {
            break;
        }

        if(v[i].first > 0)
        {
            res -= arr2[v[i].second];
            res += arr1[v[i].second];
            x -= 4000;
        }
    }

    cout << res;

    return 0;
}
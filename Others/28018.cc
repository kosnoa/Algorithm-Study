/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
vector<int> vec(1e6);
int n, q, m = 0;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;
    fill(vec.begin(), vec.end(), 0);
    for(int i = 0; i < n; i++)
    {
        int s, e;
        cin >> s >> e;
        vec[s]++;
        vec[e+1]--;
        m = max(m, e+1);
    }

    for(int i = 0; i <= m; i++)
    {
        vec[i+1] += vec[i];
    }

    cin >> q;

    for(int i = 0; i < q; i++)
    {
        int t;
        cin >> t;
        cout << vec[t] << '\n';
    }

    return 0;
}
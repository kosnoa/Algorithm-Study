/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
vector<int> v;
int n, k, l, r, cnt = 1000007;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        
        if (tmp == 1)
        {
            v.push_back(i);
        }
    }

    l = 0;
    r = k-1;

    while (r < v.size()) 
    {
        int tmp = v[r] - v[l] + 1;

        if (cnt > tmp)
        {
            cnt = tmp;
        }
        l++, r++;
    }

    if (v.empty() || v.size() < k)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << cnt << '\n';
    }

    

    return 0;
}
/* Code By kosnoa
GitHub: kosnoa */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n, count=0;
    cin >> n;

    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({b, a});  
    }

    sort(v.begin(), v.end());
    
    count = v[1].second - v[0].second;

    for (int i=1; i<n; i++)
    {
        if (v[i].first != v[i+1].first && i != n-1)
        {
            count += v[i].second - v[i-1].second;
            i++;
            count += v[i+1].second - v[i].second;
        }
        else if (i == n-1)
        {
            count += v[i].second - v[i-1].second;
        }
        else
        {
            count += min(v[i].second - v[i-1].second, v[i+1].second - v[i].second);
        }
    }

    cout << count << '\n';


    return 0;
}
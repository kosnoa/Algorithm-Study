/* Code By kosnoa
GitHub : kosnoa */


#pragma GCC optimize("Ofast")
#pragma GCC ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
vector<int> v;
int n, l,sum;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;

    for (int i=0; i<n; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sum += v[0];

    for (int i=1; i<n; i++)
    {
        if(v[i]-v[i-1] == 1)
        {
            continue;
        }
        else
        {
            sum += v[i]; 
        }
    }
    
    cout << sum << '\n';

    return 0;
}
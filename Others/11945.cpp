/* Code By kosnoa
GitHub : kosnoa */


#pragma GCC optimize("Ofast")
#pragma GCC ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;


int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    vector<int> v;

    int n, m;
    cin >> n >> m;

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            int a;
            scanf("%d", &a);
            v.push_back(a);
        }
    }

    

    return 0;
}
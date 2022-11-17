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

    int max=0, tmp=0;

    for(int i=0; i<10; i++)
    {
        int n, m;
        cin >> n >> m;
        tmp += m-n;
        if (max < tmp)
        {
            max = tmp;
        }
    }

    cout << max << '\n';

    return 0;
}
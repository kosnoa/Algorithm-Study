/* Code By kosnoa
GitHub : kosnoa */


#pragma GCC optimize("Ofast")
#pragma GCC ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
vector<int> v;
int n, l, r, MAX=-1000;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> r;
    for (int i=0; i<n; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    r--;
    int sv = r;

    while (r < n)
    {
       int tmp=0;
       for (int i=0; i<=sv; i++)
       {
        tmp += v[l+i];
       }

       if (tmp > MAX)
       {
        MAX = tmp;
        l++, r++;
       }
       else 
       {
        l++, r++;
       }
    }

    cout << MAX << '\n';

    return 0;
}
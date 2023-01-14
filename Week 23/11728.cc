/* Code By kosnoa
GitHub : kosnoa */


#pragma GCC optimize("Ofast")
#pragma GCC ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;


vector<int> v1;
vector<int> v2;
vector<int> ans;
int a, b, l=0, r=0;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    
    cin >> a >> b;

    for (int i=0; i<a; i++)
    {
        int tmp;
        cin >> tmp;
        v1.push_back(tmp);
    }

    for (int i=0; i<b; i++)
    {
        int tmp;
        cin >> tmp;
        v2.push_back(tmp);
    }

    while (l < a && r < b)
    {
        if (v1[l] < v2[r])
        {
            ans.push_back(v1[l]);
            l++;
        }
        else if (v1[l] > v2[r])
        {
            ans.push_back(v2[r]);
            r++;
        }
        else
        {
            ans.push_back(v1[l]);
            ans.push_back(v2[r]);
            l++, r++;
        }
    }

    if (l < a)
    {
        while (l < a)
        {
            ans.push_back(v1[l]);
            l++;
        }
    }
    else if (r < b)
    {
        while (r < b)
        {
            ans.push_back(v2[r]);
            r++;
        }
    }

    for (auto i : ans)
    {
        cout << i << ' ';
    }

    return 0;
}
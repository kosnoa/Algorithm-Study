/* Code By kosnoa
GitHub : kosnoa */


#pragma GCC optimize("Ofast")
#pragma GCC ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
vector<int> v;
bool check[2005];
int n;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;

    for (int i=0; i<n-1; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    vector<int> ans(n);

    for (int i=1; i<=n; i++)
    {
        bool breaked = false;
        fill(&check[0], &check[0] + check[0] + sizeof(check), false);
        ans.clear();
        ans.push_back(i);
        check[i] = true;     
        int cur = i;

        for (int j=0; j<n-1; j++)
        {
            int tmp = v[j] - cur;

            if(tmp <= 0)
            {
                breaked = true;
                break;
            }

            if(!check[tmp])
            {   
                cur = tmp;
                check[tmp] = true;
                ans.push_back(tmp);
            }
            else
            {
                breaked = true;
                break;
            }
            
        }

        if (!breaked)
        {
            break;
        }
    }

    for (auto i : ans)
    {
        cout << i << ' ';
    }
    

    return 0;
}
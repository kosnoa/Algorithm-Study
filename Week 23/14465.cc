/* Code By kosnoa
GitHub : kosnoa */


#pragma GCC optimize("Ofast")
#pragma GCC ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
vector<int> v;
bool check[100001];
int n, k, b, l, ans = 100005;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> k >> b;

    for (int i=0; i<b; i++)
    {
        int tmp;
        cin >> tmp; 
        v.push_back(tmp);
    }

    for (int i=0; i<b; i++)
    {
        check[v[i] - 1] = true;
    }

    while (l < n)
    {
        int tmp=0;
        int cnt=0;
        
        if (l + k > n)
        {
            break;
        }

        for (int i=0; i<k; i++)
        {
            if (check[l+i])
            {
                tmp++;
            }
            cnt++;
        }

        if (tmp < ans && cnt == k)
        {
            ans = tmp;
            l++;
        }
        else
        {
            l++;
        }

        if (ans == 0)
        {
            break;
        }
    }

    cout << ans << '\n';

    return 0;
}
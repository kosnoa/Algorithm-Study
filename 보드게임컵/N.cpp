/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
vector<int> v;
int arr[100001];
int n, l=0;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }


    while (l < n-1)
    {
        for (int i = l+1; i < n; i++)
        {
            if (v[i] % v[l] == 0)
            {
                arr[i]--, arr[l]++;
            }

            if (v[l] % v[i] == 0)
            {
                arr[i]++, arr[l]--;
            }
        }
        
        l++;
    }

    for (int i=0; i<n; i++)
    {
        cout << arr[i] << ' ';
    }

    return 0;
}
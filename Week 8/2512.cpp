/* Code By kosnoa
GitHub : kosnoa */

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;

int n;
vector<int> v(n);

int BinarySearch(int target, vector<int> v)
{
    int low = 0;
    int high = v[n - 1];
    int mid;
    
    int res = 0;

    while (low <= high)
    {
        int sum = 0;
        mid = (low + high) / 2;

        for (int i = 0; i < n; i++)
        {
            if (v[i] >= mid)
            {
                sum += mid;
            }
            else if (v[i] < mid)
            {
                sum += v[i];
            }
        }

        if (sum <= target)
        {
            res = mid;
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
        
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;
    vector<int> v(n);

    int sum=0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }
    sort(v.begin(), v.end());

    int total;
    cin >> total;

    if (total > sum)
    {
        cout << v[n - 1] << '\n';
    }
    else
    {
        cout << BinarySearch(total, v) << '\n';
    }

    return 0;
}

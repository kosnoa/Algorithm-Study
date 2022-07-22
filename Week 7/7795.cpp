#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n, m, cnt = 0;
        cin >> n >> m;

        vector<int> v1(n);
        vector<int> v2(m);

        for (int i = 0; i < n; i++)
        {
            cin >> v1[i];
        }

        for (int i = 0; i < m; i++)
        {
            cin >> v2[i];
        }

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        for (int i = 0; i < n; i++)
        {
            int low = 0;
            int high = m;
            int mid;

            while (low+1 < high)
            {
                mid = (low + high) / 2;


                if (v2[mid] < v1[i])
                {
                    low = mid;
                }
                else
                {
                    high = mid;
                }
            }

            cnt += low;
            
            if (v1[i] > v2[low])
            {
                cnt++;
            }
        }

        

        cout << cnt << '\n';
    }

    return 0;
}
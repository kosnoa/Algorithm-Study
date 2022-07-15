#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

vector<ll> v1;
vector<ll> v2;
vector<ll> cnt;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        ll tmp;
        cin >> tmp;
        v1.push_back(tmp);
    }

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        ll tmp;
        cin >> tmp;
        v2.push_back(tmp);
    }

    sort(v1.begin(), v1.end());

    for (int i = 0; i < m; i++)
    {
        int low = 0;
        int high = n - 1;
        int mid;
        int idx1 = 0;
        int idx2 = 0;
        bool check = true;

        while (low <= high)
        {
            mid = (low + high) / 2;

            if (v1[mid] == v2[i])
            {
                check = false;
                idx1 = mid;
                idx2 = mid;

                int up = mid + 1;
                int up_tmp;
                int down = mid - 1;
                int down_tmp;

                while (low <= down)
                {
                    down_tmp = (low + down) / 2;

                    if (v1[down_tmp] < v2[i])
                    {
                        
                        break;
                    }
                    else
                    {
                        idx1 = down_tmp;
                        down = down_tmp - 1;
                    }
                }

                while (up <= high)
                {
                    up_tmp = (up + high) / 2;
                    if (v1[up_tmp] > v2[i])
                    {
                        break;
                    }
                    else
                    {
                        idx2 = up_tmp;
                        up = up_tmp + 1;
                    }
                }

                break;
            }
            else if (v1[mid] < v2[i])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        if (check)
        {
            cnt.push_back(0);
        }
        else
        {
            cnt.push_back(idx2 - idx1 + 1);
        }
    }

    for (int i = 0; i < cnt.size(); i++)
    {
        cout << cnt[i] << ' ';
    }

    cout << '\n';

    return 0;
}   
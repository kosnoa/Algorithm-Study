/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
ll n, cnt, MIN = 1e9 + 1, MAX = -1e9 - 1;
vector<vector<ll>> v;
vector<ll> v2;
bool check[2000];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;

    v.resize(2, vector<ll>(n, 0));

    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        v2.push_back(a);
        MIN = min(a, MIN);
        MAX = max(a, MAX);
    }

    // 벡터 안에서 최대 최소값 찾는 법 | 시간 복잡도 O(n)
    // MIN = *min_element(v2.begin(), v2.end());
    // MAX = *max_element(v2.begin(), v2.end());

    sort(v2.begin(), v2.end());

    for (int i = 0; i < n; i++)
    {
        v[0][i] = v2[i];
    }


    int left = 0, right = 1;

    while (left < n)
    {
        if (right >= n)
        {
            left++;
            right = left + 1;
            continue;
        }

        ll tmp = v[0][left] + v[0][right];
        if (tmp > MAX)
        {
            left++;
            right = left + 1;
        }

        if (tmp < MIN)
        {
            right++;
            continue;
        }

        int idx = find(v[0].begin(), v[0].end(), tmp) - v[0].begin();

        if (idx != n && idx != left && idx != right)
        {
            int tmp = v[0][idx];
            while(v[0][idx] == tmp)
            {
                if (v[1][idx] == 1)
                {
                    idx++;
                }
                else 
                {
                    check[idx] = true;
                    v[1][idx] = 1;
                }
            }
        }

        right++;
    }

    for (int i = 0; i < n; i++)
    {
        cnt += v[1][i];
    }

    cout << cnt << '\n';

    return 0;
}
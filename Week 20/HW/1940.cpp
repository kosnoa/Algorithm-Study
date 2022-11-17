/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
vector<ll> v;
ll n, m, l, r = 1, cnt;

/*
힌트:
두 포인터를 둘다 맨 앞에 두면 안된다.
중간에 둬서 계산한다?
그 줄에 있는 모든 경우의 수를 생각해야된다
*/

/*
반례
19 30989

21762 2407 5723 10306 25266 21414 3568 11724
16256 24129 20308 31044 5224 1744 30731 20272 31920 280 7195

정답: 1  (5723+25266)
출력: 0
*/

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        v.push_back(a);
    }

    while (l <= r && r < n)
    {
        if (v[l] + v[r] == m)
        {
            cnt++;
        }

        if (r == n - 1)
        {
            l++;
            r = l + 1;
        }
        else
        {
            r++;
        }
    }

    cout << cnt << '\n';

    return 0;
}
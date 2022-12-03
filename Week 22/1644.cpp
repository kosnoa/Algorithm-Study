/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
int prime[4000001];
vector<int> save;
int n, l, r, sum, cnt, tmp = 0;

void primeNum(int n)
{
    for (ll i = 2; i <= n; i++)
    {
        prime[i] = i;
    }

    for (ll i = 2; i <= sqrt(n); i++)
    {
        if (prime[i] == 0)
        {
            continue;
        }

        for (ll j = i * i; j <= n; j += i)
        {
            prime[j] = 0;
        }
    }

    for (ll i = 2; i <= n; i++)
    {
        if (prime[i] != 0)
        {
            save.push_back(prime[i]);
        }
    }
}

// 중복 고려

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;

    if (n == 1)
    {
        cout << 0 << '\n';
        return 0;
    }

    primeNum(n);

    bool visited = false;

    while (l <= r && r <= save.size())
    {
        if (r == save.size() && !visited)
        {
            visited = true;
            sum = 0;
            l = tmp;
            r = l;
            continue;
        }

        if (sum == n)
        {
            tmp = l + 1;
            cnt++;
            sum -= save[l];
            l++;
        }
        else if (sum >= n)
        {
            sum -= save[l];
            l++;
        }
        else
        {
            sum += save[r];
            r++;
        }
    }

    cout << cnt << '\n';

    return 0;
}
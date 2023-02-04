/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
int alpha[26];
string s;
int n, l, r, cnt, res;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> s;
    int len = s.size();

    while(1)
    {
        while(r < len && cnt <= n)
        {
            int idx = s[r++] - 'a';
            alpha[idx]++;

            if (alpha[idx] == 1)
            {
                cnt++;
            }

            if (cnt > n)
            {
                break;
            }
            res = max(res, r - l);
        }

        if(r == len)
        {
            break;
        }

        while (cnt > n)
        {
            int idx = s[l++] - 'a';
            alpha[idx]--;

            if(alpha[idx] == 0)
            {
                cnt--;
            }   
        }
    }

    cout << res << '\n';

    return 0;
}
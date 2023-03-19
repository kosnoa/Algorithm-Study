/* Code By kosnoa
GitHub : kosnoa */


#pragma GCC optimize("Ofast")
#pragma GCC ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
int n, l, res;
deque<int> dq;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> l;
    
    int sum = 0;
    for (int i=0; i<n; i++)
    {
        int a;
        cin >> a;
        sum += a;
        if (l == dq.size())
        {
            sum -= dq.front();
            dq.pop_front();
        }
        dq.push_back(a);

        if (sum >= 129 && sum <= 138)
        {
            res++;
        }
    }

    cout << res << '\n';
    
    return 0;
}
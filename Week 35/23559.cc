/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
int n, x, res;
struct tp
{
    int sum;
    int a;
    int b;
};

struct cmp
{
    bool operator()(const tp &p1, const tp &p2)
    {
        return p1.sum < p2.sum;
    }
};
priority_queue<tp, vector<tp>, cmp> pq;

/* 직접 만든 테케
3 10000
1 5
9 2
10 4

답: 18

3 7000
10 10
5 3
5 2 

답: 18

반례:
3 6000
10 10
20 21
20 10

답: 41

*/

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> x;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        pq.push({a - b, a, b});
    }

    for (int i = 0; i < n; i++)
    {
        if (x - 5000 < 1000 * (n - i) || pq.top().a <= pq.top().b)
        {
            if (n - i == 1 && x == 5000 && pq.top().a > pq.top().b)
            {
                res += pq.top().a;
                x -= 5000;
            }
            else
            {
                res += pq.top().b;
                x -= 1000;
            }
        }
        else
        {
            res += pq.top().a;
            x -= 5000;
        }
        pq.pop();
    }

    cout << res << '\n';

    return 0;
}
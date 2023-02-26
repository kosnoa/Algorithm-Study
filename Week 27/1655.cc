/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
int n;
priority_queue<ll, vector<ll>, less<ll>> left_pq; // 큰거
priority_queue<ll, vector<ll>, greater<ll>> right_pq; // 작은거
vector<ll> v;


int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;
    vector<ll> v(n);
    for (auto &i : v)
    {
        cin >> i;
    }

    for (int i = 0; i < n; i++)
    {

        if (left_pq.size() > right_pq.size()) // 큰거 > 작은거
        {
            right_pq.push(v[i]);
        }
        else
        {
            left_pq.push(v[i]);
        }

        if (!left_pq.empty() && !right_pq.empty())
        {
            if (left_pq.top() > right_pq.top()) // 큰거 > 작은거
            {
                int left = left_pq.top();
                int right = right_pq.top();

                left_pq.pop();
                right_pq.pop();

                left_pq.push(right);
                right_pq.push(left);
            }
        }

        cout << left_pq.top() << '\n';
    }

    return 0;
}
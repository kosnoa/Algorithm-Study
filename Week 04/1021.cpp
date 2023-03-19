#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    deque<int> dq;

    int n, m, l, r, cnt = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        dq.push_back(i);
    }

    while (m--)
    {
        int num;
        cin >> num;

        for (int i = 0; i < dq.size(); i++)
        {
            if (dq[i] == num)
            {
                l = i;
                r = dq.size() - i;
                break;
            }
        }

        if (l <= r)
        {
            while (1)
            {
                if (dq.front() == num)
                {
                    break;
                }

                dq.push_back(dq.front());
                dq.pop_front();
                cnt++;
            }
            dq.pop_front();
        }
        else
        {
            cnt++;

            while (1)
            {
                if (dq.back() == num)
                {
                    break;
                }

                dq.push_front(dq.back());
                dq.pop_back();
                cnt++;
            }
            dq.pop_back();
        }
    }

    cout << cnt << '\n';

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    deque<int> dq;

    int n, m, cnt = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        dq.push_back(i);
    }

    vector<int> v(m);

    for (int i = 0; i < v.size(); i++)
    {
        cin >> v[i];
    }

    int var = 0;

    while (m--)
    {
        int l, r;

        for (int i = 1; i < dq.size(); i++)
        {
            if (dq[i] == v[var])
            {
                l = i;
                r = dq.size() - i;
                break;
            }
        }

        if (l > r)
        {
            cnt += l;

            for (int i = 1; i <= l; i++)
            {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else if (l < r)
        {
            cnt += r;
            for (int i = 1; i <= r; i++)
            {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
        else
        {
            stack<int> st1;
            stack<int> st2;
            deque<int> dq_tmp1 = dq;
            deque<int> dq_tmp2 = dq;

            for (int i = 1; i < dq_tmp1.size(); i++)
            {
                if (dq_tmp1[i] == v[var + 1])
                {
                    break;
                }
                else
                {
                    st1.push(dq_tmp1.front());
                    dq_tmp1.pop_front();
                }
            }

            for (int i = dq_tmp2.size()-1; i > 0; i--)
            {
                if (dq_tmp2[i] == v[var + 1])
                {
                    break;
                }
                else
                {
                    st1.push(dq_tmp2.back());
                    dq_tmp2.pop_back();
                }
            }

            if (st1.size() > st2.size())
            {
                cnt += l;

                for (int i = 1; i <= l; i++)
                {
                    dq.push_back(dq.front());
                    dq.pop_front();
                }
            }
            else if (st1.size() < st2.size())
            {
                cnt += r;
                for (int i = 1; i <= r; i++)
                {
                    dq.push_front(dq.back());
                    dq.pop_back();
                }
            }
        }

        var++;
    }

    cout << cnt << '\n';

    return 0;
}
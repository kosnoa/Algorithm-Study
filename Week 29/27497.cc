/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
int n;
deque<char> dq;
stack<char> st;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;
    bool check = false; // false = front is recent | true = back is recent
    for (int i = 0; i < n; i++)
    {
        int cmd;
        cin >> cmd;
        if (cmd == 1)
        {
            char a;
            cin >> a;
            if (dq.size() > 1)
            {
                if (a == dq.front())
                {
                    check = true;
                }
            }

            dq.push_back(a);
            st.push(a);
        }
        else if (cmd == 2)
        {
            char a;
            cin >> a;
            if (dq.size() > 1)
            {
                if (a == dq.back())
                {
                    check = false;
                }
            }

            dq.push_front(a);
            st.push(a);
        }
        else if (cmd == 3)
        {
            if (dq.size() == 1)
            {
                dq.pop_front();
                st.pop();
                continue;
            }

            if (dq.empty())
            {
                continue;
            }

            if (dq.front() == dq.back())
            {
                if (check)
                {
                    dq.pop_back();
                    st.pop();
                    check = false;
                }
                else
                {
                    dq.pop_back();
                    st.pop();
                    check = true;
                }
            }
            else
            {
                if (dq.front() == st.top())
                {
                    dq.pop_front();
                    st.pop();
                }
                else if (dq.back() == st.top())
                {
                    dq.pop_back();
                    st.pop();
                }
            }
        }
    }

    if (dq.empty())
    {
        cout << 0 << '\n';
    }
    else
    {
        while (!dq.empty())
        {
            cout << dq.front();
            dq.pop_front();
        }
    }

    return 0;
}
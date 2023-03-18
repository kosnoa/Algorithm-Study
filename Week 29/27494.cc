/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
int n, m;
char c;
deque<char> dq;
stack<int> st;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;
    cin.ignore();

    for (int i = 1; i <= n; i++)
    {

        cin >> m;
        if (m == 1)
        {
            cin >> c;
            dq.push_back(c);
            st.push(1);
        }
        else if (m == 2)
        {
            cin >> c;
            dq.push_front(c);
            st.push(2);
        }
        else if (m == 3)
        {
            if (dq.empty())
            {
                continue;
            }

            if (st.top() == 1)
            {
                dq.pop_back();
            }
            else if (st.top() == 2)
            {
                dq.pop_front();
            }
            st.pop();
        }
    }

    if (!dq.empty())
    {
        while (!dq.empty())
        {
            cout << dq.front();
            dq.pop_front();
        }
    }
    else
    {
        cout << 0;
    }

    return 0;
}
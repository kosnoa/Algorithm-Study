#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        deque<int> dq;

        string s;
        cin >> s;

        int n;
        cin >> n;

        string s2;
        cin >> s2;


        if (n == 0 && s[0] == 'R')
        {
            cout << "[]" << '\n';
            continue;
        }
        else if (n == 0 && s[0] == 'D')
        {
            cout << "error" << '\n';
            continue;
        }

        for (int i = 0; i < s2.size(); i++)
        {

            int a = 0;
            if (s2[i] == '[')
            {
                while (s2[i] != ',')
                {
                    a++;
                    i++;
                }

                dq.push_back(stoi(s2.substr(i - a + 1, a - 1)));
            }
            else if (s2[i - 1] == ',')
            {
                while (s2[i] != ',')
                {
                    if (s2[i + 1] == ']')
                    {
                        a++;
                        i++;
                        break;
                    }

                    a++;
                    i++;
                }

                dq.push_back(stoi(s2.substr(i - a, a)));
            }
        }

        bool flag = true;
        bool check = false;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'R')
            {
                if (flag)
                {
                    flag = false;
                }
                else
                {
                    flag = true;
                }
            }
            else if (s[i] == 'D')
            {
                if (flag)
                {
                    if (dq.empty())
                    {
                        cout << "error" << '\n';
                        check = true;
                        break;
                    }
                    else
                    {
                        dq.pop_front();
                    }
                }
                else
                {
                    if (dq.empty())
                    {
                        cout << "error" << '\n';
                        check = true;
                        break;
                    }
                    else
                    {
                        dq.pop_back();
                    }
                }
            }
        }

        if(check)
        {
            continue;
        }
        

        if (!flag)
        {
            reverse(dq.rbegin(), dq.rend());
        }

        int tmp = dq.size();
        int tmp2 = 0;

        if (dq.empty())
        {
            cout << "[]" << '\n';
        }
        else
        {
            for (int i = 0; i < tmp; i++)
            {
                if (i == 0)
                {
                    cout << '[';
                }
                tmp2++;
                cout << dq.front();
                dq.pop_front();
                if (tmp2 == tmp)
                {
                    cout << ']' << '\n';
                    break;
                }
                else
                {
                    cout << ',';
                }
            }
        }
    }

    return 0;
}
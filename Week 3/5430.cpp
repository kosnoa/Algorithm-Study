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
        vector<string> v;

        for (int i = 0; i < s2.size(); i++)
        {
            string sub;
            int a = 0;
            if (s2[i] == '[')
            {
                while (s2[i] != ',')
                {
                    a++;
                    i++;
                }

                sub = s2.substr(i - a + 1, a - 1);

                v.push_back(sub);
            }

            if (s2[i - 1] == ',')
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

                sub = s2.substr(i - a, a);

                v.push_back(sub);
            }
        }
    }
    

    return 0;
}
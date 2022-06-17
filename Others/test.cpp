#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

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

            v.push_back(s2.substr(i - a + 1, i - 1));
        }
        else if (s2[i - 1] == ',')
        {
            while (s2[i] != ',' || s2[i] != ']')
            {
                a++;
                i++;
            }

            v.push_back(s2.substr(i - a + 1, i - 1));
        }
    }

    for (auto i:v)
    {
        cout << i << '\n';
    }

    return 0;
}

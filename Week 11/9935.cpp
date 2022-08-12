/* Code By kosnoa
GitHub : kosnoa */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
vector<char> v;
string s;
string bomb;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> s;
    cin >> bomb;

    for (int i = 0; i < s.size(); i++)
    {
        v.push_back(s[i]);

        if (v.size() < bomb.size())
        {
            continue;
        }
        else
        {
            int n = v.size()-1;
            int m = bomb.size() - 1;
            bool check = false;
            for (int j = m; j >= 0; j--)
            {


                if (v[n] == bomb[j])
                {
                    check = true;
                    n--;
                }
                else
                {
                    check = false;
                    break;
                }
            }
            if (check)
            {
                for (int j = 0; j < bomb.size(); j++)
                {
                    v.pop_back();
                }
            }
        }
    }

    if (!v.empty())
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i];
        }
    }
    else
    {
        cout << "FRULA" << '\n';
    }

    return 0;
}
/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
int n, k;
vector<int> v;
vector<string> vs;
string res;

int compare(string s1, string s2)
{
    string tmp1 = s1 + s2;
    string tmp2 = s2 + s1;
    int size = tmp1.size();

    for (int i = 0; i < size; i++)
    {
        if (tmp1[i] > tmp2[i])
        {
            return 1;
        }
        else if (tmp1[i] < tmp2[i])
        {
            return -1;
        }
    }

    return 0;
}

void sort_num()
{
    for (int i = vs.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            int tmp = compare(vs[j], vs[j + 1]);
            if (tmp == -1)
            {
                swap(vs[j], vs[j + 1]);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> k >> n;

    vector<int> v(k);

    for (auto &i : v)
    {
        cin >> i;
    }

    sort(v.begin(), v.end());

    int largest = v[v.size() - 1];

    for (int i = 0; i < n - k; i++)
    {
        v.push_back(largest);
    }

    for (int i = 0; i < v.size(); i++)
    {
        vs.push_back(to_string(v[i]));
    }

    sort_num();

    for (int i=0; i<vs.size(); i++)
    {
        res += vs[i];
    }

    cout << res << '\n';

    return 0;
}
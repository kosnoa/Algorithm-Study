#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    vector<int> v = {2, 5, 1, 3, 4};

    for (int i=0; i<v.size(); i++)
    {
        int min=1e6;
        int save=0;

        for (int j=i; j<v.size(); j++)
        {
            if (min > v[j])
            {
                save = j;
                min = v[j];
            }
        }
        v[save] = v[i];
        v[i] = min;
    }

    for (auto i:v)
    {
        cout << i << ' ';
    }

    return 0;
}
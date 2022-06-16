#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    vector<int> v = {9,4,5,2,7};

    int n=0;

    for (int i=0; i<v.size(); i++)
    {
        for (int j=1; j<v.size()-i; j++)
        {
            if (v[j-1] > v[j])
            {
                n++;
                int tmp = v[j];
                v[j] = v[j-1];
                v[j-1] = tmp;
            }
            else
            {
                n++;
                continue;
            }
        }
    }

    
    for(auto elem:v) // this is same as "for (int i=0; i<v.size(); i++)"
    {
        cout << elem << ' ';
    }

    cout << '\n';

    cout << n << '\n';

    return 0;
}

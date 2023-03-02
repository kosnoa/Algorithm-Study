#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    vector<int> v = {5, 4, 3, 2, 1};

    for (int i=1; i<v.size(); i++)
    {
        int key=v[i];
        int n=0;
        for (int j=i; j>0; j--)
        {
            
            if (key < v[j-1])
            {
                v[j] = v[j-1];
                n++;
            }
            else
            {
                continue;
            }
        }
        v[i-n] = key; 
    }

    for (auto i:v)
    {
        cout << i << ' ';
    }

    return 0;
}
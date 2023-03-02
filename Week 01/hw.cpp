#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
vector<int> v1(1e6);
vector<int> v2(1e6);


int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    
    int d, k;   
    cin >> d >> k;

    v1[1] = 1;
    v2[2] = 1;

    for (int i = 3; i <= d; i++)
    {
        v1[i] = v1[i - 1] + v1[i - 2];
        v2[i] = v2[i - 1] + v2[i - 2];
    }

    for (int i = 1; i <= k; i++)
    {
        int tmp = k - (v1[d] * i);

        if (tmp % v2[d] == 0)
        {
            cout << i << '\n' << tmp / v2[d] << '\n';
            break;
        }
    }

    return 0;
}
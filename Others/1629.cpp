#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;




int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    ll a, b, c;
    cin >> a >> b >> c;

    ll result = 1;
    ll tmp = a%c;

    while (b>0)
    {
        if (b%2 == 1)
        {
            result *= tmp;
            result %= c;
        }

        tmp = ((tmp%c)*(tmp%c))%c;
        b/=2;
    }


    cout << result << '\n';

   

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

int clock_number (int x)
{
    int tmp=x;

    for (int i=0; i<3; i++)
    {
        tmp = tmp%1000*10 + tmp/1000;

        if (tmp < x)
        {
            x = tmp;
        }
    }

    return x;

}


int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int num = a*1000 + b*100 + c*10 + d;
    int r = clock_number(num);


    int cnt = 0;
    for (int i=1111; i<r; i++)
    {
        if (i == clock_number(i))
        {
            cnt++;
        }
    }

    cout << cnt+1 << '\n';

    return 0;
}
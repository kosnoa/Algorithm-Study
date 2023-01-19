/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
bool check[13];
bool num[7];
bool lstraight[7];
bool bstraight[7];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    for (int i = 1; i < 13; i++)
    {
        char c;
        cin >> c;
        if (c == 'Y')
        {
            check[i] = true;
        }
    }

    int n, m, k;
    cin >> n >> m >> k;

    num[n] = true;
    num[m] = true;
    num[k] = true;

    if (n == m && m == k)
    {
        if (check[11])
        {
            cout << 50 << '\n';
            return 0;
        }
        else
        {
            if (n == 6 && check[6])
            {
                cout << 30 << '\n';
                return 0;
            }
            else
            {
                if ((check[8] && n != 6) || (check[12] && n == 6))
                {
                    cout << n * 3 + 12 << '\n';
                    return 0;
                }
                else if (check[8] && n == 6)
                {
                    cout << n * 3 + 10 << '\n';
                    return 0;
                }
                else
                {

                    if (n == 1 && check[1])
                    {
                        cout << n * 5 << '\n';
                        return 0;
                    }
                    else if (n==2 && check[2])
                    {
                        cout << n * 5 << '\n';
                        return 0;
                    }
                    else if (n==3 && check[3])
                    {
                        cout << n * 5 << '\n';
                        return 0;
                    }
                    else if (n==4 && check[4])
                    {
                        cout << n * 5 << '\n';
                        return 0;
                    }
                    else if (n==5 && check[5])
                    {
                        cout << n*5 << '\n';
                    }
                    else
                    {
                        if (check[12])
                        {
                            cout << n*3+12 << '\n';
                            return 0;
                        }
                        else 
                        {
                            if (check[7])
                            {
                                cout << n*4 << '\n';
                            }
                            else
                            {
                                for (int i=6; i>0; i--)
                                {
                                    if(check[i])
                                    {
                                        cout << i*2 << '\n';
                                        return 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else if(n==m && m!=k)
    {
        
    }
    else if(n==k && k!=m)
    {

    }
    else if(m==k && k!=n)
    {

    }
    else
    {

    }

    return 0;
}
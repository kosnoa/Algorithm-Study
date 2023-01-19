/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int T, num = 1;
    bool reverse = false;
    cin >> T;
    while (T--)
    {
        string s;
        int n;
        cin >> s >> n;

        if (s == "CLOCK" || s == "WATCH")
        {
            if (num == n)
            {
                cout << num << " YES\n";
            }
            else
            {
                cout << num << " NO\n";
            }

            if(!reverse)
            {
                if(num == 12)
                {
                    num = 1;
                }
                else
                {
                    num++;
                }
            }
            else 
            {
                if(num == 1)
                {
                    num = 12;
                }
                else 
                {
                    num--;
                }
            }
            
        }
        else if (s == "HOURGLASS")
        {
            cout << num << " NO\n";

            if (num != n)
            {
                if (reverse)
                {
                    reverse = false;
                }
                else 
                {
                    reverse = true;
                }
            }

            if(!reverse)
            {
                if(num == 12)
                {
                    num = 1;
                }
                else
                {
                    num++;
                }
            }
            else 
            {
                if(num == 1)
                {
                    num = 12;
                }
                else 
                {
                    num--;
                }
            }
        }
    }

    return 0;
}
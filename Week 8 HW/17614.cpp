/* Code By kosnoa
GitHub: kosnoa */


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;


int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n, cnt=0, tmp=1;
    cin >> n;

    while(tmp <= n)
    {
        string s = to_string(tmp);
        
        for (int i=0; i<s.size(); i++)
        {
            if (s[i] == '3' || s[i] == '6' || s[i]  == '9')
            {
                cnt++;
            }
        }

        tmp++;
    }

    cout << cnt << '\n';

    return 0;
}
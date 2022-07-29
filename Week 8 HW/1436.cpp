/* Code By kosnoa
GitHub: kosnoa */


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;


int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    ll n;
    cin >> n;
    ll cnt = 1, num = 665, tmp=0;

    while(cnt <= n)
    {
        string s = to_string(num);
        
        for (int i=2; i<s.size(); i++)
        {
            if (s[i-2] == '6' && s[i-1] == '6' && s[i] == '6')
            {
                cnt++;
                tmp = num;
                break;
            }
        }
        num++;
    }
    
    cout << tmp << '\n';

    return 0;
}
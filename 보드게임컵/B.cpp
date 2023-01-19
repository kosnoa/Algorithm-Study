/* Code By kosnoa
GitHub : kosnoa */


#pragma GCC optimize("Ofast")
#pragma GCC ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
int arr[4];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) { 
        string s;
        int n;
        cin >> s >> n;

        if (s == "STRAWBERRY")
        {
            arr[0] += n;
        }
        else if (s == "BANANA")
        {
            arr[1] += n;
        }
        else if (s == "LIME")
        {
            arr[2] += n; 
        }
        else if(s == "PLUM")
        {
            arr[3] += n;
        }
    }

    for (int i=0; i<4; i++)
    {
        if (arr[i] == 5)
        {
            cout << "YES" << '\n';
            return 0;
        }
    }

    cout << "NO" << '\n';

    return 0;
}
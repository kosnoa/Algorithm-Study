/* Code By kosnoa
GitHub : kosnoa */


#pragma GCC optimize("Ofast")
#pragma GCC ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

bool arr[101];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int T;
    cin >> T;
    int cnt=0;
    while(T--) { 
        int n;
        cin >> n;
        if(!arr[n])
        {
            arr[n] = true;
        }
        else
        {
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}
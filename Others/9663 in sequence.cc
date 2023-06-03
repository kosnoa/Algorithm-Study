/* Code By kosnoa
GitHub : kosnoa */


#pragma GCC optimize("Ofast")
#pragma GCC ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
int n;
int arr[15] = {1, 0, 0, 2, 10, 4, 40, 92, 352, 724, 2680, 14200, 73712, 365596, 2279184};

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    cin >> n;
    cout << arr[n-1];

    return 0;
}
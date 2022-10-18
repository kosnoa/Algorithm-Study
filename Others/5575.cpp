/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

int tmp[3];
int arr[3][6];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    for (int i=0; i<3; i++)
    {
        for (int j=0; j<6; j++)
        {
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<3; i++)
    {
        tmp[i] = (arr[i][3] * 3600 + arr[i][4] * 60 + arr[i][5]) - (arr[i][0] * 3600 + arr[i][1] * 60 + arr[i][2]);
        cout << tmp[i]/3600 << ' ';
        tmp[i] %= 3600;
        cout << tmp[i]/60 << ' ';
        tmp[i] %= 60;
        cout << tmp[i] << '\n';
    }

    return 0;
}
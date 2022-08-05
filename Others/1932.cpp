/* Code By kosnoa
GitHub : kosnoa */


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

int dp[505][505];
int arr[505][505];
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=i; j++)
        {
            cin >> arr[i][j];
        }
    }

    dp[1][1] = arr[1][1]; 

    for (int i=2; i<=n; i++)
    {
        for (int j=1; j<=i; j++)
        {
            if(j==1)
            {
                dp[i][j] = dp[i-1][j] + arr[i][j]; 
            }
            else if (j==i)
            {
                dp[i][j] = dp[i-1][j-1] + arr[i][j];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + arr[i][j];
            }
        }
    }

    int max=0;

    for (int i=1; i<=n; i++)
    {
        if (dp[n][i] > max)
        {
            max = dp[n][i];
        }
    }

    if (n == 1)
    {
        cout << dp[1][1] << '\n';
    }
    else
    {
        cout << max << '\n';
    }
    

    return 0;
}
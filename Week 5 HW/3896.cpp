#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

int n=1299709;
int arr[1299710];

void primeNum()
{
    for (int i = 2; i <= n; i++)
    {
        arr[i] = i;
    }

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (arr[i] == 0)
        {
            continue;
        }

        for (int j = i * i; j <= n; j += i)
        {
            arr[j] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    primeNum();

    int t;
    cin >> t;
    
    while(t--)
    {
        int k, sum=0;
        cin >> k;

        for(int i=k; i<1299710; i++)
        {
            if(arr[i] != 0)
            {
                break;
            }
            else
            {
                sum++;
            }
        }
        
        for(int i=k; i>1; i--)
        {
            if(arr[i] != 0)
            {
                break;
            }
            else
            {
                sum++;
            }
        }

        cout << sum << '\n';
    }

    

    return 0;
}
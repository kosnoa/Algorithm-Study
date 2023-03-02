#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

int n, m;
int arr[1000000];

void primeNum()
{
    int total=0;
    m = 2*n;

    for (int i = 2; i <= m; i++)
    {
        arr[i] = i;
    }

    for (int i = 2; i <= sqrt(m); i++)
    {
        if (arr[i] == 0)
        {
            continue;
        }

        for (int j = i * i; j <= m; j += i)
        {
            arr[j] = 0;
        }
    }

    for (int i = n+1; i <= m; i++)
    {
        if (arr[i] != 0)
        {
            total++;
        }
    }

    cout << total << '\n';
    
}


int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    while(1)
    {
        cin >> n;

        if (n!=0)
        {
            primeNum();
        }
        else
        {
            break;
        }
    }

    return 0;
}


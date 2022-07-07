#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
int n, m;
int arr[1000001];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m;

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

    for (int i = n; i <= m; i++)
    {
        if (arr[i] != 0)
        {
            cout << arr[i] << '\n';
        }
    }

    return 0;
}
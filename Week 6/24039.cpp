#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

int n=10000;
int arr[10005];

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

    int num;

    cin >> num;

    primeNum();

    int tmp = 2;
    vector<int> v;

    for (int i = 3; i < 9974; i++)
    {
        if (arr[i] != 0)
        {
            v.push_back(tmp * i);
            tmp = i;
        }
    }

    int j = 0;

    while (num >= v[j])
    {
        j++;
    }

    cout << v[j] << '\n';

    return 0;
}
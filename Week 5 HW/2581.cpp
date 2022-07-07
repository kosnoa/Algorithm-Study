#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

int n, m;
int arr[100001];
vector<int> v;
bool check = false;

void primeNum()
{
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
            v.push_back(arr[i]);
        }
    }

    if (v.empty())
    {
        check = true;
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m;

    primeNum();

    if (check)
    {
        cout << "-1" << '\n';
    }
    else
    {
        int sum = 0;

        for (int i = 0; i < v.size(); i++)
        {
            sum += v[i];
        }

        cout << sum << '\n';
        cout << v[0] << '\n';
    }

    return 0;
}
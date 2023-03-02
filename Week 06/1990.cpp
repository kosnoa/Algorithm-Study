#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

int n, m;
int arr[10000005];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m;

    if (m > 10000000)
    {
        m = 10000000;

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
                string s1 = to_string(arr[i]);
                string s2 = s1;

                reverse(s2.begin(), s2.end());

                if (s1 == s2)
                {
                    cout << arr[i] << '\n';
                }
            }
        }
        cout << "-1" << '\n';
    }
    else
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
                string s1 = to_string(arr[i]);
                string s2 = s1;

                reverse(s2.begin(), s2.end());

                if (s1 == s2)
                {
                    cout << arr[i] << '\n';
                }
            }
        }

        cout << "-1" << '\n';
    }

    return 0;
}
/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

int A[20000];
int B[20000];

bool cmp(int x, int y)
{
    return x > y;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        for (int j = 0; j < n; j++)
        {
            cin >> A[j];
        }
        for (int j = 0; j < m; j++)
        {
            cin >> B[j];
        }
        sort(A, A + n, cmp);
        sort(B, B + m, cmp);

        int left = 0;
        int right = 0;
        int sum = 0;
        while (left < n && right < m)
        {
            if (A[left] > B[right])
            {
                sum += m - right;
                left++;
            }
            else
            {
                right++;
            }
        }
        cout << sum << "\n";
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));
    }

    return 0;
}
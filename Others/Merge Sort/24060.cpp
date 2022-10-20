/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

int A[500005];
int res[500005];
int n, k, cnt;

void merge(int left, int right)
{
    int mid = (left+right)/2;
    int i = left;
    int j = mid + 1;
    int t = 0;

    while (i <= mid && j <= right)
    {
        if (A[i] <= A[j])
        {
            res[t++] = A[i++];
        }
        else
        {
            res[t++] = A[j++];
        }
    }

    while (i <= mid)
    {
        res[t++] = A[i++];
    }

    while (j <= right)
    {
        res[t++] = A[j++];
    }

    i = left;
    t = 0;

    while (i <= right)
    {
        A[i++] = res[t++];
        if (++cnt == k)
        {
            cout << res[t - 1] << '\n';
        }
    }
}

void merge_sort(int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        merge_sort(left, mid);
        merge_sort(mid + 1, right);
        merge(left, right);
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    merge_sort(0, n - 1);

    if (cnt < k)
    {
        cout << "-1" << '\n';
    }

    return 0;
}
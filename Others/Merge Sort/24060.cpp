/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

int arr[500001];
int res[500001];
int n, m, cnt;

void merges(int left, int right)
{
    int mid = (left + right) / 2;
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right)
    {
        if (arr[i] > arr[j])
        {
            res[k++] = arr[j++];
        }
        else
        {
            res[k++] = arr[i++];
        }
    }

    if (i > mid)
    {
        while (j <= right)
        {
            res[k++] = arr[j++];
        }
    }
    else
    {
        while (i <= mid)
        {
            res[k++] = arr[i++];
        }
    }

    cnt += (right - left + 1);
    if (cnt > 0 && cnt >= m)
    {
        cout << res[m - cnt + right - left] << '\n';
        cnt = -1;
    }
}

void partition(int left, int right)
{
    int mid;
    while (left < right)
    {
        mid = (left + right) / 2;
        partition(left, mid);
        partition(mid + 1, right);
        merges(left, right);
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    partition(0, n - 1);

    return 0;
}
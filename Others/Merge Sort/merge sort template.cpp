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
        // 양쪽 리스트에서 최솟값을 비교했는데 오른쪽 리스트가 더 컸을 경우
        // 그대로 왼쪽 리스트의 최솟값이 결과배열에 내려온다.
        else
        {
            res[k++] = arr[i++];
        }
    }

    // 오른쪽 리스트에 아직 결과배열에 들어가지 못한 값 있을 경우 그대로 넣는 과정.
    if (i > mid)
    {
        while (j <= right)
        {
            res[k++] = arr[j++];
        }
    }
    else // 왼쪽 리스트에 남은 값들 차례롷 마저 넣는 과정.
    {
        while (i <= mid)
        {
            res[k++] = arr[i++];
        }
    }

    // 다시 원래 배열에 옮겨담는 작업.
    for (int a = left; a <= right; a++)
    {
        arr[a] = res[a];
    }
}

void partition(int left, int right)
{
    int mid;
    // 두개로 분할하고 병합하는 과정
    // 병합 합수 merges를 보면 알 수 있들이, while문 등으로 정렬하면하서 병합하게 된다.
    if (left < right)
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

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    partition(0, n - 1);

    // 이후 결과 배열인 result를 출력하거나 활용
    

    return 0;
}
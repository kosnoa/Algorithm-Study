#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

// 선형 검색 (Linear Search)
void LinearSearch()
{
    int find = 10;
    int A[5] = {30, 40, 50, 10, 20};
    for (int i = 0; i < 5; i++)
    {
        if (A[i] == find)
        {
            cout << "found!" << '\n';
        }
    }
}

// 이진 검색 (Binary Search)
// 조건 : 정렬

int Test(int tmp[], int len, int target)
{
    int low = 0;
    int high = len - 1;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (tmp[mid] == target)
        {
            return 1;
        }
        else if (tmp[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

void BinarySearch()
{
    int arr[7] = {3, 7, 9, 10, 15, 17, 20};
    // Test(array, array size, number to find)
    int res = Test(arr, 7, 15);

    if (res != -1)
    {
        cout << "Found" << '\n';
    }
    else
    {
        cout << "Not Found" << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    return 0;
}
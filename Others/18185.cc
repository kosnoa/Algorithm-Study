/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
int n, res;
int arr[10001];

/* WA (반례 1 2 1 1 | 2 3 2 1) 
사이즈 3 bool 배열 만들기 (어떤 조건을 충족하는지 찾기)

배열이 0 1 2 모두 true일 경우
- 조건 3
배열이 0 1 또는 1 2가 true일 경우
- 조건 2
나머지 경우
- 조건 1

AC 받을려면 중간값의 크기 유무
- 중간값 > 오른쪽값
    - 2개를 먼저 구매 후 3개를 구매
- 그 외 경우
    - 3개를 먼저 구매 후 2개를 구매
- 1개는 그냥 3 * arr[i] 해주면 됨
*/

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i + 1] > arr[i + 2])
        {
            int val = min(arr[i], arr[i + 1] - arr[i + 2]);
            res += val * 5;
            arr[i] -= val;
            arr[i + 1] -= val;

            val = min(arr[i], min(arr[i+1], arr[i+2]));
            res += val * 7;
            arr[i] -= val;
            arr[i + 1] -= val;
            arr[i + 2] -= val;
            
        }
        else
        {
            int val = min(arr[i], min(arr[i+1], arr[i+2]));
            res += val * 7;
            arr[i] -= val;
            arr[i + 1] -= val;
            arr[i + 2] -= val;

            val = min(arr[i], arr[i + 1]);
            res += val * 5;
            arr[i] -= val;
            arr[i + 1] -= val;
        }
        res += arr[i] * 3;
    }

    cout << res;

    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int res;
int arr[2000];

int main()
{

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    // 1 2 3 4 5 6 7 8 9 10
    for (int i = 0; i < n; i++)
    {                       // i : 2
        long find = arr[i]; // find : 3
        int l = 0;          // l : 0
        int r = n - 1;      // r : 1
        while (l != r)
        {
            if (arr[l] + arr[r] == find)
            {
                if (l != i && r != i)
                {
                    res++;
                    break;
                }
                else if (l == i)
                {
                    l++;
                }
                else if (r == i)
                {
                    r--;
                }
            }
            else if (arr[l] + arr[r] < find)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
    }
    cout << res;
}

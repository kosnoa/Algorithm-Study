#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

vector<int> v;

bool binarySearch(int len, int target)
{
    int low = 0, mid, high = len - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (v[mid] == target)
        {
            return true;
        }
        else if (v[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    cin >> m;

    while (m--)
    {
        int num;
        cin >> num;
        bool tmp = binarySearch(v.size(), num);

        if (tmp)
        {
            cout << "1" << '\n';
        }
        else
        {
            cout << "0" << '\n';
        }
    }

    return 0;
}
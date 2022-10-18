/*
Study Purpose
*/

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define VPRT(x, type) copy(x.begin(), x.end(), ostream_iterator<type>(cout, " "))
typedef long long ll;
typedef unsigned long long llu;

int k, s, arr[1024];
vector<int> v[11];

void triversal(int start, int end, int depth)
{
    v[depth].push_back(arr[(start + end) / 2]);

    if (start == end)
    {
        return;
    }

    triversal(start, (start + end) / 2 - 1, depth + 1);
    triversal((start + end) / 2 + 1, end, depth + 1);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    cin >> k;
    s = pow(2, k) - 1;

    for (int i = 0; i < s; i++)
    {
        cin >> arr[i];
    }

    triversal(1, s, 1);

    for (int i = 1; i <= k; i++)
    {
        VPRT(v[i], int);
        cout << '\n';
    }

    return 0;
}

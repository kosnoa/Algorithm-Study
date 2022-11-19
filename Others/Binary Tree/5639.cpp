/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
int tree[10001];

void postOrder(int l, int r)
{
    if (l >= r)
    {
        return;
    }

    if (l == r - 1)
    {
        cout << tree[l] << '\n';
        return;
    }

    int idx = l + 1;
    
    while (idx < r)
    {
        if (tree[l] < tree[idx])
        {
            break;
        }
        idx++;
    }
    
    postOrder(l+1, idx);
    postOrder(idx, r);
    cout << tree[l] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    int idx = 0;
    while (cin >> n)
    {
        tree[idx++] = n;
    }

    postOrder(0, idx);

    return 0;
}
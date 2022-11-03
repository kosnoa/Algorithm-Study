/* Code By kosnoa
GitHub : kosnoa */


#pragma GCC optimize("Ofast")
#pragma GCC ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
int arr[101][101];
bool check[101];
int n, m, cnt;

void dfs(int x)
{
    check[x] = true;

    for (int i=1; i<=n; i++)
    {
        if(arr[x][i] && !check[i])
        {
            cnt++;
            dfs(i);
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m;
    for (int i=0; i<m; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    dfs(1);

    cout << cnt << '\n';
    

    return 0;
}
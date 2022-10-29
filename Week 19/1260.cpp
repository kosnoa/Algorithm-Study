/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
int arr[1005][1005];
vector<int> v1;
vector<int> v2;
bool check1[1005][1005];
bool check2[1005][1005];
int n, m, start;

/*
void dfs(int x){
    visited[x] = true;
    cout << x << " "; 
    for(int i=1; i<=n; i++){ 
        if(arr[x][i] && !visited[i]){
            dfs(i);
        }
    }
}

*/

void dfs(int y, int x)
{
    check1[y][x] = true;

    for (int i = 0; i < n; i++)
    {
        int nx = x + i;

        if (nx >= 1 && nx <= n && arr[y][nx] == 1 && !check1[y][nx])
        {
            check1[y][nx] = true;
            check1[nx][y] = true;
            v1.push_back(nx);
            
            if (v1.size() == n-1)
            {
                return;
            }
            dfs(nx, 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m >> start;

    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    dfs(1, 1);

    cout << start << ' ';
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << ' ';
    }
    cout << '\n';

    return 0;
}
/* Code By kosnoa
GitHub : kosnoa */

// 숙제
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

int arr[3][105];
bool visited[3][105];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, c;

// 사이클을 찾는다

void dfs(int x, int y)
{
    visited[x][y] = true;

    for (int i=0; i<4; i++)
    {
        int nx = x+dx[i];
        int ny = x+dy[i];
    }
}


int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;
    
    for (int i=1; i<2; i++)
    {
        for (int j=1; j<=n; j++)
        {
            arr[i][j] = j;
        }
    }

    return 0;
}
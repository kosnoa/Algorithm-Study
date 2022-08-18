/* Code By kosnoa
GitHub: kosnoa */

// 문제 이해함, 하지만 시작부분에서 막힘
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

int arr[1001][1001];
bool visited[1001][1001];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n,m, c;

queue<pair<int, int>> qp;

void bfs(int x, int y)
{
    
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> m >> n;

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cin >> arr[i][j];
        }
    }

    

    cout << c << '\n';

    return 0;
}
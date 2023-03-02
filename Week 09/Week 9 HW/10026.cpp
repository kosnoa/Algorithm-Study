/* Code By kosnoa
GitHub: kosnoa */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

char tmp[1001][1001];
int arr1[1001][1001];
int arr2[1001][1001];
bool visited[1001][1001];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, c1, c2;

void dfs_color(int x, int y, int num)
{
    visited[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 <= nx && nx < n && 0 <= ny && ny < n)
        {
            if (arr1[nx][ny] == num && visited[nx][ny] == false)
            {
                dfs_color(nx, ny, num);
            }
        }
    }
}
    
void dfs_not_color(int x, int y, int num)
{
    visited[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 <= nx && nx < n && 0 <= ny && ny < n)
        {
            if (arr2[nx][ny] == num && visited[nx][ny] == false)
            {
                dfs_not_color(nx, ny, num);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> tmp[i][j];
        }
    }

    // Not the case

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (tmp[i][j] == 'R')
            {
                arr1[i][j] = 1;
            }
            else if (tmp[i][j] == 'G')
            {
                arr1[i][j] = 2;
            }
            else if (tmp[i][j] == 'B')
            {
                arr1[i][j] = 3;
            }
        }
    }

    // The case

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (tmp[i][j] == 'R' || tmp[i][j] == 'G')
            {
                arr2[i][j] = 1;
            }
            
            else if (tmp[i][j] == 'B')
            {
                arr2[i][j] = 2;
            }
        }
    }

    for (int i=1; i<4; i++)
    {
        for (int j=0; j<n; j++)
        {
            for (int k=0; k<n; k++)
            {
                if (arr1[j][k] == i && visited[j][k] == false)
                {
                    c1++;
                    dfs_color(j, k, i);
                }
            }
        } 
        memset(visited, false, sizeof(visited));
    }

    for (int i=1; i<3; i++)
    {
        for (int j=0; j<n; j++)
        {
            for (int k=0; k<n; k++)
            {
                if (arr2[j][k] == i && visited[j][k] == false)
                {
                    c2++;
                    dfs_not_color(j, k, i);
                }
            }
        } 
        memset(visited, false, sizeof(visited));
    }

    cout << c1 << ' ' << c2 << '\n';

    return 0;
}
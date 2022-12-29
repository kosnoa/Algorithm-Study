/* Code By kosnoa
GitHub : kosnoa */


#pragma GCC optimize("Ofast")
#pragma GCC ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
vector<string> vs;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
bool check[25][25];
int res[25*25];
int n, c;

void dfs(auto y, auto x)
{
    res[c]++; // Counting how many of them exist until it finishes checking the area.
    check[y][x] = true; // Indicating that this coordinate has been visited.


    for (int i=0; i<4; i++)
    {
        int ny = y + dy[i]; // Traversing to find any coordinate that has not been visited.
        int nx = x + dx[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n) // Skipping cases when it is Out of Bounds.
        {
            continue;
        }

        if (vs[ny][nx] == '1' && !check[ny][nx])
        {
            dfs(ny, nx); // Recursion.
        }
    }
}

int main()
{
    cin >> n;

    vs = vector<string>(n);

    for (auto& str : vs)
    {
        cin >> str;
    }


    for (auto i=0; i<n; i++)
    {
        for (auto j=0; j<n; j++)
        {
            if (vs[i][j] == '1' && !check[i][j])
            {
                c++;
                dfs(i, j);
            }
        }
    }

    cout << c << '\n';
    sort(res + 1, res + c + 1);
    for (int i=1; i<=c; i++)
    {
        cout << res[i] << '\n';
    }

    return 0;
}
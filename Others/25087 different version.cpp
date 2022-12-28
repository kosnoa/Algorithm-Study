/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

vector<string> board;
vector<vector<bool>> visited;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
string dir;
int r, c;

// x: 현재 가로 위치
// y: 현재 세로 위치
// rx: 2*2 박스 가로 좌표 정보
// ry: 2*2 박스 세로 좌표 정보
// px: 전 가로 위치 기록
// py: 전 세로 위치 기록

void dfs(int y, int x, int ry, int rx, int py, int px) 
{
    visited[y][x] = true;

    // 원래 하던 if 문을 합쳐서 정리해둔 코드
    auto is_visited = [&](auto ny, auto nx)
    {
        if (ny < 0 || ny >= r || nx < 0 || nx >= c)
        {
            return true;
        }

        if (visited[ny][nx])
        {
            return true;
        }

        if (board[ny][nx] == '#')
        {
            return true;
        }

        return false;
    };

    int tmp = 1;

    while (tmp < 4)
    {
        if (ry == 0 && !is_visited(y - 1, x))
        {
            dir.push_back('N');
            dfs(y-1, x, 1, rx, y, x);
            dir.push_back('S');
            rx ^= 1; // XOR 연산자, rx = rx ^ 1이랑 동일
            ++tmp;
        }
        else if (ry == 1 && !is_visited(y+1, x))
        {
            dir.push_back('S');
            dfs(y+1, x, 0, rx, y, x);
            dir.push_back('N');
            rx ^= 1; 
            ++tmp;
        }
        else if (rx == 0 && !is_visited(y, x-1))
        {
            dir.push_back('W');
            dfs(y, x-1, ry, 1, y, x);
            dir.push_back('E');
            ry ^= 1;
            ++tmp;
        }
        else if (rx == 1 && !is_visited(y, x+1))
        {
            dir.push_back('E');
            dfs(y, x+1, ry, 0, y, x);
            dir.push_back('W');
            ry ^= 1;
            ++tmp;
        }
        else if(ry == 0 && rx == 0)
        {
            dir.push_back('S');
            ry = 1;
            ++tmp;
        }
        else if(ry == 1 && rx == 0)
        {
            dir.push_back('E');
            rx = 1;
            ++tmp;
        }
        else if(ry == 0 && rx == 1)
        {
            dir.push_back('W');
            rx = 0;
            ++tmp;
        }
        else if(ry == 1 && rx == 1)
        {
            dir.push_back('N');
            ry = 0;
            ++tmp;
        }
    };

    if (y == 0 && x == 0)
    {
        dir.push_back('W');
    }
}

void Solve()
{
    dir.clear();
    cin >> r >> c;

    board = vector<string>(r);

    for (auto& str : board)
    {
        cin >> str;
    }

    // 위 코드를 풀었을 경우
    // for (int i=0; i<r; i++)
    // {
    //     string str;
    //     cin >> str;
    //     board.push_back(str);
    // }

    visited = vector<vector<bool>>(r, vector<bool>(c)); // 2차원 벡터

    dfs(0, 0, 0, 0, -1, 0);

    for (auto y = 0; y < r; ++y)
    {
        for (auto x = 0; x < c; ++x)
        {
            if(!visited[y][x] && board[y][x] == '*')
            {
                cout << "IMPOSSIBLE\n";
                return;
            }
        }
    }

    cout << dir << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";
        Solve();
    }

    return 0;
}
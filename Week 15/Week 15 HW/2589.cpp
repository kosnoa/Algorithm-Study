/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

/*
0,0 시작
W일 경우 건너뜀.
매 점 위치 확인, 이동값 저장.


방문 위치 숫자로 세기.
만약 방문 했는데 c의 값이 더 작다, 그러면 바꿔주기
아닐 경우 continue 하기
*/

queue<tuple<int, int, int>> qt;
char arr[51][51];
bool check[51][51];
int cnt[51][51];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int n, m, num = 0;

void bfs(int x, int y)
{
    fill(&cnt[0][0], &cnt[50][51], 0);
    fill(&check[0][0], &check[50][51], false);


    if (arr[x][y] == 'W')
    {
        return;
    }
    else
    {
        check[x][y] = true;
        qt.push(make_tuple(x, y, 0));

        while (!qt.empty())
        {
            tuple<int, int, int> cur = qt.front();

            qt.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = get<0>(cur) + dx[i];
                int ny = get<1>(cur) + dy[i];
                int c = get<2>(cur);

                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                {
                    continue;
                }
                else
                {
                    if (arr[nx][ny] == 'W')
                    {
                        continue;
                    }

                    if (arr[nx][ny] == 'L' && !check[nx][ny])
                    {
                        check[nx][ny] = true;
                        cnt[nx][ny] = c + 1;
                        qt.push(make_tuple(nx, ny, c + 1));

                        if (c + 1 > num)
                        {
                            num = c + 1;
                        }
                    }
                    else if (arr[nx][ny] == 'L' && check[nx][ny])
                    {
                        if (cnt[nx][ny] > c + 1)
                        {
                            cnt[nx][ny] = c + 1;
                            qt.push(make_tuple(nx, ny, c + 1));

                            if (c + 1 > num)
                            {
                                num = c + 1;
                            }
                        }
                        else
                        {
                            continue;
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            bfs(i, j);
        }
    }

    cout << num << '\n';

    return 0;
}
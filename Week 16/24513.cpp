/* Code By kosnoa
GitHub : kosnoa */

/*
1번 바이러스 확인
2번 바이러스 확인
3번 바이러스는 1번 2번이 그 칸에 동시에 침투했을 경우
3번 바이러스는에서 출발 불가능
1번 바이러스 먼저 돌리기
2번 바이러스 돌리면서 1번의 방문 여부 확인

*/

// 벽인 경우 고려, 시간을 잘 사용

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
int arr[1001][1001];
pair<int, int> virus1;
pair<int, int> virus2;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
bool check[1001][1001];
int hour[1001][1001];
int infect[1001][1001];
queue<tuple<int, int, int>> qp1;
queue<tuple<int, int, int>> qp2;
tuple<int, int, int> cur1;
tuple<int, int, int> cur2;
int cnt1 = 0, cnt2 = 0, cnt3 = 0;
int n, m;

void bfs()
{
    qp1.push(make_tuple(virus1.first, virus1.second, 0));
    qp2.push(make_tuple(virus2.first, virus2.second, 0));
    

    while (!qp1.empty() && !qp2.empty())
    {
        if (!qp1.empty())
        {
            cur1 = qp1.front();
            qp1.pop();
        }
        else
        {
            cur1 = make_tuple(-1, -1, 100000000);
        }

        if (!qp2.empty())
        {
            cur2 = qp2.front();
            qp2.pop();
        }
        else
        {
            cur2 = make_tuple(-1, -1, 100000000);
        }

        for (int i = 0; i < 4; i++)
        {
            int nx1 = get<0>(cur1) + dx[i];
            int ny1 = get<1>(cur1) + dy[i];

            int nx2 = get<0>(cur2) + dx[i];
            int ny2 = get<1>(cur2) + dy[i];

            if (nx1 < 0 || nx1 >= n || ny1 < 0 || ny1 >= m)
            {
                continue;
            }

            if (!check[nx1][ny1])
            {
                hour[nx1][ny1] = get<2>(cur1);
                check[nx1][ny1] = true;
                infect[nx1][ny1] = 1;
                qp1.push(make_tuple(nx1, ny1, get<2>(cur1) + 1));
            }
            else if (check[nx1][ny1] && hour[nx1][ny1] > get<2>(cur1) && infect[nx1][ny1] == 2)
            {
                hour[nx1][ny1] = get<2>(cur1);
                infect[nx1][ny1] = 1;
                qp1.push(make_tuple(nx1, ny1, get<2>(cur1) + 1));
            }

            if (nx2 < 0 || nx2 >= n || ny2 < 0 || ny2 >= m)
            {
                continue;
            }

            if (!check[nx2][ny2])
            {
                hour[nx2][ny2] = get<2>(cur2);
                check[nx2][ny2] = true;
                infect[nx2][ny2] = 2;
                qp2.push(make_tuple(nx2, ny2, get<2>(cur2) + 1));
            }
            else if (check[nx2][ny2] && hour[nx2][ny2] > get<2>(cur2) && infect[nx2][ny2] == 1)
            {
                hour[nx2][ny2] = get<2>(cur2);
                infect[nx2][ny2] = 2;
                qp2.push(make_tuple(nx2, ny2, get<2>(cur2) + 1));
            }
            else if (get<2>(cur2)+1 == hour[nx2][ny2] && nx2 != virus2.first && ny2 != virus2.second && infect[nx2][ny2] == 1)
            {
                infect[nx2][ny2] = 3;
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

            if (arr[i][j] == 1)
            {
                virus1 = make_pair(i, j);
                
            }

            if (arr[i][j] == 2)
            {
                virus2 = make_pair(i, j);
            }

            if (arr[i][j] == -1)
            {
                hour[i][j] = -1;
                check[i][j] = true;
            }
        }
    }

    bfs();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (infect[i][j] == 1)
            {
                cnt1++;
            }
            else if (infect[i][j] == 2)
            {
                cnt2++;
            }
            else if (infect[i][j] == 3)
            {
                cnt3++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << infect[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << cnt1 << ' ' << cnt2 << ' ' << cnt3 << '\n';

    return 0;
}
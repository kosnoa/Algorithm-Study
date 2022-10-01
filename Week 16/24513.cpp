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
bool check1[1001][1001];
bool check2[1001][1001];
int infect1[1001][1001];
int infect2[1001][1001];
int cnt1 = 0, cnt2 = 0, cnt3 = 0;
int n, m;

void bfs()
{
    queue<pair<int, int>> qp1;
    queue<pair<int, int>> qp2;
    qp1.push(virus1);
    qp2.push(virus2);
    
    

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
        }
    }

    bfs();
    

    cout << cnt1 << ' ' << cnt2 << ' ' << cnt3 << '\n';

    return 0;
}
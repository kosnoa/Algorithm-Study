/* Code By kosnoa
GitHub: kosnoa */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

queue<pair<ll, ll>> qp;
vector<pair<ll, ll>> ladder;
vector<pair<ll, ll>> snake;
int n, m;

/*
1. 올라가는 경우 확인
2. 내려가는 경우 확인
3. 6인 경우 확인
*/

int bfs(int x)
{
    qp.push({x, 1});

    while (!qp.empty())
    {
        // 이 루프가 무한으로 돌고 있음
        pair<ll, ll> cur = qp.front();
        qp.pop();

        if (cur.first == 100)
        {
            return cur.second;
        }

        bool visit1 = false;
        bool visit2 = false;

        for (int i = 1; i <= 6; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (ladder[j].first == i + cur.first)
                {
                    cur.first = ladder[j].second;
                    cur.second++;
                    qp.push({cur.first, cur.second});
                    visit1 = true;
                    break;
                }
            }

            if (!visit1)
            {
                for (int j = 0; j < m; j++)
                {
                    if (snake[j].first == i + cur.first)
                    {
                        cur.first = snake[j].second;
                        cur.second++;
                        qp.push({cur.first, cur.second});
                        visit2 = true;
                        break;
                    }
                }
            }

            if (!visit1 && !visit2 && i + cur.first == 100)
            {
                cur.second++;
                return cur.second;
            }

            if (!visit1 && !visit2 && i == 6)
            {
                cur.first += i;
                cur.second++;
                qp.push({cur.first, cur.second});
            }

        }
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        ladder.push_back({a, b});
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        snake.push_back({a, b});
    }

    cout << bfs(1) << '\n';

    return 0;
}
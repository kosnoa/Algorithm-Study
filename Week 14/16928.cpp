/* Code By kosnoa
GitHub: kosnoa */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

queue<pair<ll, ll>> qp;
vector<pair<ll, ll>> ladder;
vector<pair<ll, ll>> snake;
bool check[105];
int n, m;


int bfs(int x)
{
    qp.push({x, 1});

    while (!qp.empty())
    {
        pair<ll, ll> cur = qp.front();
        qp.pop();

        if (cur.first == 100)
        {
            return cur.second - 1;
        }

        for (int i = 1; i <= 6; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (ladder[j].first == i + cur.first && !check[ladder[j].first])
                {
                    check[ladder[j].first] = true;
                    check[ladder[j].second] = true;
                    int tmp = cur.second + 1;
                    qp.push({ladder[j].second, tmp});
                    break;
                }
            }

            for (int j = 0; j < m; j++)
            {
                if (snake[j].first == i + cur.first && !check[snake[j].first])
                {
                    check[snake[j].first] = true;
                    check[snake[j].second] = true;
                    int tmp = cur.second + 1;
                    qp.push({snake[j].second, tmp});
                    break;
                }
            }

            if (i + cur.first == 100)
            {
                return cur.second;
            }

            if (!check[cur.first + i])
            {
                check[cur.first + i] = true;
                int tmp = cur.second + 1;
                qp.push({cur.first + i, tmp});
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
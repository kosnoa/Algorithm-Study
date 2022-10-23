/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

/*
소수 판정 미리 하기
입력 deque<char> ?
*/

bool prime[10001];
int check[10001];
queue<int> q;
int n, m;

void primeNum()
{
    for (int i = 2; i * i <= 9999; i++)
    {
        if (prime[i])
        {
            continue;
        }

        for (int j = i + i; j <= 9999; j += i)
        {
            prime[j] = true;
        }
    }
}

void bfs()
{
    q.push(n);
    check[n] = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            string node_s = to_string(cur); // node_s 1033 들어감

            for (int j = 0; j <= 9; j++)
            {
                node_s[i] = j + '0'; // node_s: "0033"
                int next = stoi(node_s);

                if (next >= 1000 && !prime[next] && check[next] == -1)
                {
                    check[next] = check[cur] + 1;
                    q.push(next);
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    primeNum();

    int T;
    cin >> T;
    while (T--)
    {
        memset(check, -1, sizeof(check));

        cin >> n >> m;

        bfs();

        if (check[m] != -1)
        {
            cout << check[m] << '\n';
        }
        else
        {
            cout << "Impossible" << '\n';
        }
    }

    return 0;
}
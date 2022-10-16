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

bool prime[10000];
bool check[10000];
queue<pair<int, int>> qp;
int n, m;

void primeNum()
{
    for (int i = 2; i <= 9999; i++)
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

int bfs()
{
    qp.push({n, 0});
    check[n] = true;

    while (!qp.empty())
    {
        pair<int, int> cur = qp.front();
        qp.pop();

        if (cur.first == m)
        {
            return cur.second;
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
        cin >> n >> m;
        cout << bfs() << '\n';
    }

    return 0;
}
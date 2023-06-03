/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
int n, res;
vector<ll> board;

bool check(int p)
{
    for (int i = 0; i < p; i++)
    {
        if (board[p] == board[i] || p - i == abs(board[p] - board[i]))
        // 앞은 같은 열 확인, 뒤는 대각선상에 확인
        {
            return false;
        }
    }

    return true;
}

void nqueen(int p)
{
    if (p == n)
    {
        res++;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        board[p] = i;
        if (check(p))
        {
            nqueen(p + 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;
    board = vector<ll>(n);
    nqueen(0);
    cout << res;

    return 0;
}
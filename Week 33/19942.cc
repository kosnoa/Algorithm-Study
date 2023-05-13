/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

vector<int> mr(4);
int tmp[16];
vector<int> res(16);
int n, cost = 7500, cnt;
struct nut
{
    int p;
    int f;
    int e;
    int v;
    int c;
};
vector<nut> vec;

void recursion(int r1, int r2, int r3, int r4, int r5, int r6, int r7)
{
    tmp[r7] = r1 + 1;
    if (r2 >= mr[0] && r3 >= mr[1] && r4 >= mr[2] && r5 >= mr[3] && r6 < cost)
    {
        cnt = r7;
        for (int i = 0; i <= r1; i++)
        {
            res[i] = tmp[i];
        }

        cost = r6;
    }
    for (int i = r1 + 1; i < n; i++)
    {
        recursion(i, r2 + vec[i].p, r3 + vec[i].f, r4 + vec[i].e, r5 + vec[i].v, r6 + vec[i].c, r7 + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;
    vec = vector<nut>(n);

    for (auto &i : mr)
    {
        cin >> i;
    }

    for (auto &i : vec)
    {
        cin >> i.p >> i.f >> i.e >> i.v >> i.c;
    }

    for (int i = 0; i < n; i++)
    {
        recursion(i, vec[i].p, vec[i].f, vec[i].e, vec[i].v, vec[i].c, 0);
    }

    if (cost == 7500)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << cost << '\n';


        for(int i = 0; i <= cnt; i++)
        {
            cout << res[i] << ' ';
        }
    }

    return 0;
}
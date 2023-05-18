/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
int n;
struct coord
{
    int x;
    int y;
};

coord home;
coord convei[100];
coord rock;
bool check[100];

bool bfs()
{
    queue<pair<int, int>> qp;
    qp.push({home.x, home.y});

    while(!qp.empty())
    {
        int x = qp.front().first;
        int y = qp.front().second;
        qp.pop();

        if(abs(x - rock.x) + abs(y - rock.y) <= 1000)
        {
            return true;
        }

        for(int i = 0; i < n; i++)
        {
            if(check[i])
            {
                continue;
            }
            
            int dist = abs(x - convei[i].x) + abs(y - convei[i].y);

            if(dist <= 1000)
            {
                check[i] = true;
                qp.push({convei[i].x, convei[i].y});
            }
        }

    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {   
        memset(convei, 0, sizeof(convei));
        memset(check, false, sizeof(check));
        cin >> n;
        cin >> home.x >> home.y;
        for(int i = 0; i < n; i++)
        {
            cin >> convei[i].x >> convei[i].y;
        }
        cin >> rock.x >> rock.y;

        if(bfs())
        {
            cout << "happy\n";
        }
        else
        {
            cout << "sad\n";
        }
    }

    return 0;
}
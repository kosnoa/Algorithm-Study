/* Code By kosnoa
GitHub : kosnoa */


#pragma GCC optimize("Ofast")
#pragma GCC ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
int n, idx, res;
vector<pair<ll, ll>> vec[100005];
bool check[100005]; 

void dfs(int cur, int val) {
    check[cur] = true;
    if(val > res) {
        res = val;
        idx = cur;
    }

    for(int i = 0; i < vec[cur].size(); i++) {
        int p = vec[cur][i].first;
        int d = vec[cur][i].second + val;
        if(!check[p]) {
            check[p] = true;
            dfs(p, d);
            check[p] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;
    for(int i=0;i<n;i++) {
        int p1, p2, d;
        cin >> p1;
        while(1) {
            cin >> p2;
            if(p2 == -1)
                break;
            else {
                cin >> d;
                vec[p1].push_back({p2, d});
            }
        }
    }

    dfs(1, 0);
    res = 0;
    memset(check, false, sizeof(check));
    dfs(idx, 0);
    cout << res;
    

    return 0;
}
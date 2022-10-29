/* Code By kosnoa
GitHub : kosnoa */


#pragma GCC optimize("Ofast")
#pragma GCC ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

int check [10000001];

void bfs(int n)
{
    queue<int> q;
    q.push(n);

}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) { 
        int n;
        cin >> n;
        bfs(n);
        
        memset(check, 0, sizeof(check));
    }    

    return 0;
}
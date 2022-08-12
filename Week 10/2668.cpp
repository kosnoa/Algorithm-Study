/* Code By kosnoa
GitHub : kosnoa */


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

int arr[105];
int visited[105];
vector<int> res;
int n;

// 사이클을 찾는다

void dfs(int start, int cur)
{
    if (visited[cur] == 0)
    {
        visited[cur] = start; 
        dfs(start, arr[cur]); 
    }
    else if(start == cur)
    {
        res.push_back(start);
        return;
    }
}


int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;

    
    for (int i=1; i<=n; i++)
    {
        cin >> arr[i];
    }

    for (int i=1; i<=n; i++)
    {
        memset(visited, 0, sizeof(visited));
        dfs(i, i);
    }
    
    cout << res.size() << '\n';

    sort(res.begin(), res.end());

    for (int i=0; i<res.size(); i++)
    {
        cout << res[i] << '\n';
    }

    return 0;
}
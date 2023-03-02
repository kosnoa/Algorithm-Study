#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

vector<string> v;
vector<string> s;
vector<string> ans;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < m; i++)
    {
        string tmp;
        cin >> tmp;
        s.push_back(tmp);
    }

    int cnt = 0;

    for (int i = 0; i < m; i++)
    {
        int low = 0;
        int high = n - 1;
        int mid;

        while (low <= high)
        {
            mid = (low + high) / 2;

            if (v[mid] == s[i])
            {
                ans.push_back(v[mid]);
                cnt++;
                break;
            }
            else if (v[mid] < s[i])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }

    sort(ans.begin(), ans.end());

    cout << cnt << '\n';
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << '\n';
    }

    return 0;
}
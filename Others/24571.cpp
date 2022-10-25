/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

vector<pair<string, string>> samegroup;
vector<pair<string, string>> diffgroup;
vector<tuple<string, string, string>> realgroup;


int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n, m, k, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        samegroup.push_back({s1, s2});
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        diffgroup.push_back({s1, s2});
    }

    cin >> k;
    for (int i = 0; i < k; i++)
    {
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        realgroup.push_back({s1, s2, s3});
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            bool same_vio[n];
            tuple<string, string, string> tcur = realgroup[j];
            pair<string, string> pcur = samegroup[i];

            if (pcur.first == get<0>(tcur))
            {
                if (pcur.second != get<1>(tcur) || pcur.second != get<2>(tcur))
                {
                    same_vio[i] = true;
                    cnt++;
                }
            }
            else if (pcur.first == get<1>(tcur))
            {
                if (pcur.second != get<0>(tcur) || pcur.second != get<2>(tcur))
                {
                    same_vio[i] = true;
                    cnt++;
                }
            }
            else if (pcur.first == get<2>(tcur))
            {
                if (pcur.second != get<0>(tcur) || pcur.second != get<1>(tcur))
                {
                    same_vio[i] = true;
                    cnt++;
                }
            }

            if(same_vio[i])
            {
                break;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < k; j++)
        {
            bool diff_vio[m];
            tuple<string, string, string> tcur = realgroup[j];
            pair<string, string> pcur = diffgroup[i];

            if (pcur.first == get<0>(tcur) || pcur.first == get<1>(tcur) || pcur.first == get<2>(tcur))
            {
                if (pcur.second == get<0>(tcur) || pcur.second == get<1>(tcur) || pcur.second == get<2>(tcur))
                {
                    cout << '\n' << get<0>(tcur) << ' ' << get<1>(tcur) << ' ' << get<2>(tcur) << ' ';
                    diff_vio[i] = true;
                    cnt++;
                }
            }
            else if (pcur.second == get<0>(tcur) || pcur.second == get<1>(tcur) || pcur.second == get<2>(tcur))
            {
                if (pcur.first == get<0>(tcur) || pcur.first == get<1>(tcur) || pcur.first == get<2>(tcur))
                {
                    cout << '\n' << get<0>(tcur) << ' ' << get<1>(tcur) << ' ' << get<2>(tcur) << ' ';
                    diff_vio[i] = true;
                    cnt++;
                }
            }

            if(diff_vio[i])
            {
                break;
            }
        }
    }


    cout << cnt << '\n';

    return 0;
}
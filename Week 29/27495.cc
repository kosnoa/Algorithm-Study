/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
string a1[3][3];
string a2[3][3];
string a3[3][3];
string a4[3][3];
string a5[3][3];
string a6[3][3];
string a7[3][3];
string a8[3][3];
vector<string> master;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (i < 3)
            {
                if (j < 3)
                {
                    cin >> a1[i][j];
                }
                else if (j > 5)
                {
                    cin >> a3[i][j - 6];
                }
                else
                {
                    cin >> a2[i][j - 3];
                }
            }
            else if (i > 5)
            {
                if (j < 3)
                {
                    cin >> a6[i - 6][j];
                }
                else if (j > 5)
                {
                    cin >> a8[i - 6][j - 6];
                }
                else
                {
                    cin >> a7[i - 6][j - 3];
                }
            }
            else
            {
                if (j < 3)
                {
                    cin >> a4[i - 3][j];
                }
                else if (j > 5)
                {
                    cin >> a5[i - 3][j - 6];
                }
                else
                {
                    string tmp;
                    cin >> tmp;
                    if (i == 4 && j == 4)
                    {
                        continue;
                    }

                    master.push_back(tmp);
                }
            }
        }
    }

    sort(master.begin(), master.end());

    for (int i = 0; i < master.size(); i++)
    {
        vector<string> vs;
        if (master[i] == a1[1][1])
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    if (j == 1 && k == 1)
                    {
                        continue;
                    }

                    vs.push_back(a1[j][k]);
                }
            }
            
            sort(vs.begin(), vs.end());

            for (int i=0; i<vs.size(); i++)
            {

            }


            printf("#%d. %s\n", i + 1, master[i].c_str());
            for (int j = 0; j < vs.size(); j++)
            {
                printf("#%d-%d. %s\n", i + 1, j + 1, vs[j].c_str());
            }
        }
        else if (master[i] == a2[1][1])
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    if (j == 1 && k == 1)
                    {
                        continue;
                    }

                    vs.push_back(a2[j][k]);
                }
            }
            sort(vs.begin(), vs.end());
            printf("#%d. %s\n", i + 1, master[i].c_str());
            for (int j = 0; j < vs.size(); j++)
            {
                printf("#%d-%d. %s\n", i + 1, j + 1, vs[j].c_str());
            }
        }
        else if (master[i] == a3[1][1])
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    if (j == 1 && k == 1)
                    {
                        continue;
                    }

                    vs.push_back(a3[j][k]);
                }
            }
            sort(vs.begin(), vs.end());
            printf("#%d. %s\n", i + 1, master[i].c_str());
            for (int j = 0; j < vs.size(); j++)
            {
                printf("#%d-%d. %s\n", i + 1, j + 1, vs[j].c_str());
            }
        }
        else if (master[i] == a4[1][1])
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    if (j == 1 && k == 1)
                    {
                        continue;
                    }

                    vs.push_back(a4[j][k]);
                }
            }
            sort(vs.begin(), vs.end());
            printf("#%d. %s\n", i + 1, master[i].c_str());
            for (int j = 0; j < vs.size(); j++)
            {
                printf("#%d-%d. %s\n", i + 1, j + 1, vs[j].c_str());
            }
        }
        else if (master[i] == a5[1][1])
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    if (j == 1 && k == 1)
                    {
                        continue;
                    }

                    vs.push_back(a5[j][k]);
                }
            }
            sort(vs.begin(), vs.end());
            printf("#%d. %s\n", i + 1, master[i].c_str());
            for (int j = 0; j < vs.size(); j++)
            {
                printf("#%d-%d. %s\n", i + 1, j + 1, vs[j].c_str());
            }
        }
        else if (master[i] == a6[1][1])
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    if (j == 1 && k == 1)
                    {
                        continue;
                    }

                    vs.push_back(a6[j][k]);
                }
            }
            sort(vs.begin(), vs.end());
            printf("#%d. %s\n", i + 1, master[i].c_str());
            for (int j = 0; j < vs.size(); j++)
            {
                printf("#%d-%d. %s\n", i + 1, j + 1, vs[j].c_str());
            }
        }
        else if (master[i] == a7[1][1])
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    if (j == 1 && k == 1)
                    {
                        continue;
                    }

                    vs.push_back(a7[j][k]);
                }
            }
            sort(vs.begin(), vs.end());
            printf("#%d. %s\n", i + 1, master[i].c_str());
            for (int j = 0; j < vs.size(); j++)
            {
                printf("#%d-%d. %s\n", i + 1, j + 1, vs[j].c_str());
            }
        }
        else if (master[i] == a8[1][1])
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    if (j == 1 && k == 1)
                    {
                        continue;
                    }

                    vs.push_back(a8[j][k]);
                }
            }
            sort(vs.begin(), vs.end());
            printf("#%d. %s\n", i + 1, master[i].c_str());
            for (int j = 0; j < vs.size(); j++)
            {
                printf("#%d-%d. %s\n", i + 1, j + 1, vs[j].c_str());
            }
        }
    }

    return 0;
}
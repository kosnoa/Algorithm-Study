#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        deque<int> dq;

        string s;
        cin >> s;

        int n;
        cin >> n;

        string s2;
        cin >> s2;
        vector<int> v;
        

        for (int i=0; i<s2.size(); i++)
        {
            string s3;
            if (s[i] == '[')
            {
                while (s[i] != ',')
                {
                    i++;
                    s3 = s[i];
                }
                
                v.push_back(atoi(s3.c_str()));
            }
            
            if (s[i] == ',')
            {
                i++;
                while (s[i] != ',' || s[i] != ']')
                {
                    i++;
                    s3 = s[i];
                }
                
                v.push_back(atoi(s3.c_str()));
            }   
        }

    }

    return 0;
}
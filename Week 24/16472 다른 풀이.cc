#include <iostream>
#include <string.h>

using namespace std;

int alpha[26];

int main()
{
    int n;
    cin >> n; // n : 2
    string str;
    cin >> str; // str : abbcaccba
    int len = str.length();

    int left = 0;
    int right = 0;
    int res = 0;
    int cnt = 0;

    // left : 0, right ; 0. res : 0, cnt : 0

    while (1)
    {
        while (right < len && cnt <= n)
        {
            int idx = str[right++] - 'a'; // idx : 0
            alpha[idx]++;                 // alpha[0] : 1
            if (alpha[idx] == 1)
                cnt++; // cnt : 1
            if (cnt > n)
                break;
            res = max(res, right - left);
        }
        if (right == len)
            break;

        while (cnt > n)
        {
            int idx = str[left++] - 'a';
            alpha[idx]--;
            if (alpha[idx] == 0)
                cnt--;
        }
    }
    cout << res << endl;
    return 0;
}

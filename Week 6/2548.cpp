#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

vector<int> v;

void BinarySearch(int len, int target)
{
    int low = (target + v[0]) / 2;
    int high = (target + v[v.size() - 1]) / 2;
    int mid;

    while (low <= high)
    {
        int low_tmp = 0, mid_tmp = 0, high_tmp = 0;
        mid = (low + high) / 2;

        for (int i=0; i<v.size(); i++)
        {
            low_tmp += abs(low-v[i]);
            mid_tmp += abs(mid-v[i]);
            high_tmp += abs(high-v[i]);
        }

        if (mid_tmp < low_tmp && mid_tmp < high_tmp)
        {
            cout << mid << '\n';
            break;
        }
        else if (mid_tmp > low_tmp && high_tmp > low_tmp)
        {
            mid = low;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    // 첫 번쨰 경우에만 내가 해준다 (평균값 구하기 & 최소값과 평균값의 중간값 & 최댓값과 평균값의 중간값)

    int avg = 0;
    for (int i = 0; i < v.size(); i++)
    {
        avg += v[i];
    }

    avg /= v.size();

    BinarySearch(v.size(), avg);

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

vector<int> v;
int repNum = 0, save = 0;
int low = v[0];
int high = v[v.size() - 1];

void BinarySearch(int len)
{
    int mid;

    while (low <= high)
    {
        int low_tmp = 0, mid_tmp = 0, high_tmp = 0;
        mid = (low + high) / 2;

        for (int i = 0; i < v.size(); i++)
        {
            low_tmp += abs(low - v[i]);
            mid_tmp += abs(mid - v[i]);
            high_tmp += abs(high - v[i]);
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

    int low_tmp = 0, mid_tmp = 0, high_tmp = 0;

    for (int i = 0; i < v.size(); i++)
    {
        low_tmp += abs(low - v[i]);
        mid_tmp += abs(avg - v[i]);
        high_tmp += abs(high - v[i]);
    }

    if (low_tmp == high_tmp)
    {
        cout << low << '\n';
    }

    int tmp = min(low_tmp, mid_tmp, high_tmp);

    if (tmp == low_tmp)
    {
        repNum = low_tmp;
    }
    else if (tmp == high_tmp)
    {
        repNum = high_tmp;
        low = avg + 1;
        BinarySearch(v.size());
    }
    else if (tmp == mid_tmp)
    {
        if (low_tmp < high_tmp)
        {
            high = avg - 1;
            BinarySearch(v.size());
        }
        else
        {
        }
    }

    return 0;
}

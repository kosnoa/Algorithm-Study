#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

vector<int> v;

void BinarySearch(int len)
{
    
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    
    for (int i=0; i<n; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    // 첫 번쨰 경우에만 내가 해준다 (평균값 구하기 & 최소값과 평균값의 중간값 & 최댓값과 평균값의 중간값)

    BinarySearch(v.size());
   

    return 0;
}
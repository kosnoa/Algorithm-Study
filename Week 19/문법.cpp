/* Code By kosnoa
GitHub : kosnoa */


#pragma GCC optimize("Ofast")
#pragma GCC ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

template<typename T1, typename T2>
T1 add(T1 x, T2 y)
{
    return x + y;
}



int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cout << add(10, 20) << '\n';
    cout << add(3.1, 1.5) << '\n';
    cout << add(10, 3.14) << '\n';

    return 0;
}
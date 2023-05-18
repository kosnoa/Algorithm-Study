/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
struct point
{
    double x;
    double y;
};

point a, b, c;

double len(point p, point q)
{
    double x = p.x - q.x;
    double y = p.y - q.y;
    return sqrt(x * x + y * y);
}

double slope(point p, point q)
{
    return abs(p.y - q.y) / abs(p.x - q.x);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    if (slope(b, a) == slope(c, b))
    {
        cout << "-1.0\n";
        exit(0);
    }

    double len1 = len(b, a);
    double len2 = len(c, b);
    double len3 = len(c, a);
    double peri1 = (len1 + len2) * 2;
    double peri2 = (len2 + len3) * 2;
    double peri3 = (len3 + len1) * 2;

    cout << fixed;
    cout.precision(16);

    cout << max({peri1, peri2, peri3}) - min({peri1, peri2, peri3});

    return 0;
}
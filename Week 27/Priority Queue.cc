/* Code By kosnoa
GitHub : kosnoa */


#pragma GCC optimize("Ofast")
#pragma GCC ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;


int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    priority_queue<int> pq; // 큰 수를 우선 순위
    // priority_queue<int, vector<int>, less<int>> pq; // 큰 수를 우선 순위
    // priority_queue<int, vector<int>, greater<int>> pq; // 작은 수를 우선 순위
    pq.push(20);
    pq.push(10);
    pq.push(50);
    pq.push(40);
    pq.push(30);

    /*
    다익스트라는 
    priority_queue<int> pq; // 큰 수를 우선 순위
    pq.push(-20);
    pq.push(-10);
    pq.push(-50);
    pq.push(-40);
    pq.push(-30);
    */


    while(!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}
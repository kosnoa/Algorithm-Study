/*
Study Purpose
*/

#pragma GCC optimize("Ofast")
#pragma GCC ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

struct node{
    char left;
    char right;
};

vector<node> v(26);

void preOrder(char node) // 전위 순회
{
    //root - left - right
    if(node == '.')
    {
        return;
    }

    cout << node;
    preOrder(v[node].left);
    preOrder(v[node].right);
}

void inOrder(char node)
{
    // left - root - right
    {
        if(node == '.')
        {
            return;
        }

        inOrder(v[node].left);
        cout << node;
        inOrder(v[node].right);
    }
}

void postOrder(char node)
{
    // left - right - root

    if(node == '.')
    {
        return;
    }

    postOrder(v[node].left);
    postOrder(v[node].right);
    cout << node;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;

    char root, l, r;
    for (int i=0; i<n; i++)
    {
        cin >> root >> l >> r;
        v[root].left = l;
        v[root].right = r;
    }

    preOrder('A');
    cout << '\n';

    inOrder('A');
    cout << '\n';

    postOrder('A');
    cout << '\n';

    return 0;
}
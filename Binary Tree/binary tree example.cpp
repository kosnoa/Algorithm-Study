/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

// 이진 탐색 트리의 연산

class Node
{
public:
    int data;
    Node *leftChild = NULL;
    Node *rightChild = NULL;

    Node(int _data, Node *_leftChild, Node *_rightChild)
        : data(_data), leftChild(_leftChild), rightChild(_rightChild)
    {
    }
};

// 탐색

// 트리에 target 이 있다면 true 리턴
bool BST_SearchNode(Node *tree, int target)
{
    if (tree = NULL)
    {
        return false;
    }

    if (tree->data == target)
    {
        return true;
    }
    else if (tree->data > target)
    {
        return BST_SearchNode(tree->leftChild, target);
    }
    else if (tree->data < target)
    {
        return BST_SearchNode(tree->rightChild, target);
    }
}

// 트리에 target이 있다면 해당 노드 리턴
Node *BST_SearchNode2(Node *tree, int target)
{
    if (tree == NULL)
    {
        return NULL;
    }

    if (tree->data == target)
    {
        return tree;
    }
    else if (tree->data > target)
    {
        return BST_SearchNode2(tree->leftChild, target);
    }
    else if (tree->data < target)
    {
        return BST_SearchNode2(tree->rightChild, target);
    }
}

void BST_InsertNode(Node *tree, Node *node)
{
    if (node->data < tree->data)
    { // 현재 재귀 단계에서의 트리의 루트와 크기 비교 (서브트리의 루트)
        if (tree->leftChild == NULL)
        { // 루트보다 작은데 마침 루트에게 왼쪽 자식이 없다면 루트의 왼쪽 자식으로 세팅 후 종료
            tree->leftChild = node;
            return;
        }
        else
        {
            BST_InsertNode(tree->leftChild, node); 
            // 루트보다 작은데 루트에게 왼쪽 자식이 있다면 거기에 추가될 수 없으므로 더 내려가야 함. 왼쪽 서브트리로 내려가기.
        }
    }
    else if (node->data > tree->data)
    { // 루트보다 큰데 마침 루트에게 오른쪽 자식이 없다면 루트의 오른쪽 자식으로 세팅 후 종료
        if (tree->rightChild == NULL)
        {
            tree->rightChild = node;
            return;
        }
        else
        {
            BST_InsertNode(tree->rightChild, node);
            // 루트보다 큰데 루트에게 오른쪽 자식이 있다면 거기에 추가될 수 없으므로 더 내려가야 함. 오른쪽 서브트리로 내려가기.
        }
    }
}
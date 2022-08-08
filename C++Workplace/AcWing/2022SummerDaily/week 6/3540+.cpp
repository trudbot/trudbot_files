
//
// Created by trudbot on 2022/7/11.
//

#include <bits/stdc++.h>

#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;

typedef struct node{
    node* l, *r;
    int val;
}*Node;

Node NewNode(int key)
{
    Node t = new node;
    t->val = key;
    t->l = t->r = nullptr;
}

Node Insert(Node root, int key)
{
    if(!root) return NewNode(key);
    if(key > root->val)
        root->r = Insert(root->r, key);
    else if(key < root->val)
        root->l = Insert(root->l, key);
    return root;
}

void Insert_1(Node root, int key)
{
    Node t = NewNode(key);
    while(root)//死循环
    {
        if(root->val < key)
        {
            if(!root->r)
            {
                root->r = t;
                break;
            }
            root = root->r;
        }
        else if(root->val > key)
        {
            if(!root->l)
            {
                root->l = t;
                break;
            }
            root = root->l;
        }
        else
        {
            free(t);
            break;
        }
    }
}

void Preorder(Node root)
{
    if(!root) return;
    cout << root->val << " ";
    Preorder(root->l);
    Preorder(root->r);
}

void Inorder(Node root)
{
    if(!root) return;
    Inorder(root->l);
    cout << root->val << " ";
    Inorder(root->r);
}

void Postorder(Node root)
{
    if(!root) return;
    Postorder(root->l);
    Postorder(root->r);
    cout << root->val << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    Node root = nullptr;
    while(n--)
    {
        int t;
        cin >> t;
        root = Insert(root, t);
    }
    Preorder(root); cout << endl;
    Inorder(root); cout << endl;
    Postorder(root); cout << endl;
    return 0;
}
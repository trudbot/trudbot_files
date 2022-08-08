
//
// Created by trudbot on 2022/7/11.
//

#include <bits/stdc++.h>

#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
const int N = 1010;

int l[N], r[N];

int AddNode(int root, int key)
{
    if(root == 0)
        return key;
    else if(root > key)
        l[root] = AddNode(l[root], key);
    else if(root < key)
        r[root] = AddNode(r[root], key);
    return root;
}

void Preorder(int root)
{
    if(root == 0) return;
    cout << root << " ";
    Preorder(l[root]);
    Preorder(r[root]);
}

void InOrder(int root)
{
    if(root == 0) return;
    InOrder(l[root]);
    cout << root << " ";
    InOrder(r[root]);
}

void Postorder(int root)
{
    if(root == 0) return;
    Postorder(l[root]);
    Postorder(r[root]);
    cout << root << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, t, root = 0;
    cin >> n;
    while(n--)
    {
        cin >> t;
        root = AddNode(root, t);
    }
    Preorder(root);
    cout << endl;
    InOrder(root);
    cout << endl;
    Postorder(root);
    cout << endl;

    return 0;
}


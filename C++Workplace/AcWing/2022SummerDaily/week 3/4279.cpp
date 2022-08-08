//
// Created by trudbot on 2022/6/21.
//作者：trudbot 结果： Accepted 通过了 10/10个数据 运行时间：10 ms 运行空间: 212 KB

#include <bits/stdc++.h>
using namespace std;

typedef struct node{
    int val;
    struct node* left, *right;
}*Node;

//新建结点
inline Node NewNode(int val){
    Node n = new node;
    n->val = val;
    n->left = n->right = nullptr;
    return n;
}

inline int FindMin(const int* seq, int first, int last){
    if(first == last){
        return first;
    }
    if(first > last){
        return -1;
    }
    int mini = first;
    while(++first <= last){
        if(seq[first] < seq[mini]){
            mini = first;
        }
    }
    return mini;
}

//树的建立
Node BuildTree(const int* seq, int first, int last){
    if(first == last){
        return NewNode(seq[first]);
    }
    if(first > last){
        return nullptr;
    }
    int pos = FindMin(seq, first, last);
    Node root = NewNode(seq[pos]);
    root->left = BuildTree(seq, first, pos-1);
    root->right = BuildTree(seq, pos+1, last);
    return root;
}

//广度优先遍历
void BFS(Node root){
    queue<Node> q;
    Node temp;
    q.push(root);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        cout << temp->val << " ";
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
}


int main() {
    int N;
    cin>> N;
    int seq[N];
    for(int i=0; i<N; i++){
        cin >> seq[i];
    }
    Node tree = BuildTree(seq, 0, N-1);
    BFS(tree);
    return 0;
}

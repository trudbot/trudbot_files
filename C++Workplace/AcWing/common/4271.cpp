//
// Created by trudbot on 2022/6/22.
//

#include <bits/stdc++.h>
#define MaxNum 1001
using namespace std;

int l[MaxNum], r[MaxNum], pre[MaxNum];

int Root;
int inorder[31], postorder[31];
int Level[MaxNum];

int BuildTree(int li, int ri, int lp, int rp){
    if(li > ri){
        return 0;
    }
    int root = postorder[rp];
    int i;
    for(i=li; i<=ri; i++){
        if(inorder[i] == root){
            break;
        }
    }
    l[root] = BuildTree(li, i-1, lp, lp+i-li-1);
    if(l[root] != 0){
        pre[l[root]] = root;
    }
    r[root] = BuildTree(i+1, ri, rp+i-ri, rp-1);
    if(r[root] != 0){
        pre[r[root]] = root;
    }
    return root;
}

void getLevel(int root, int level){
    if(root == 0){
        return;
    }
    Level[root] = level;
    getLevel(l[root], level+1);
    getLevel(r[root], level+1);
}

bool IsFullTree(int root){
    if((r[root] == 0) && (l[root] == 0)){//叶子结点
        return true;
    }
    if((r[root] == 0) ^ (l[root] == 0)){//度为1的结点
        return false;
    }
    return IsFullTree(l[root]) && IsFullTree(r[root]);
}

bool Solution(const string& str){
    int A, B;
    if(str.find("root") < str.length()){
        sscanf(str.c_str(), "%d", &A);
        return A == Root;
    }
    else if(str.find("siblings") < str.length()){
        sscanf(str.c_str(), "%d and %d", &A, &B);
        if(A == B) return false;
        return pre[A] == pre[B];
    }
    else if(str.find("parent") < str.length()){
        sscanf(str.c_str(), "%d is the parent of %d", &A, &B);
        return l[A] == B || r[A] == B;
    }
    else if(str.find("left") < str.length()){
        sscanf(str.c_str(), "%d is the left child of %d", &A, &B);
        return l[B] == A;
    }
    else if(str.find("right") < str.length()){
        sscanf(str.c_str(), "%d is the right child of %d", &A, &B);
        return r[B] == A;
    }
    else if(str.find("same level") < str.length()){
        sscanf(str.c_str(), "%d and %d", &A, &B);
        return Level[A] == Level[B];
    }
    else if(str.find("full tree") < str.length()){
        return IsFullTree(Root);
    }
}

int main() {
    int N;
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> postorder[i];

    for(int i=0; i<N; i++)
        cin >> inorder[i];

    Root = BuildTree(0, N-1, 0, N-1);
    getLevel(Root, 1);

    int M;
    cin >> M;
    getchar();
    string str;
    while(M--){
        getline(cin, str);
        if(Solution(str)){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }

    return 0;
}

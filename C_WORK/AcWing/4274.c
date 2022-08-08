/*
给定一个二叉表达式树，请你输出相应的后缀表达式，要求使用括号反映运算符的优先级。

输入格式
第一行包含整数 N，表示节点数量。节点编号 1∼N。

接下来 N 行，每行给出一个节点的信息（第 i 行对应第 i 个节点），格式为：

data left_child right_child
其中，data 是一个不超过 10 个字符的字符串，left_child 和 right_child 分别是该节点的左右子节点的编号。

没有子节点（即 NULL），则用 −1 表示。

下面两图分别对应给出的两个样例。

4d1c4a98-33cc-45ff-820f-c548845681ba.JPG b5a3c36e-91ad-494a-8853-b46e1e8b60cc.JPG

输出格式
在一行中输出答案，表达式符号之间不得有空格。

数据范围
1≤N≤20
输入样例1：
8
* 8 7
a -1 -1
* 4 1
+ 2 5
b -1 -1
d -1 -1
- -1 6
c -1 -1
输出样例1：
(((a)(b)+)((c)(-(d))*)*)
输入样例2：
8
2.35 -1 -1
* 6 1
- -1 4
% 7 8
+ 2 3
a -1 -1
str -1 -1
871 -1 -1
输出样例2：
(((a)(2.35)*)(-((str)(871)%))+)
*/

#include <stdio.h>
#include <string.h>

typedef struct{
    char data[11];//结点的内容
    int left, right;
    int pre;//前驱
}node;

node Tree[21];

void InitTree(void){
    for(int i=1; i<21; i++){
        Tree[i].left = Tree[i].right = Tree[i].pre = -1;
    }
}

void CreateTree(int N){
    for(int i=1; i<=N; i++){
        scanf("%s%d%d", Tree[i].data, &Tree[i].left, &Tree[i].right);
        if(Tree[i].left != -1){
            Tree[Tree[i].left].pre = i;
        }
        if(Tree[i].right != -1){
            Tree[Tree[i].right].pre = i;
        }
    }
}

int getRoot(void){
    int i = 1;
    while(Tree[i].pre != -1){
        i = Tree[i].pre;
    }
    return i;
}

int IsOneChild(int root){
    if(Tree[root].left == -1 && Tree[root].right == -1){
        return 0;
    }
    if(Tree[root].left != -1 && Tree[root].right != -1){
        return 0;
    }
    return 1;
}

void SuffixExp(int root){
    if(root == -1){
        return;
    }
    printf("(");
    if(IsOneChild(root)){
        printf("%s", Tree[root].data);
        SuffixExp(Tree[root].left);
        SuffixExp(Tree[root].right);
    }
    else{
        SuffixExp(Tree[root].left);
        SuffixExp(Tree[root].right);
        printf("%s", Tree[root].data);
    }
    printf(")");
}

int main(void){
    int N;
    scanf("%d", &N);

    InitTree();
    CreateTree(N);
    SuffixExp(getRoot());
}

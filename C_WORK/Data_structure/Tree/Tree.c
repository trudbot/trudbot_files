#include <stdio.h>
#include <stdlib.h>

struct TreeNode;
typedef struct TreeNode tree;
typedef tree* Node;
typedef Node Tree;
typedef Tree root;


struct TreeNode{
    int val;
    Node firstChild;
    Node nextSibling;
};
/*
为了最高效率的构造树：
    每个结点的child都放在一个链表里， 结点的firstchild指向链表的第一个结点
    每个结点的nextSibling指向它的下一个兄弟
*/

Node NewNode(int value){
    Node temp = (Node)malloc(sizeof(tree));
    temp->firstChild = NULL;
    temp->nextSibling = NULL;
    temp->val = value;
    return temp;
}

int IsHaveNoChild(Node parent){//是否没有child
    return parent->firstChild == NULL;
}

int IsHaveNoSibling(Node child){//是否没有sibling
    return child->nextSibling == NULL;
}

void AddChild(Node parent, Node child){
    if(IsHaveNoChild(parent)){
        parent->firstChild = child;
    }else{
        Node temp = parent->firstChild;
        while(! IsHaveNoSibling(temp)){
            temp = temp->nextSibling;
        }
        temp->nextSibling = child;
    }
}

//树的遍历方式
/*
在本文件中， 树的每个节点都有一个整数值
如果要对整颗数上的值求和，或者要将整棵树打印出来， 就需要遍历整颗树。
因此这里以树的求和函数和打印函数来展现树的遍历
*/
/*
由于树是递归定义的， 所以：
对数进行先序遍历， 其实就是先访问当前结点， 然后对结点的所有子树进行先序遍历。
*/

//1， 树的先序遍历 / preorder traversal
/*
“先序”的意思就是先访问当前结点， 再访问它的子结点。
由于树是递归定义的， 一个结点的子结点可以看成是一个个独立的树
所以对以root为根结点的树进行先序遍历其实就是先访问root结点， 然后对所有以root的子结点为根结点的子树进行先序遍历。
*/
/*先序遍历通常用来创建一颗树的副本， 因为它会先访问当前结点， 再访问子结点
还经常用来获取树的前缀表达式
*/

int TreeSum_1(root Root){//完全用递归来实现
    int sum = Root->val;
    
    if(! IsHaveNoChild(Root)){
        sum += TreeSum_1(Root->firstChild);
    }
    if(! IsHaveNoSibling(Root)){
        sum += TreeSum_1(Root->nextSibling);
    }

    return sum;
}

void DisplayThisTree_1(root Root){
    printf("%d ", Root->val);//访问当前结点

    //访问子结点
    if(! IsHaveNoChild(Root)){
        DisplayThisTree_1(Root->firstChild);
    }
    if(! IsHaveNoSibling(Root)){
        DisplayThisTree_1(Root->nextSibling);
    }
}

void DisplayThisTree_2(root Root, int depth){//打印数据的同时打印出它们之间的层次关系
    for(int i=0; i<depth; i++)
        printf("  ");
    printf("%d\n", Root->val);
    if(! IsHaveNoChild(Root)){
        DisplayThisTree_2(Root->firstChild, depth+1);
    }
    if(! IsHaveNoSibling(Root)){
        DisplayThisTree_2(Root->nextSibling, depth);
    }
}

int TreeSum_3(root Root){//另一种递归写法， 迭代和递归组合
    int sum = Root->val;
    
    Node child = Root->firstChild;
    while(child){
        sum += TreeSum_3(child);
        child = child->nextSibling;
    }
    return sum;
}

//2， 后序遍历 / postorder traversal
/*
与先序相对应的， 后序就是指先访问所有子结点， 在访问当前结点
所以， 后序遍历以root为根结点的树， 就是先后序遍历所有由root的子结点为根结点的子树， 最后再访问root
*/
/*
后序遍历通常用来删除树中的结点
也用于获取树的后缀表达式
*/
//为了展现前序遍历和后序遍历的区别， 在此只写display函数
void DisplayThisTree_3(root Root){

    if(! IsHaveNoChild(Root)){//访问子结点
        DisplayThisTree_3(Root->firstChild);
    }
    printf("%d ", Root->val);//当前树下的子结点都访问完后， 访问当前结点

    if(! IsHaveNoSibling(Root)){//访问兄弟结点
        DisplayThisTree_3(Root->nextSibling);
    }
}

void DisplayThisTree_4(root Root){//相比之下， 这种递归写法能更好的反映后序遍历的思想， 且效率更高
    Node child = Root->firstChild;
    while(child){
        DisplayThisTree_4(child);
        child = child->nextSibling;
    }
    printf("%d ", Root->val);
}

//3, 中序遍历 / inorder traversal
/*
思想是先访问当前结点的第一个子结点， 然后访问当前结点， 最后访问其余子结点
*/

void DisplayThisTree_5(root Root){
    if(IsHaveNoChild(Root)){
        printf("%d ", Root->val);
    }else{
        Node child = Root->firstChild;
        DisplayThisTree_5(child);
        printf("%d ", Root->val);
        while(! IsHaveNoSibling(child)){
            child = child->nextSibling;
            DisplayThisTree_5(child);
        }
    }
}//中序遍历主要为二叉树所设计

//先、中、后序遍历都属于“深度优先遍历”/"深度优先搜索"
/*
深度优先遍历介绍， 摘自维基百科。

深度优先搜索算法（英语：Depth-First-Search，DFS）是一种用于遍历或搜索树或图的算法。
这个算法会尽可能深地搜索树的分支。当节点v的所在边都己被探寻过，搜索将回溯到发现节点v的那条边的起始节点。
这一过程一直进行到已发现从源节点可达的所有节点为止。
如果还存在未被发现的节点，则选择其中一个作为源节点并重复以上过程，整个进程反复进行直到所有节点都被访问为止。
这种算法不会根据图的结构等信息调整执行策略。

深度优先搜索是图论中的经典算法，利用深度优先搜索算法可以产生目标图的拓扑排序表，
利用拓扑排序表可以方便的解决很多相关的图论问题，如无权最长路径问题等等。

因发明“深度优先搜索算法”，约翰·霍普克洛夫特与罗伯特·塔扬在1986年共同获得计算机领域的最高奖：图灵奖。
*/
//一般使用栈数据结构来实现深度优先搜索

//除了像上述一样使用递归中的栈结构来实现算法， 也可以自定义栈结构来实现。

int main(void){
    root Root = NewNode(1);
    Node a = NewNode(2);
    Node b = NewNode(3);
    Node c = NewNode(4);
    Node d = NewNode(5);
    Node e = NewNode(6);
    Node f = NewNode(7);
    Node g = NewNode(8);
    AddChild(Root, a);
    AddChild(Root, b);
    AddChild(a, c);
    AddChild(b, d);
    AddChild(c, e);
    AddChild(e, f);
    AddChild(e, g);
    printf("先序遍历: ");
    DisplayThisTree_1(Root);
    printf("\n");
    printf("中序遍历: ");
    DisplayThisTree_5(Root);
    printf("\n");
    printf("后序遍历: ");
    DisplayThisTree_4(Root);
}



//Created by liuxiangshuo on 2022/6/5
//层次树

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MaxNum 20

typedef enum bool{
    false, true
}bool;

typedef struct node{
    double x, y;//坐标
    int num;//编号
    struct node* left, *right;
}node, *Node;

typedef struct TreeBuilder{
    int len;
    Node* array;
    bool Visited[MaxNum];
    double distance[MaxNum][MaxNum];
}*TreeBuilder;

typedef unsigned Index;

//new a node
Node NewNode(double x, double y, int num){
    Node tNode = (Node)malloc(sizeof(node));
    tNode->x = x;
    tNode->y = y;
    tNode->left = NULL;
    tNode->right = NULL;
    tNode->num = num;
    return tNode;
}

//new a tree builder
TreeBuilder NewBuilder(int len){
    TreeBuilder builder = (TreeBuilder)malloc(sizeof(struct TreeBuilder));
    builder->len = len;
    builder->array = (Node*)calloc(len, sizeof(Node));
    return builder;
}

//计算两点间的距离
double Calc(Node n1, Node n2){
    return sqrt(pow(n1->x - n2->x, 2) + pow(n1->y - n2->y, 2));
}

//得到两个结点的父结点
Node getParent(Node n1, Node n2, int num){
    double x = (n1->x + n2->x)/2;
    double y = (n1->y + n2->y)/2;
    Node parent = NewNode(x, y, num);
    return parent;
}

//获取所有点彼此的距离
void getDistances(TreeBuilder builder){
    for(int i=0; i<builder->len; i++){
        for(int j=i+1; j<builder->len; j++){
            builder->distance[i][j] = builder->distance[j][i] = Calc(builder->array[i], builder->array[j]);
        }
    }
}

//更新某个结点与其它结点之间的距离
void UpdateDistance(TreeBuilder builder, Index i){
    for(int j=0; j<builder->len; j++){
        if(j != i && !builder->Visited[j]){
            builder->distance[i][j] = builder->distance[j][i]= Calc(builder->array[i], builder->array[j]);
        }
    }
}

//选择数组中距离最小的两个结点
void SelectTwoMin(TreeBuilder builder, Index* min1, Index* min2){
    Index s1, s2;
    double MinVal = __INT_MAX__;
    for(Index i=0; i<builder->len; i++){
        for(Index j=i+1; j<builder->len; j++){
            if(!(builder->Visited[i] || builder->Visited[j]) && builder->distance[i][j] < MinVal){
                s1 = i;
                s2 = j;
                MinVal = builder->distance[i][j];
            }
        }
    }
    *min1 = s1;
    *min2 = s2;
}

Node BuildTree(double* xCoords, double* yCoords, int len){
    TreeBuilder builder = NewBuilder(len);
    int num = len;//计数器， 用来生成结点的编号
    Node parent;

    //将数据输入结点数组以及Visited数组初始化
    for(int i=0; i<len; i++){
        builder->array[i] = NewNode(xCoords[i], yCoords[i], i+1);
        builder->Visited[i] = false;
    }
    
    getDistances(builder);//进行初始化

    Index min1, min2;
    for(int i=0; i<len-1; i++){//通过计算可知， n个结点形成层次树仅需要n-1次选择
        SelectTwoMin(builder, &min1, &min2);
        printf("第%d次选择, %d号样本和%d号样本之间的距离为%.2lf, 组合成了%d号样本的子树, ", (++num)-len, 
                                                                builder->array[min1]->num, 
                                                                builder->array[min2]->num, 
                                                                builder->distance[min1][min2], 
                                                                num);
        builder->Visited[min1] = true;

        //生成min1和min2的父结点， 并把父节点放到min2的位置
        parent = getParent(builder->array[min1], builder->array[min2], num);
        printf("%d号样本的坐标为(%.2lf, %.2lf)\n", num, parent->x, parent->y);

        parent->left = builder->array[min1];
        parent->right = builder->array[min2];
        builder->array[min2] = parent;

        UpdateDistance(builder, min2);
    }

    for(int i=0; i<len; i++){//将唯一的未被选择的结点找到
        if(!builder->Visited[i]){
            parent = builder->array[i];
            free(builder->array);
            free(builder);
            break;
        }
    }
    return parent;
}

//先序遍历
void PreTraversal(Node root){
    if(!root){
        return;
    }
    printf("%d ", root->num);
    PreTraversal(root->left);
    PreTraversal(root->right);
}

int main(void){
    double xCoord[] = {5.1, 4.9, 4.7, 6.1, 6.3, 6.1, 6.3, 6.5, 6.2};
    double yCoord[] = {3.5, 3.0, 3.2, 2.8, 2.5, 2.8, 2.5, 3.0, 3.4};

    Node root = BuildTree(xCoord, yCoord, 9);
    printf("先序遍历结果: ");
    PreTraversal(root);
}
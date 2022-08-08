//Created by 宋遗平 on 2022/5/3
//topic: Binary search tree

/*
以每个结点的键(key)为一个整数的二叉查找树举例(并且假设结点的key互异)
二叉查找树有如下特性：
    根结点的左子树中的每一个结点的值都要小于根结点的值
    根结点的右子树中的每一个结点的值的要大于根结点的值
    每一个子树都是二叉查找树
*/

# include <stdio.h>
# include <stdlib.h>

struct BinarySearchTree;
typedef struct BinarySearchTree searchTree;
typedef struct BinarySearchTree* SearchTree;
typedef struct BinarySearchTree* Position;

struct BinarySearchTree{
    int key;
    SearchTree left;
    SearchTree right;
};

//base part
SearchTree NewTree(int key){
    SearchTree tree = (SearchTree)malloc(sizeof(searchTree));
    tree->left = tree->right = NULL;
    tree->key = key;
    return tree;
}

//


//在查找树中找到给定key值的结点
Position Find1(SearchTree root, int key){
    if(! root){
        return NULL;//为NULL说明在当前树没有找到符号的结点
    }else if(key > root->key){
        Find1(root->right, key);//如果给定键值大于结点的键值， 则在结点的右子树中继续查找
    }else if(key < root->key){
        Find1(root->left, key);//小于则在左子树中查找
    }else{
        return root;//等于则返回当前结点的地址
    }
}//最多需要logn函数调用就能找到结果， 空间复杂度为O(logn)

Position Find2(SearchTree root, int key){//空间复杂度为O(1)的迭代实现
    while(root){
        if(key == root->key){
            break;
        }else if(key > root->key){
            root = root->right;
        }else if(key < root->key){
            root = root->left;
        }
    }
    return root;
}

//找最值
Position FindMax(SearchTree root){
    if(! root){
        return NULL;
    }
    while(root->right){
        root = root->right;
    }
    return root;
}

Position FindMin(SearchTree root){
    if(! root){
        return NULL;
    }
    while(root->left){
        root = root->left;
    }
    return root;
}

//插入
//由于查找树的特性， 往查找树中插入结点肯定可以插入到某个叶结点的后面
void Insert_1(SearchTree root, int key){
    SearchTree child = NewTree(key);
    while(root){
        if(child->key > root->key){
            if(root->right == NULL){
                root->right = child;
                return;
            }
            root = root->right;
        }
        else if(child->key < root->key){
            if(root->left == NULL){
                root->left = child;
                return;
            }
            root = root->left;
        }
        else{
            return;//查找树中已经存在了这个key的话, 什么也不做
        }
    }
}

SearchTree Insert_2(SearchTree root, int key){
    if(root == NULL){
        SearchTree tree = NewTree(key);
        return tree;
    }
    else if(root->key < key){
        root->right = Insert_2(root->right, key);
    }
    else if(root->key > key){
        root->left = Insert_2(root->left, key);
    }
    return root;
}

//删除结点
//删除查找树结点时, 要根据要删除结点的位置采用不同策略
/*
当结点为叶结点时, 直接删除即可
当结点仅有一个儿子时, 让儿子替代结点的位置, 再将结点删除

当结点有两个儿子时, 一般的策略是将结点的数据替换为结点右子树中最小的数据(或左子树中最大数据), 并将最小数据结点删除
这样做的原因是删除叶结点要比删除某棵树的根结点要简单的多
*/
SearchTree Delete(SearchTree root, int key){
    if(!root){
        return NULL;
    }
    else if(root->key > key){
        root->left = Delete(root->left, key);
    }
    else if(root->key < key){
        root->right = Delete(root->right, key);
    }
    else{//找到了对应匹配的结点
        Position temp;
        if(root->right && root->left){//two children
            temp = FindMin(root->right);//找到右子树中的最小元素
            root->key = temp->key;//将元素值赋给结点
            root->right = Delete(root->right, temp->key);//再删掉最小元素结点
        }
        else{//one or zero children
            temp = root;
            if(root->left){
                root = root->left;
            }
            else if(root->right){
                root = root->right;
            }
            else{
                root = NULL;
            }
            free(temp);
        }
    }
    return root;
}



int main(void){
    SearchTree root = NewTree(1);
    Insert_1(root, 2);
    Insert_1(root, -1);
    Insert_2(root, 9);
    Insert_1(root, 8);
    Insert_1(root, 5);
    root = Delete(root, 1);

}


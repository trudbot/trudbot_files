/*
Created by 宋遗平 on 2022/04/23
Topic: 二叉树
*/
# include <stdio.h>
# include <stdlib.h>

enum bool;
typedef enum bool bool;
struct BinaryTree;
typedef struct BinaryTree node;
typedef node* Node;
typedef Node BinTree;

struct BinaryTree
{
    int val;
    Node left;
    Node right;
};

enum bool{
    false = 0, true
};

Node NewNode(int value){
    Node temp = (Node)malloc(sizeof(node));
    temp->val = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

bool IsHaveNoChild(Node parent){
    return parent->left == NULL && parent->right == NULL;
}

bool IsHaveNoLeftChild(Node parent){
    return parent->left == NULL;
}

bool IsHaveNoRightChild(Node parent){
    return parent->right == NULL;
}

bool AddLeftChild(Node parent, Node child){
    if(parent->left != NULL){
        return false;
    }else{
        parent->left = child;
        return true;
    }
}

bool AddRightChild(Node parent, Node child){
    if(parent->right != NULL){
        return false;
    }else{
        parent->right = child;
        return true;
    }
}

bool AbandonLeftChild(Node parent){
    if(parent->left == NULL)
        return false;
    else{
        free(parent->left);
        parent->left = NULL;
        return true;
    }
}

bool AbandonRightChild(Node parent){
    if(parent->right == NULL)
        return false;
    else{
        free(parent->right);
        parent->right = NULL;
        return true;
    }
}

//二叉树的
void InorderTraversal(BinTree root){
    if(root != NULL){
        InorderTraversal(root->left);
        printf("%d ", root->val);
        InorderTraversal(root->right);
    }
}
//二叉树中中序遍历的顺序是左子树， 根结点， 右子树




int main(void){
    BinTree root = NewNode(1);
    BinTree a = NewNode(2);
    BinTree b = NewNode(3);
    BinTree c = NewNode(4);
    BinTree d = NewNode(5);
    BinTree e = NewNode(6);
    BinTree f = NewNode(7);
    BinTree g = NewNode(8);

    AddLeftChild(root, a);
    AddRightChild(root, b);
    AddLeftChild(a, c);
    AddRightChild(b, d);
    AddRightChild(c, e);
    AddLeftChild(e, f);
    AddRightChild(e, g);

    InorderTraversal(root);
}

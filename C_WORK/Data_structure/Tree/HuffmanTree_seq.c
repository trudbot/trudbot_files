#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define root 0

struct node;
typedef struct node node;
typedef node* HTNode;
typedef HTNode HTree;

struct node{
    char key;
    unsigned int weight;
    int parent;
    int left, right;
};

static unsigned Weights[128];//由于静态存储区的特性， 数组已经是全0数组了
static int charNum;//用于存放字符的种数(待定)

void Reversal(char *str)//将字符串逆序
{
    char *low = str;
    char *high = str+strlen(str)-1;
    char temp;
    while(low < high)
    {
        temp = *low;
        *low = *high;
        *high = temp;
        low++;
        high--;
    }
}

void InitHT(HTree HT, int len){
    HT[0].weight = len;//第一个元素不放数据， 放哈夫曼树的结点个数
    for(int i=1; i<=len; i++){
        HT[i].weight = 0;
        HT[i].parent = HT[i].left = HT[i].right = root;
    }
}

HTree NewHuffmanTree(int num){//num为叶结点的数量
    HTNode HT = (HTNode)malloc(sizeof(node)*(2*num));
    InitHT(HT, 2*num-1);

    int index = 1;
    for(int i=0; i<128; i++){
        if(Weights[i] != 0){
            HT[index].key = i;
            HT[index].weight = Weights[i];
            index++;
        }
    }
    return HT;
}


void Select(HTree HT, int end, int *s1, int *s2){
    //第一部分， 先找到表中两个未参与树构建的结点， 便于比较
    int min1, min2;
    int i = 1;
    while(HT[i].parent != 0 && i <= end){
        i++;
    }
    *s1 = i;
    min1 = HT[i].weight;
    i++;

    while(HT[i].parent != 0 && i <= end){
        i++;
    }
    if(min1 > HT[i].weight){//维护min1为小的， min2为相对更大的
        *s2 = *s1;
        min2 = min1;
        *s1 = i;
        min1 = HT[i].weight;
    }else{
        *s2 = i;
        min2 = HT[i].weight;
    }
    //第一部分结束

    //第二部分
    //让这两个结点与后续的未参与树构建的结点进行比较， 维护min1为最小的， min2为第二小的
    for(i++; i<=end; i++){
        if(HT[i].parent != 0){
            continue;
        }else if(HT[i].weight < min1){//权重比最小的还小时， 原min1退化为min2, min2丢弃，min1更新为当前结点
            min2 = min1;
            *s2 = *s1;
            *s1 = i;
            min1 = HT[i].weight;
        }else if(HT[i].weight < min2){//介于min1和min2之间时， min2更新为当前结点
            min2 = HT[i].weight;
            *s2 = i;
        }
    }
    //第二部分结束， 此时s1为表里所有未参与构建树的结点中权重最小的结点的下标， s2其次
}

int getFrequency(char* text){
    int num = 0;
    char* currChar = text;
    while(*currChar != '\0'){
        if(Weights[*currChar]++ == 0){
            num++;
        }
        currChar++;
    }
    return num;
}

HTree CreateHT(char* text){//创建哈夫曼树
    //哈夫曼树初始化
    charNum = getFrequency(text);
    HTree HT = NewHuffmanTree(charNum);

    //构建哈夫曼树
    int s1, s2;
    for(int i=charNum+1; i<=2*charNum-1; i++){
        Select(HT, i-1, &s1, &s2);
        HT[i].left = s1;
        HT[i].right = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
        HT[s1].parent = HT[s2].parent = i;
    }
    return HT;
}

void Coding(HTree HT){//得到用户输入权重对应的编码并输出
    char str[100];
    int len = 0;//用于保存每次的编码的字符串

    int thisParent;
    for(int i=1; i<=charNum; i++){
        int j = i;
        thisParent = HT[i].parent;
        while(thisParent != root){//从叶结点到根结点， 获取编码
            if(HT[thisParent].left == j){
                str[len++] = '0';
            }else{
                str[len++] = '1';
            }
            j = thisParent;
            thisParent = HT[j].parent;
        }
        str[len] = '\0';
        Reversal(str);//反转字符串

        printf("%c: %s\n", HT[i].key,  str);
        len = 0;
    }
}

void FreeHTree(HTree HT){
    free(HT);
}

void HuffmanCoding(char* text){
    HTree Ht = CreateHT(text);
    Coding(Ht);
    free(Ht);
}

int main(void){
    int num;
    char *text = "abcd";

    HuffmanCoding(text);
    return 0;
}
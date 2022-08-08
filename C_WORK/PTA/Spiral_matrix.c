/*
7-2 h0121. 螺旋矩阵 (15 分)
给定一个包含 N 个正整数的序列，请你将序列中的元素以非递增顺序填充到螺旋矩阵中。
从左上角的第一个元素开始填充，并按照顺时针方向旋转。
要求矩阵有 m 行 n 列，并且 m,n 满足：
m×n=N， m≥n， m−n 尽可能小

输入格式:
第一行包含整数 N，1≤N≤10000。

第二行包含 N 个整数，1≤ 序列中元素 ≤10000。

输出格式:
输出填充好的 m×n 的矩阵。

数字之间用一个空格隔开，结尾不得有多余空格。

输入样例:
12
37 76 20 98 76 42 53 95 60 81 58 93

输出样例:
98 95 93
42 37 81
53 20 76
58 60 76
*/
# include<stdio.h>
# include<math.h>
# include <stdlib.h>
# include <time.h>

void Creat_random_array(int **q, int len)
{
    *q = (int *)calloc(len, sizeof(int));

    srand((unsigned int)time(NULL));
    
    for (int i=0; i<len; i++)
    {
        (*q)[i] = rand()%100;
    }
}

void sort(int *arr, int len)
{
    int temp;
    for(int i=len-1; i>=0; i--)
        for(int j=0; j<i; j++)
            if(arr[j]<arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}

int* Closest_factor(int N)
{
    int *res = (int*)malloc(2*sizeof(int));
    int m, n;
    for(int i=sqrt(N); ;i--)
    {
        for(int j=i; j*i<=N; j++)
            if(i*j == N)
            {
                m = j;
                n = i;
                break;
            }
        if(n == i)
            break;
    }
    res[0] = m;
    res[1] = n;
    return res;
}

int** creat_array(int row, int column)
{
    int **arr = (int**)malloc(row*sizeof(int*));
    
    for(int i=0; i<row; i++)
        arr[i] = (int*)malloc(column*sizeof(int));

    return arr;
}

int ** fill_matrix(int *arr, int len, int m, int n)
{
    int **res = creat_array(m, n); 
    int j = 0, row = 0, col = 0, i=0, row_increment = 0, col_increment = 1;

    for(j=0; j<len; j++)
    {
        res[row][col] = arr[j];

        row += row_increment;
        col += col_increment;

        if(row==i && col==n-1-i) //达到对应位置时更改行、列增量， 以控制填充的方向
        {
            row_increment = 1;
            col_increment = 0;
        }
        else if(row==m-1-i && col==n-1-i)
        {
            row_increment = 0;
            col_increment = -1;
        }
        else if(row==m-1-i && col==i)
        {
            row_increment = -1;
            col_increment = 0;
        }
        else if(row==i+1 && col==i)
        {
            row_increment = 0;
            col_increment = 1;
            i++;
        }
    }

    return res;
    
}

void PRINT(int **arr, int row, int column)
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
            printf("%-5d", arr[i][j]);
        printf("\n");
    }
}

void FREE(int **arr, int row, int column)
{
    for(int i=0; i<row; i++)
        free(arr[i]);
    free(arr);
}

int main(void)
{
    int N;
    scanf("%d", &N);

    int *arr;
    Creat_random_array(&arr, N); //生成测试数据
    
    sort(arr, N); //排序

    int *factor = Closest_factor(N);
    int m = factor[0], n = factor[1];
    int **res = fill_matrix(arr, N, m, n);

    PRINT(res, m, n);

    free(factor);
    FREE(res, m, n);
    
    return 0;
}

/*
�������������� L1=a1��a2������an?1��an �� L2=b1��b2������bm?1��bm�����㣺n��2m��
��������ǽ��϶̵��Ǹ���������Ȼ��֮����ϳ��������õ����� a1��a2��bm��a3��a4��bm?1�� �Ľ����
���������������ֱ�Ϊ 6��7 �� 1��2��3��4��5����Ӧ����� 1��2��7��3��4��6��5��
����
�����п��ܰ������������������еĽڵ㣬��Щ�ڵ����迼�ǡ�

�����ʽ
���������ڵ�һ���и����������� L1 �� L2 ��ͷ���ĵ�ַ���Լ������� N���������Ľ��������
һ�����ĵ�ַ��һ�� 5 λ���ķǸ����������ܰ���ǰ�� 0�����յ�ַ NULL �� ?1 ��ʾ��
��� N �У�ÿ�а����¸�ʽ����һ��������Ϣ��
Address Data Next
���� Address �ǽ��ĵ�ַ��Data �ǲ����� 105 ����������Next ����һ�����ĵ�ַ��

��Ŀ��֤û�п��������ҽϳ������������ǽ϶��������������

�����ʽ
��˳������������ÿ�����ռһ�У���ʽ��������ͬ��

���ݷ�Χ
1��N��105
����������
00100 01000 7
02233 2 34891
00100 6 00001
34891 3 10086
01000 1 02233
00033 5 -1
10086 4 00033
00001 7 -1
���������
01000 1 02233
02233 2 00001
00001 7 34891
34891 3 10086
10086 4 00100
00100 6 00033
00033 5 -1
*/

#include <stdio.h>

typedef struct linkNode
{
    int val;
    int next;
}node;

node Link[100001];//��Ŀ���������Ϊ100000

//���ݵ�����
void Input(int N){
    int address, val, next;
    for(int i=0; i<N; i++){
        scanf("%d %d %d", &address, &val, &next);
        Link[address].next = next;
        Link[address].val = val;
    }
}

//��ת����
int reverse(int start){
    int curr, temp;
    curr = Link[start].next;
    Link[start].next = -1;
    while(curr != -1){
        temp = Link[curr].next;
        Link[curr].next = start;
        start = curr;
        curr = temp;
    }
    return start;
}

//��ȡ����
int getLen(int start){
    int len = 0;
    while(start != -1){
        len++;
        start = Link[start].next;
    }
    return len;
}

int Merge(int head1, int head2, int N){
    int len = getLen(head1);
    if(len > N/3){//ά��head1����Ϊ�϶̵���һ��
        int temp = head1;
        head1 = head2;
        head2 = temp;
    }

    head1 = reverse(head1);//��head1����ת

    //�ϲ�����
    int curr, temp;
    curr = Link[head2].next;
    while(head1 != -1){
        temp = head1;
        head1 = Link[head1].next;
        Link[temp].next = Link[curr].next;
        Link[curr].next = temp;
        curr = Link[temp].next;
        curr= Link[curr].next;//curr���������
    }
    return head2;
}

//��ӡ����
void PrintLink(int start){
    while(start != -1){
        printf("%05d ", start);
        printf("%d ", Link[start].val);
        if(Link[start].next == -1){
            printf("-1\n");
        }else{
            printf("%05d\n", Link[start].next);
        }
        start = Link[start].next;
    }
}

int main(void){
    int head1, head2, N;
    scanf("%d %d %d", &head1, &head2, &N);
    Input(N);
    PrintLink(Merge(head1, head2, N));
}


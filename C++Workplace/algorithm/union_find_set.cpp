//
// Created by trudbot on 2022/7/9.
//

#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
using namespace std;
#define N 100
int p[N], w[N];//存放集合中的元素个数

//查找集合编号
int Find(int x)
{
    if(p[x] != x) p[x] = Find(p[x]);
    return p[x];
}

//合并两个元素所在的集合
void merge(int a, int b)
{
    a = Find(a), b = Find(b);
    if(a == b) return;
    p[a] = b;
    w[b] += w[a];
}

//判断两个元素是否在同一个集合中
bool SameSet(int a, int b)
{
    return Find(a) == Find(b);
}

//获取某个集合中的元素个数
int getNum(int item)
{
    return w[item];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}

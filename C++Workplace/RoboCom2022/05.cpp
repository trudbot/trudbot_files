/*
 * RC-u5 树与二分图

 设 G=(V,E) 是一个无向图，如果顶点集合 V 可分割为两个互不相交的子集 (A,B)，并且每条边 (i,j)∈E 的两个端点 i 和 j 分别属于这两个不同的顶点子集，则称图 G 为一个二分图。

现在给定一棵树 T，要求选择树中两个没有边相连的结点 i 和 j，使得将无向边 (i,j) 加进 T 后能够构成二分图。你的任务是计算满足这个要求的选择方案有多少种。

输入格式:
输入第一行给出一个正整数 N (2≤N≤10
6
 )，表示树中结点的个数。

接下来 N−1 行，每行给出树中一条边的两端结点编号，以空格分隔。结点编号从 1 开始。题目保证输入给出的是一棵树中所有的边。

输出格式:
在一行中输出方案数。注意：连接 (1,2) 和 (2,1) 视作同一个方案。

输入样例:
7
1 2
2 3
2 4
2 5
2 6
4 7
输出样例:
4
 */

#include <bits/stdc++.h>

#include <random>
using namespace std;
#define ll long long
const int N = 1e6 + 10;

ll n;
int h[N], e[N], ne[N], idx;

void add(int x, int y)
{
    e[idx] = y, ne[idx] = h[x], h[x] = idx++;
}

bool st[N];
ll m;
void dfs(int v, bool color)
{
    st[v] = true;
    if(color) m++;
    for(int i=h[v]; i!=-1; i=ne[i])
    {
        int j = e[i];
        if(!st[j]) dfs(j, !color);
    }
}

int main()
{
    cin >> n;
    for(int i=1; i<=n; i++) h[i] = -1;
    int x, y;
    for(int i=1; i<n; i++)
    {
        cin >> x >> y;
        add(x, y), add(y, x);
    }
    dfs(1, true);
    cout << m*(n-m) - (n-1);
    return 0;
}

/*
 * RC-u1 不要浪费金币
 哲哲最近在玩一个游戏，击杀怪物能获得金币 —— 这里记击杀第 i 个怪物获得的金币数量为 Pi。

然而这个游戏允许拥有的金币数量是有上限的，当超过时，超过上限的部分就会被系统光明正大地吃掉，哲哲就拿不到了。

为了不浪费金币，哲哲决定，当下一个要击杀的怪物可获得的金币会导致自己拥有的金币数量超过上限时，就去消费一次，把自己已有的金币全部用完。

现在给定哲哲将要击杀的一系列怪物对应的金币数量，请你计算一下哲哲去消费了几次。

输入格式:
 输入第一行是两个整数 N,M （1≤N≤1e3 ,1≤M≤1e6），表示击杀的怪物数量以及系统允许拥有金币数量的上限。

接下来一行是由空格隔开的 N 个数 Pi（i=1,⋯,N），依次表示击杀第 i 个怪物能获得的金币数量。
 假设哲哲是按输入顺序击杀怪物的，并且每个 Pi都是 不超过 1e6的非负整数。

输出格式:
在一行中输出哲哲去消费的次数。

 输入样例:
10 10
1 2 3 4 1 2 3 5 11 1
输出样例:
4
样例解释：
消费时间点为：第四个怪物击杀后、第七个怪物击杀后、第八个怪物击杀后、第九个怪物击杀后。
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
int arr[N];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> arr[i];

    int res = 0;
    int sum = 0;
    for(int i=1; i<=n; i++)
    {
        if(sum + arr[i] > m)
        {
            res++;
            sum = 0;
        }
        sum += arr[i];
    }
    cout << res << endl;
    return 0;
}


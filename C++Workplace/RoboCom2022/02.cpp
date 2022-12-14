/*
 *RC-u2 智能服药助手
 智能看护中很重要的环节是安排需要服药的老年人的服药计划。

已知机器人需要照顾的某位老年人需要服用 N 种药物，但某些药物不宜间隔过短服用 —— 比如降糖药一般遵医嘱日服 3 次，
 两次之间需要间隔至少 4 小时。当需要服用的药物比较多，医嘱比较复杂时，如何保证每位老人的服药计划是安全合理的，就成为一个挑战。

本题给定一套服药计划，请你检查一下计划是否存在问题。

输入格式:
输入第一行给出两个整数 N,M（1≤N,M≤1e3），表示老人需要服用 N 种药物（药物种类从 1 到 N 编号），对应的服药计划有 M 条记录。

接下来首先在一行中给出 N 个用空格隔开的整数 Ti（−1≤Ti ≤100,Ti !=0)，表示编号为 i 的药物需要间隔至少 Ti个单位时间服用。
 如果 Ti为 −1，则说明这种药物没有间隔要求。

接下来的 M 行，每行给出一条服药计划中的记录，格式为：首先给出两个非负整数 t 和 k (0≤t≤1e9,0≤k≤N)，
 表示服药的时刻为 t，服用了 k 种药物；然后紧接着列出 k 个数，每个数对应 t 时刻要吃的药物种类的编号。一行中的数字之间以空格分隔。

题目保证：记录按照服药时刻 t 的递增顺序给出；每一时刻服用的药物种类各不相同。注意：同一种药物可能需要在不同的时刻重复服用。
 如果一位老人在 ti时刻和 tj时刻服用了同一种药物，则他服用的间隔时间为 ∣ti−tj∣。

输出格式:
按照输入顺序检查每一条记录中的每一种药物。如果在 Y 时刻不宜服用药物 X，则在一行中输出：

Don't take X at Y!

注意：老人收到提醒后会按照提醒不服用指定的药物。

输入样例:
10 6
1 2 3 4 5 -1 -1 -1 -1 -1
0 1 1
1 2 1 2
2 1 2
3 2 1 3
5 3 1 3 4
6 2 1 4

输出样例:
Don't take 2 at 2!
Don't take 3 at 5!
Don't take 4 at 6!

 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int tim[N];
map<int, vector<int> > h;

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> tim[i];

    int t, k;
    while (m--)
    {
        cin >> t >> k;
        int i;
        while(k--)
        {
            cin >> i;
            if(h[i].empty() || tim[i] == -1)
            {
                h[i].push_back(t);
                continue;
            }
            int x = h[i].size()-1;
            if(t-h[i][x] >= tim[i])
                h[i].push_back(t);
            else
                printf("Don't take %d at %d!\n", i, t);
        }
    }

}

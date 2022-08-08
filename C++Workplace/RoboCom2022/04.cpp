#include <bits/stdc++.h>

using namespace std;
const int N = 7;
int num[N];//各队伍的人数
bool A[N], B[N], C[N];//各队伍是否有坦克、工兵、指挥
int totalA;//坦克的总数

//目前的最优方案， 1、2 对应 欧文、亚特
vector<int> ans1, ans2;
/* RO, R1, R2对应前三个规则所要求的性质
 * R0: 是否满足 每组必须有至少一个 MT（主坦克）。
 * R1: 是否满足 每组有至少一个指挥和至少一个工兵
 * R2: 是否满足 每组至少有一个指挥
 */
bool R0, R1, R2;


vector<int> tmp1, tmp2;//当前要判断的方案

void judge()
{
    //所有人都在一组， 不符合分组要求， 直接退出
    if(tmp1.empty() || tmp2.empty()) return;

    //当前方案的r0, r1, r2性质， 以及临时变量t1, t2
    bool r0, r1, r2, t1, t2;

    //判断方案的r0性质
    t1 = t2 = false;
    for(int i : tmp1)
        if( A[i] ) {
            t1 = true;
            break;
        }
    for(int i : tmp2)
        if( A[i] ) {
            t2 = true;
            break;
        }
    r0 = t1 && t2;
    if(!r0) return;//r0是硬性要求， 不满足直接不考虑

    //判断方案的r2性质, 先判断r2是因为r2是r1的组成部分
    t1 = t2 = false;
    for(int i : tmp1)
        if( C[i] ) {
            t1 = true;
            break;
        }
    for(int i : tmp2)
        if( C[i] ) {
            t2 = true;
            break;
        }
    r2 = t1 && t2;

    //判断方案的r1性质
    t1 = t2 = false;
    for(int i : tmp1)
        if( B[i] ) {
            t1 = true;
            break;
        }
    for(int i : tmp2)
        if( B[i] ) {
            t2 = true;
            break;
        }
    r1 = r2 && t1 && t2;

    //规则0, R0为false说明最优方案为空
    if( !R0 )
    {
        ans1 = tmp1, ans2 = tmp2;
        R0 = r0, R1 = r1, R2 = r2;
        return;
    }

    //规则1
    if(R1 && !r1) return;
    if(r1 && !R1)
    {
        ans1 = tmp1, ans2 = tmp2;
        R0 = r0, R1 = r1, R2 = r2;
        return;
    }

    //都不满足规则1时执行规则2
    if(!R1 && !r1)
    {
        if(R2 && !r2) return;
        if(r2 && !R2)
        {
            ans1 = tmp1, ans2 = tmp2;
            R0 = r0, R1 = r1, R2 = r2;
            return;
        }
    }

    //规则3
    int an1 = 0, an2 = 0, tn1 = 0, tn2 = 0;//各组人数
    for(int i : ans1) an1 += num[i];
    for(int i : ans2) an2 += num[i];
    for(int i : tmp1) tn1 += num[i];
    for(int i : tmp2) tn2 += num[i];

    int d1 = abs(an1 - an2), d2 = abs(tn1 - tn2);//人数差
    if(d1 < d2) return;
    if(d1 > d2)
    {
        ans1 = tmp1, ans2 = tmp2;
        R0 = r0, R1 = r1, R2 = r2;
        return;
    }

    //规则四
    t1 = (an1 > an2), t2 = (tn1 > tn2);
    if(t1 && !t2) return;
    if(t2 && !t1)
    {
        ans1 = tmp1, ans2 = tmp2;
        R0 = r0, R1 = r1, R2 = r2;
        return;
    }

    //规则5
    for(int k=0; k<ans1.size() && k < tmp1.size(); k++)
    {
        if(ans1[k] < tmp1[k]) return;
        else if(ans1[k] > tmp1[k])
        {
            ans1 = tmp1, ans2 = tmp2;
            R0 = r0, R1 = r1, R2 = r2;
            return;
        }
    }
    /*
     可以发现虽然代码长, 但其实都差不多
     基本就是:
        如果最优方案满足某个规则而当前方案不满足, 判断结束
        如果最优方案不满足某个规则而当前方案满足, 则当前方案替换最优方案, 判断介绍
        如果都满足, 执行下一个规则
     */
}

void dfs(int i)
{
    if(i > 6)
    {
        judge();
        return;
    }
    if(num[i] == 0)
    {
        dfs(i+1);
        return;
    }
    tmp1.push_back(i);
    dfs(i+1);
    tmp1.pop_back();

    tmp2.push_back(i);
    dfs(i+1);
    tmp2.pop_back();
}

int main()
{
    for(int i=1; i<=6; i++)
        cin >> num[i];
    string ABC;
    for(int i=1; i<=6; i++)
    {
        cin >> ABC;
        if(ABC[0] == '1') A[i] = true, totalA++;
        if(ABC[1] == '1') B[i] = true;
        if(ABC[2] == '1') C[i] = true;
    }
    if(totalA < 2)//出现GG的情况有且仅有少于两个队伍有坦克
    {
        cout << "GG";
        return 0;
    }
    else
    {
        dfs(1);
        for(int i=0; i<ans1.size(); i++)
        {
            if(i != 0) cout << " ";
            cout << ans1[i];
        }
        cout << endl;
        for(int i=0; i<ans2.size(); i++)
        {
            if(i != 0) cout << " ";
            cout << ans2[i];
        }
    }
    return 0;
}

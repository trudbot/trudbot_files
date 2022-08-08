//
// Created by trudbot on 2022/6/23.
//

#include <bits/stdc++.h>
using namespace std;
#define MaxN 1010

int rooms[MaxN][MaxN];//记录房间的编号以及位置
int visited[MaxN][MaxN];//用于记录该位置房间MaxStep是否已经确定
int MaxSteps[MaxN][MaxN];//记录最大可到达房间数
int s;
map<int, pair<int, int>> pos;//记录对应编号房间到其位置的映射


void CountMaxSteps(int row, int col)
{
    if(visited[row][col])
        return;

    visited[row][col] = true;

    if(row > 1)//如果上边有房间
    {
        if(rooms[row-1][col] == rooms[row][col]+1)
        {
            CountMaxSteps(row-1, col);
            MaxSteps[row][col] += MaxSteps[row-1][col];
        }
    }

    if(col > 1)//如果左边有房间
    {
        if(rooms[row][col-1] == rooms[row][col]+1)
        {
            CountMaxSteps(row, col-1);
            MaxSteps[row][col] += MaxSteps[row][col-1];
        }
    }

    if(row < s)//如果下面有房间
    {
        if(rooms[row+1][col] == rooms[row][col]+1)
        {
            CountMaxSteps(row+1, col);
            MaxSteps[row][col] += MaxSteps[row+1][col];
        }
    }

    if(col < s)//如果右边有房间
    {
        if(rooms[row][col+1] == rooms[row][col]+1)
        {
            CountMaxSteps(row, col+1);
            MaxSteps[row][col] += MaxSteps[row][col+1];
        }
    }

}

int main() {

    int T;
    cin >> T;

    for(int i=1; i<=T; i++)
    {
        cin >> s;
        //一系列数据输入及初始化
        for(int j=1; j<=s; j++)
            for(int k=1; k<=s; k++)
            {
                cin >> rooms[j][k];
                pos[rooms[j][k]] = {j, k};
                visited[j][k] = false;
                MaxSteps[j][k] = 1;
            }

        //编号较小的房间更有可能到达尽可能多的房间， 当然这里也可以直接遍历， 就不需要用哈希表了
        for(int j=1; j<=s; j++)
            for(int k=1; k<=s; k++)
            {
                if(!visited[j][k])
                    CountMaxSteps(j, k);
            }

        //找出最大的房间
        int res = 1;
        for(int j=2; j<=s*s; j++)
        {
            if(MaxSteps[pos[j].first][pos[j].second] > MaxSteps[pos[res].first][pos[res].second])
                res = j;
        }

        cout << "Case #" << i << ": " << res << " " << MaxSteps[pos[res].first][pos[res].second] << endl;
    }


    return 0;
}

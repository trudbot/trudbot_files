//
// Created by trudbot on 2022/6/20.
//
/*
峰会是国家元首或政府首脑的会议。

为峰会安排休息区可不是一件简单的工作。

一共有 N 个首脑参加峰会，编号 1∼N。

这些首脑之间存在 M 对两两之间的直接朋友关系。

在划分区域时，我们希望被安排在同一休息区域的首脑们满足，任意两人之间都是直接朋友关系。

现在，给定 K 个关于划分休息区域的安排，请你依次判断每个安排是否合理。

输入格式
第一行包含两个整数 N 和 M。

接下来 M 行，每行包含两个整数 a,b，表示首脑 a 和首脑 b 之间存在直接朋友关系。

再一行包含整数 K。

接下来 K 行，每行描述一个区域安排，首先包含一个整数 L，表示该安排打算将 L 个首脑安排在同一区域休息，然后包含 L 个整数，表示这些首脑的编号。

输出格式
共 K 行，第 i 行输出对第 i 个安排的判断，具体格式为

如果安排满足其中的任意两人之间都是直接朋友关系并且不存在额外的人与被安排的所有人都是直接朋友关系（即无法安排更多的人在这一区域休息），则输出 Area X is OK.
如果安排满足其中的任意两人之间都是直接朋友关系并且存在额外的人与被安排的所有人都是直接朋友关系（即可以安排更多的人在这一区域休息），则输出 Area X may invite more people, such as H.，其中 H 是额外可被安排的人的编号（如果不唯一，则输出最小的那个）。
如果安排无法满足其中的任意两人之间都是直接朋友关系，则输出 Area X needs help.。
X 表示组别编号，从 1 到 K。

数据范围
1≤N≤200,
1≤M≤N(N−1)/2,
1≤a,b≤N,
a≠b,
1≤K≤100,
1≤L≤N,
同一对直接朋友关系不会在输入中重复出现。

输入样例：
8 10
5 6
7 8
6 4
3 6
4 5
2 3
8 2
2 7
5 3
3 4
6
4 5 4 3 6
3 2 8 7
2 2 3
1 1
2 4 6
3 3 2 1
输出样例：
Area 1 is OK.
Area 2 is OK.
Area 3 is OK.
Area 4 is OK.
Area 5 may invite more people, such as 3.
Area 6 needs help.

 */


#include <bits/stdc++.h>
#define MaxNum 200
using namespace std;

bool IsFriends[MaxNum+1][MaxNum+1];

void JudgeArea(const vector<int>& area, int N){
    for(int i=0; i<area.size()-1; i++){
        for(int j=i+1; j<area.size(); j++){
            if(!IsFriends[area[i]][area[j]]){
                cout<< "needs help."<< endl;
                return;
            }
        }
    }

    for(int i=1; i<=N; i++){
        int j;
        for(j=0; j<area.size(); j++){
            if(!IsFriends[i][area[j]]){
                break;
            }
        }
        if(j == area.size()){
            cout<< "may invite more people, such as "<<i<<".\n";
            return;
        }
    }

    cout << "is OK."<<endl;
}

int main() {
    int N, M;
    int a, b;
    cin >> N >> M;
    while(M--){
        cin>> a>>b;
        IsFriends[a][b] = IsFriends[b][a] = true;
    }

    int K, L, temp;
    cin>> K;
    vector<int> area;
    for(int i=1; i<=K; i++)
    {
        area.clear();
        cin>> L;
        while(L--){
            cin>> temp;
            area.push_back(temp);
        }
        cout << "Area " << i <<" ";
        JudgeArea(area, N);
    }
    return 0;
}

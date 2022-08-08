//
// Created by trudbot on 2022/6/23.
//

#include <bits/stdc++.h>
#define MaxN 1001

using namespace std;
int N, K;

//有向图矩阵， CallTime[a][b]表示a 给 b 打电话的总时长
int CallTime[MaxN][MaxN];
int team[MaxN];
int teamNum = 1;
//判断n是否为嫌疑人
inline bool IsSuspect(int n){
    int outNum = 0, inNum = 0;
    for(int i=1; i<=N; i++){
        if(CallTime[n][i] && CallTime[n][i] <= 5){
            outNum++;
            if(CallTime[i][n])
                inNum++;
        }
    }
    if(outNum <= K || outNum < inNum*5)
        return false;
    return true;
}


int main() {
    int M;
    cin >> K >> N >> M;
    int a, b, time;

    while(M--){
        cin >> a >> b >> time;
        CallTime[a][b] += time;
    }
    vector<int> suspect;
    for(int i=1; i<=N; i++){
        if(IsSuspect(i)){
            suspect.push_back(i);
        }
    }
    if(suspect.empty()){
        cout << "None" << endl;
        return 0;
    }
    int temp;

    for(int i : suspect){
        if(team[i] == 0){
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                temp = q.front();
                q.pop();
                if(team[temp] != 0) continue;
                team[temp] = teamNum;
                for(int j : suspect){
                    if(team[j] == 0 && CallTime[temp][j] && CallTime[j][temp])
                        q.push(j);
                }
            }
            teamNum++;
        }
    }

    for(int i=1; i<teamNum; i++){
        for(int j=1; j<=N; j++)
            if(team[j] == i)
                cout << j << " ";
        cout << endl;
    }

    return 0;
}

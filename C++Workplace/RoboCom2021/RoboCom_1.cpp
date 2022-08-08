//
// Created by trudbot on 2022/6/20.
//
/*
众所周知，在互联网上有很多话是不好直接说出来的，不过一些模糊的图片仍然能让网友看懂你在说什么。然而对这种言论依然一定要出重拳，所以请你实现一个简单的匹配算法。

现在我们采集了原图的一些特征数据，由 N 个小于 255 的非负整数组成，假设对于给定的若干张由 Mi个同样小于 255 的非负整数组成的新图的特征数据，
每个数据都可以由原图中任意四个不同数据的平均值计算而来，则称新图为原图的相似图片。对于给出的数据，请你判断是不是相似图片。

注意，不同数据指的并非是数据的值不同，而是不能取同一个数据多次。对于两个相同值的数据，如果给出两次，则可以取两次。

输入格式:
输入第一行是两个整数 N,K (1 ≤ N ≤ 50, 1 ≤ K ≤ 200)，表示采集的原图的特征数据个数和新图的张数。

接下来一行为 N 个小于 255 的非负整数，表示原图的特征数据。

最后的 K 行，每行第一个数是 Mi (1 ≤ Mi ≤ 200)，表示新图的特征数据个数。然后是 Mi个小于 255 的非负整数，表示新图的特征数据。

输出格式:
对于每一张新图，如果为相似图片，则在一行中输出 Yes，否则输出 No。

输入样例:
5 3
4 8 12 20 40
3 11 16 19
3 12 16 19
10 11 11 11 11 11 11 11 11 11 11

输出样例:
Yes
No
Yes
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K;
    cin>> N >> K;
    int data[N];
    vector<vector<int>> graphs;
    int len, temp;
    for(int i=0; i<N; i++){
        cin >> data[i];
    }

    graphs.resize(K);
    for(int i=0; i<K; i++){
        cin>> len;
        while(len--){
            cin>> temp;
            graphs[i].push_back(temp);
        }
    }

    unordered_map<int, bool> hash;
    int i, j, k, m;
    for(i=0; i<N-3; i++)
        for(j=i+1; j<N-2; j++)
            for(k=j+1; k<N-1; k++)
                for(m=k+1; m<N; m++){
                    hash[data[i]+data[j]+data[k]+data[m]] = true;
                }

    for(i=0; i<K; i++){
        for(j=0; j<graphs[i].size(); j++){
            if(hash.count(4*graphs[i][j]) == 0){
                break;
            }
        }
        if(j == graphs[i].size()){
            cout<< "Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}

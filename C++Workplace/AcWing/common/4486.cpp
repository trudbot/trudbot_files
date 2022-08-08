//
// Created by trudbot on 2022/6/25.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> pfs;
    int p = 2;
    while(p <= N)
    {
        if(N%p == 0)
        {
            pfs.push_back(p);
            N /= p;
        }
        else
            p++;
    }

    map<int, int> hash;
    for(auto i : pfs)
    {
        if(hash.count(i) == 0)
            hash[i] = 1;
        else
            hash[i] += 1;
    }

    int min = 1;
    int max = 0;
    int flag = false;
    for(auto & i : hash){
        min *= i.first;
        if(i.second > max)
            max = i.second;
    }

    int count = 0;
    for(auto & i : hash){
        if(i.second != max){
            flag = true;
            break;
        }
    }
    if(max == 1){
        count == 0;
    }
    else{
        if(max % 2 == 1)
            max++;
        while(max != 1){
            max /= 2;
            count++;
        }
        count++;
    }
    cout << min << " " << count;
    return 0;
}

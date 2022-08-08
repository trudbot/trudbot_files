//
// Created by trudbot on 2022/6/26.
//

#include <bits/stdc++.h>

using namespace std;
unordered_map<string, string> nextCity;
unordered_map<string, bool> selected;

int main() {
    int T, N;
    cin >> T;
    string s1, s2;
    for(int i=1; i<=T; i++)
    {
        cin>> N;
        getchar();
        for(int j=0; j<N; j++)
        {
            getline(cin, s1);
            getline(cin, s2);
            nextCity[s1] = s2;
            selected[s2] = true;
        }

        string curr;
        for(auto &city : nextCity)
        {
            if(selected.count(city.first) == 0)
            {
                curr = city.first;
                break;
            }
        }

        printf("Case #%d:", i);
        while(nextCity.count(curr) != 0)
        {
            cout << " " << curr << "-" << nextCity[curr];
            curr = nextCity[curr];
        }
        printf("\n");
        nextCity.clear();
        selected.clear();
    }
    return 0;
}


//
// Created by trudbot on 2022/7/19.
//

#include <bits/stdc++.h>

#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    string code = "V W X Y Z A B C D E F G H I J K L M N O P Q R S T U";
    getline(cin, str);
    while(str != "ENDOFINPUT")
    {
        getline(cin, str);
        for(char & i : str)
            if(i <= 'Z' && i >= 'A')
                i = code[(i-'A') * 2];
        cout << str << endl;
        getline(cin, str);
        getline(cin, str);
    }
    return 0;
}
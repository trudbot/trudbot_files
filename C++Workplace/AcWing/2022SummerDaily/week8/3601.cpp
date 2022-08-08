
//
// Created by trudbot on 2022/7/24.
//

#include <bits/stdc++.h>
using namespace std;

struct student {
    int score, age;
    string name;

    bool operator < (const student &stu) const {
        if(score != stu.score) return score < stu.score;
        if(name != stu.name) return name < stu.name;
        return age < stu.age;
    }
};

int main() {
    int n; cin >> n;
    vector<student> data(n);
    for(int i=0; i<n; i++)
        cin >> data[i].name >> data[i].age >> data[i].score;
    sort(data.begin(), data.end());
    for(auto &s : data)
        cout << s.name << " " << s.age << " " << s.score << endl;
    return 0;
}
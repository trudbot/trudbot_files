
//
// Created by trudbot on 2022/7/12.
//

#include <bits/stdc++.h>
using namespace std;
map<int, int> num;//存储每种骰子被掷的总数
int Max, Min;//点数的最大最小值

void Solution(string str)
{
    //l指向当前要处理指令的第一个字符， sign为当前指令的正负号， 1为正， -1为负
    int r = str.length()-1, l = 0, sign = 1;

    while(l <= r)
    {
        int x = 0, y = 0;

        //读取x
        while(l<=r && str[l] != 'd' && str[l] != '+' && str[l] != '-')
            x = x*10 + str[l++] - '0';

        //停止在d字符， 说明是一个指令
        if(str[l] == 'd')
        {
            if(x == 0) x = 1;//d前面没有字符时， x默认为1
            l++;
            //读取y
            while(l<=r && str[l] != '+' && str[l] != '-')
                y = y*10 + str[l++] - '0';
            num[y] += x;//y面骰子的掷数增加x
            if(sign == 1)
            {
                //为正时， Max加上最大数， Min加上最小数
                Max += y*x;//每次都掷y点
                Min += x;//每次都掷1点
            }
            else//为负时， 同上
            {
                Max -= x;
                Min -= y*x;
            }
        }
        else//停止在+/-或越界， 说明是一个常量， 乘上符号直接加到Max, Min里即可
        {
            Max += sign*x;
            Min += sign*x;
        }

        if(l <= r)
            sign = str[l++] == '+' ? 1 : -1;//判断下一个操作对象的符号， l后移指向它的第一个字符
    }
}


int main() {
    string str;
    cin >> str;
    Solution(str);

    for(auto i : num)
    {
        cout << i.first << " " << i.second << endl;
    }
    cout << Min << " " << Max << endl;

    return 0;
}
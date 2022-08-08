//
// Created by trudbot on 2022/6/29.
//
//unique是一个对有序序列去重的函数

#include <bits/stdc++.h>

#define ll long long
using namespace std;

//双指针法实现unique， 返回值为去重后序列的长度
int MyUnique(int arr[], int len)
{
    int j = 0, i;
    for(i = 1; i<len; i++)
    {
        if(arr[i] != arr[j])
            arr[++j] = arr[i];
    }
    return j+1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int arr[] = {2, 2, 3, 8, 8};
    int newLen = MyUnique(arr, 5);
    cout << newLen << endl;

    for(int i=0; i<newLen; i++)
        cout << arr[i] << " ";

    return 0;
}

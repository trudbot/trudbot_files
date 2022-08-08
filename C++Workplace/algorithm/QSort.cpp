//
// Created by trudbot on 2022/6/28.
//快排记忆版

#include <bits/stdc++.h>

using namespace std;

void QSort(int arr[], int l, int r)
{
    if(l >= r)
        return;
    int i = l-1, j = r+1, p = arr[(l+r)>>1];
    while(i < j)
    {
        do i++; while(arr[i] < p);
        do j--; while(arr[j] > p);
        if(i < j) swap(arr[i], arr[j]);
    }
    QSort(arr, l, j), QSort(arr, j+1, r);
}

int main() {
    int arr[] = {3, 8, 3, 2, 4};
    QSort(arr, 0, 4);
    for(int I : arr)
        cout << I << " ";
    return 0;
}

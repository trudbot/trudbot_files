//
// Created by trudbot on 2022/6/23.
//

#include <bits/stdc++.h>

using namespace std;
int arr[201];

int main() {
    int n, N;
    cin >> n >> N;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    int sum = 0;
    int min = N;
    for(int i=n; i>=0; i--){
        if(arr[i] < min){
            sum += (min - arr[i]) * i;
            min = arr[i];
        }
    }
    cout << sum << endl;
    return 0;
}

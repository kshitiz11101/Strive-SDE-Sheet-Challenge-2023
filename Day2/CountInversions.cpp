#include <bits/stdc++.h> 
long long getInversions(long long *arr, int n){
    // Write your code her
    long long count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i<j && arr[i]>arr[j]){
                count++;
            }
        }

    }
    return count;
}

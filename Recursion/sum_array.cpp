#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findSum(int *arr, int size){
    
    //base case
    if(size==0){
        return 0;
    }
    if(size==1){
        return arr[0];
    }
    else{
        return arr[0] + findSum(arr+1, size-1);
    }
}

int main(){
    int arr[6] = {2,5,6,7,4,9};
    int n = 6;
    cout<<findSum(arr,n)<<endl;
    return 0;
}
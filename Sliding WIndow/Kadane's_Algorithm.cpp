//Largest sum continous subarray
#include<iostream>
using namespace std;

int LargestsumSubarray(int arr[], int n){
    int maxsofar = arr[0]; int currmax = arr[0];
    for(int i = 0;i< n;i++){
        currmax = max(arr[i], currmax+arr[i]);
        maxsofar = max(maxsofar, currmax);
    }
    return maxsofar;
    
}

int main(){
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -7};
    int n = 8;
    int ans = LargestsumSubarray(arr,n);
    cout<< ans;
}
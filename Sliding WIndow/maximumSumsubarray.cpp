//Q Maximum sum subarray of size k

/*
// Introductory Sliding window
*/

#include<iostream>
using namespace std;
#include<vector>
#include <climits>

int findSubarray(vector<int> &arr, int k){
    int i = 0, j = 0;
    int sum = 0;
    int maxsofar = 0;//INT_MIN;
    while(j<arr.size()){
        sum = sum + arr[j];
        if(j-i+1<k){
            j++;
        }
        if(j-i+1 == k){
        maxsofar = max(sum, maxsofar);
        sum = sum - arr[i];
        i++;
        j++;
        }
    }
    return maxsofar;
}

int main(){
    vector<int> arr = {2,3,4,5,2,7,6,8};
    int k = 3;
    cout<<findSubarray(arr, k);
}
//9 12 11 14 15 21
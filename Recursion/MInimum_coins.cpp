#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int minimumcoins(int n, int ){
    if(n <=0){
        return -1;
    }
    if(n == 1||n==2||n==5){
        return 1;
    }
    int ans = min(INT_MAX, minimumcoins(n-1, 1) + minimumcoins(n-2,2) + minimumcoins(n-5, 5)); 
    return ans;
}

int main(){
    int n;
    cout<<"Enter AMount: ";
    cin>>n;
    int arr[3]= {1,2,5};
    int ans = minimumcoins(n, 0);
    cout<<ans;
}
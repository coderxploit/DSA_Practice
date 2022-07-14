#include<iostream>
using namespace std;

bool search(int *arr, int size, int k){
    if(size==0) 
        return false;
    if(arr[0]==k){
        return true;
    }
    else return search(arr+1, size-1, k);
}

int main(){
    int arr[5]= {5,4,6,8,9};
    int size = 5;
    int k = 7;
    cout<<search(arr,size, k);
    return 0;
}
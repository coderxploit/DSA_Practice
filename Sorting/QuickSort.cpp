#include<iostream>
using namespace std;
#include <vector>

int Partition(vector<int> &arr, int s, int e);

void quickSort(vector<int> &arr, int s, int e){

    //basecase
    if(s>=e){
        return;
    }

    //partition
    int p = Partition(arr, s, e);

    //Recursive call
    quickSort(arr, s, p-1);
    quickSort(arr, p+1, e);
}

int Partition(vector<int> &arr, int s, int e){
    //choose a pivot

    int pivot = arr[s];
    int count = 0;
    for(int i = s+1;i<=e;i++){
        if(arr[i]<= pivot){
            count++;
        }
    }
    //place pivot at right position
    int pivotIndex = s + count;
    swap(arr[pivotIndex], arr[s]);

    //arrange left right part 

    int i = s, j = e;
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<pivot){
            i++;
        }

        while(arr[j]>pivot){
            j--;
        }

        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;

}

int main(){
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(1);
    arr.push_back(6);
    arr.push_back(9);

    quickSort(arr, 0, 4);

    for(auto x: arr){
        cout<<x<<endl;
    }
}
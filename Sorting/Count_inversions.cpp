// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int merge(long long arr[],long long l,long long mid,long long r){
       long long int i=l;
       long long int j=mid+1;
       long long int k=l;
       long long int B[r+1];
       long long int count=0;
        
        while(i<=mid && j<=r){
            if(arr[i]>arr[j]){
                count+=mid-i+1; //extra line added in merge sort
                B[k++]=arr[j++];
                
            }
            else B[k++]=arr[i++];
        }
        
        while(i<=mid){
            B[k++]=arr[i++];
        }
        while(j<=r){
            B[k++]=arr[j++];
        }
        
        for(int k=l;k<=r;k++){
            arr[k]=B[k];
        }
        return count;
        
    }
    long long int merge_sort(long long arr[],long long l,long long r){
        if(l>=r){
            return 0;
        }
        long long mid=(l+r)/2;
        long long int x=merge_sort(arr,l,mid);
        long long int y=merge_sort(arr,mid+1,r);
        long long int z=merge(arr,l,mid,r);
        return x+y+z;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        return merge_sort(arr,0,N-1);
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends
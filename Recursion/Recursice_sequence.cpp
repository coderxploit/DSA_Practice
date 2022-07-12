// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    
    long long sequence(int N){
              if(N==1)
           return 1;
       long long c=N*(N-1)/2+1;
       long long prod=1;
       
       for(int i=1; i<=N; i++)
       {
           prod*=c;
           c++;
       }
       return prod+sequence(N-1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}  // } Driver Code Ends
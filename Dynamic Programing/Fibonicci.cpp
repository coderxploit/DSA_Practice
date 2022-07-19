//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  //Space optimization
  long long int nthFibonacci(long long int n){
        long long int mod = 1e9+7;
        long long int prev1 = 0;
        long long int prev2 = 1;
        long long int curr;
        for(int i = 2;i<=n;i++){
            curr = prev1+ prev2;
        
            prev1 = prev2;
            prev2 = curr;
        }
        return prev2;
  }
  /*
  //tabulation method
    long long int nthFibonacci(long long int n){
        long long int mod=1e9+7;
       vector<int>dp(n+1);
       dp[0]=0;
       dp[1]=1;
       for(int i=2;i<n+1;i++){
           dp[i]=(dp[i-1]+dp[i-2])%mod;
       }
       return dp[n];
       
   }*/
   /*
   //Mamoization method:
    long long int f(int n, vector<long long int> &dp){
        //base case 
        if(n <= 1){
            return n;
        }
        //check memory 
        if(dp[n] != -1){
            return dp[n];
        }
        
        dp[n] = (f(n-1, dp) + f(n-2, dp))%1000000007;
    }
    
    long long int nthFibonacci(long long int n){
       vector<long long int> dp(n+1);
       for(int i = 0; i <= n; i++){
           dp[i] = -1;
       }
       return f(n, dp);
    }
};

*/

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends
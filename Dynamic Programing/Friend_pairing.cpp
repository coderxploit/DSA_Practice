//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:

    //recursion
    
    int countFriendsPairings1(int n) 
    { 
        
        //base case 
        if (n == 1){
            return 1;

        }
        if(n == 2){
            return 2;
        }
        //Recursive relation
        return countFriendsPairings1(n-1)+(n-1)*countFriendsPairings1(n-2);
        
    }

    //memoizaion
    int cfp(int n, vector<int> &dp){
        if(n == 1)
            return 1;
        if(n == 2)
            return 2;
        if(dp[n]!=-1)
            return dp[n];
        
        return dp[n] = (cfp(n-1, dp) + (n-1)*cfp(n-2, dp));
    }

    int countFriendsPairings2(int n){
        vector<int>dp(n+1, -1);
        return cfp(n, dp);
    }

    //space-optimized
    int m = 1e9+7;
    long long int fun(int n){
        if(n==1) return 1;
        if(n==2) return 2;
        
        long long int a = 1,b = 2,c; 
        
        for(int i = 3;i<=n;i++){
            c = (b + a*(i-1))%m;
            a = b;
            b = c;
        }
        return b;
    }
    int countFriendsPairings(int n) 
    { 
        // code here
        return fun(n)%m;
    }


    
};    
 

//{ Driver Code Starts.
int main() 
{
    int t;
    cin>>t; 
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	//cout <<ob.countFriendsPairings1(n); 
        cout<< ob.countFriendsPairings2(n);
    	cout<<endl;
    }
} 

// } Driver Code Ends
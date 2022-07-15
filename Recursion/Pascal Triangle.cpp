// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

 // } Driver Code Ends
// #define ll long long
class Solution{
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
        vector<ll> ans;
        ans.push_back(1);
        if(n == 1){
            return ans;
        }
        vector<ll> prev = nthRowOfPascalTriangle(n-1);
        
        for(int i =1; i<prev.size();i++){
            ll curr = prev[i-1]%1000000007+prev[i]%1000000007;
            ans.push_back(curr%1000000007);
        }
        ans.push_back(1);
        return ans;
    }
};


// { Driver Code Starts.


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}
  // } Driver Code Ends
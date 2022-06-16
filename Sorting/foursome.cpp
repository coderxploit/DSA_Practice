// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>>sv;
        for(int i=0;i<n;i++){
            
            for(int j=i+1;j<n;j++){
                
                for(int k=j+1;k<n;k++){
                    
                    int chk=target-(nums[i]+nums[j]+nums[k]);
                    
                    if(binary_search(nums.begin()+k+1,nums.end(),chk)){
                        
                        vector<int>v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[k]);
                        v.push_back(chk);
                        
                        
                        sort(v.begin(),v.end());
                        sv.insert(v);
                    }
                }
            }
        }
        vector<vector<int>>ans(sv.begin(),sv.end());
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends
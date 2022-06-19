// { Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
    

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int arr[], int n){
       vector<int>v1;
       v1.push_back(arr[n-1]);
       int leader=arr[n-1];
       
       for(int i=n-2;i>=0;i--){
           if(arr[i]>=leader){
               leader=arr[i];
               v1.push_back(leader);
           }
           
       }
       // sort(v1.begin(),v1.end(),greater<int>());
       reverse(v1.begin(),v1.end());
       
       return v1;
        
    }
};

// { Driver Code Starts.

int main()
{
   long long t;
   cin >> t;//testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array
        
        int a[n];
        
        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        //calling leaders() function
        vector<int> v = obj.leaders(a, n);
        
        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}
  // } Driver Code Ends
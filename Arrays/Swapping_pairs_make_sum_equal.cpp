// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:

    //Brute Force Approach
	//**************************************************************
    /*
    int findSwapValues(int A[], int n, int B[], int m)
	{
	    int sumA = 0, sumB = 0;
        for(int i = 0;i<n;i++){
            sumA += A[i];
        }
        for(int i = 0;i<m;i++){
            sumB += B[i];
        }
        int maxsum = max(sumA,sumB);
        int diff = abs(sumA - sumB);
        if(diff>=0){
            if(maxsum == sumA){
                for(int i = 0;i<n;i++){
                    for(int j = 0;i<m;j++){
                        if(diff-A[i]==B[j])
                        {
                            return 1;
                            break;
                        }
                    }
                }
            }
            else if(maxsum == sumB){
                for(int i = 0;i<m;i++){
                    for(int j = 0;i<n;j++){
                        if(diff-B[i]==A[j])
                        {
                            return 1;
                            break;
                        }
                    }
                }
            }
        }
        return -1;
	}
 

};
//*****************************************************************/

    int findSwapValues(int A[], int n, int B[], int m)
	{
        
    }
// { Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        

        Solution ob;
        cout <<  ob.findSwapValues(a, n, b, m);
	    cout << "\n";
	     
    }
    return 0;
}





  // } Driver Code Ends
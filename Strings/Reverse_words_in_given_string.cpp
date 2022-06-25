// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        string s1 = "",s2 = "";
        for(int i=0;i<S.size();i++)
        {
             if(S[i]=='.')
            {
                 s1 = "."+s2+s1;s2 ="";
            }
            else s2+=S[i];
        }
        return s2+s1; 
    } 
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends
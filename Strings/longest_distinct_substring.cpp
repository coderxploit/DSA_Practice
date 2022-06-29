// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int longestSubstrDistinctChars (string S)
{
    int a=0;
    for(int i=0;i<S.length();i++)
    {
        unordered_map<char,int> m;
        int j=i;
        int sum=0;
        while(j<S.length())
        {
            if(m[S[j]]>0) break;
            m[S[j]]++;
            sum++;
             j++;
        }

        if(sum>a) a=sum;
    }

    return a;
}